/*
 * ******************************************************************************
 * This program is part of the source code provided with "Linux Device Drivers"
 * Course offered by Techveda <www.techveda.org>
 *
 * (C) 2020 Raghu Bharadwaj/Techveda
 *
 * Git repository:
 *   https://gitlab.com/techveda/ldd
 * ******************************************************************************
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "rtc.h"

int main(void)
{

	int fd;
	struct rtc_time time;

	fd = open("/dev/myrtc", O_RDWR);
	if (fd < 0) {
		perror("open call");
		return -1;
	}

	read(fd, &time, sizeof(struct rtc_time));
	
	printf("sec : %x\n", time.sec);
	printf("min : %x\n", time.min);
	printf("hour: %x\n", time.hour);
	printf("day : %x\n", time.day);
	printf("mon : %x\n", time.mon);
	printf("year: %x\n", time.year);

	close(fd);
	return 0;
}


