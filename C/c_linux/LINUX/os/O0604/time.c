#include <time.h>
#include <pthread.h>
#include <stdio.h>
/* for ETIMEDOUT */
#include <errno.h>
#include <string.h>

pthread_mutex_t calculating = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t done = PTHREAD_COND_INITIALIZER;

void *expensive_call(void *data)
{
        int oldtype,cnt=0;

        /* allow the thread to be killed at any time */
        pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, &oldtype);

        /* ... calculations and expensive io here, for example:
         * infinitely loop
         */
//        for (;;) {}
	while(1)
	{	cnt++;
		if(cnt==5)
		{        pthread_cond_signal(&cnt);
			return (int)cnt;
		}
	}
        /* wake up the caller if we've completed in time */
        pthread_cond_signal(&done);
        return NULL;
}
int do_or_timeout(struct timespec *max_wait)
{
        struct timespec abs_time;
        pthread_t tid;
        int err;

        pthread_mutex_lock(&calculating);

        /* pthread cond_timedwait expects an absolute time to wait until */
        clock_gettime(CLOCK_REALTIME, &abs_time);
        abs_time.tv_sec += max_wait->tv_sec;
        abs_time.tv_nsec += max_wait->tv_nsec;

        pthread_create(&tid, NULL, expensive_call, NULL);

        /* pthread_cond_timedwait can return spuriously: this should
         * be in a loop for production code
         */
        err = pthread_cond_timedwait(&done, &calculating, &abs_time);

        if (err == ETIMEDOUT)
                fprintf(stderr, "%s: calculation timed out\n", __func__);

        if (!err)
                pthread_mutex_unlock(&calculating);
	printf("%d\n",err);
        return err;
}

int main()
{
        struct timespec max_wait;

        memset(&max_wait, 0, sizeof(max_wait));

        /* wait at most 2 seconds */
        max_wait.tv_sec = 10;
        do_or_timeout(&max_wait);

        return 0;
}
