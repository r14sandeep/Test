#include"header.h"
typedef struct messenger
{
	char name[20],phone[11],passwrd[11];

}MESG;
int cnt=0;
void signup()
{
	MESG *msg,*number_check;	
	FILE *fp;
	int index;
	msg=calloc(1,sizeof(MESG));
	name:
	printf("enter your name:");
	scanf("%s",(msg)->name);
	for(index=0;(msg)->name[index];index++)
		if((((msg)->name[index]>'a')&&((msg)->phone[index]<'z'))||(((msg)->name[index]>'A')&&((msg)->phone[index]<'Z')));
		else
		{
			printf("name should only contain alphabets\n");
			goto name;
		}			
	number:
	printf("enter your mobile num:");
	scanf("%s",(msg)->phone);
	for(index=0;(msg)->phone[index];index++)
		if(((msg)->phone[index]>57)||((msg)->phone[index]<48))
		{
			puts("invalid number");
			goto number;
		}
	
	if(number_verify((msg)->phone))
	{
		puts("number is already exist,please enter another number");
		goto number;
	}
	else
	{
		password:
		printf("enter your password:");
		getchar();
		scanf("%s",(msg)->passwrd);
		if(passwrd_validation((msg)->passwrd))
		{
			puts("passwrd must contain 8 to 10 characters and minimum 1 Cap,1 Small,1 Number,1 special char");	
			goto password;
		}
		else
		{
			fp=fopen("file.txt","a");
			fwrite(msg,sizeof(MESG),1,fp);
//			cnt++;
			fclose(fp);
		}
	}
}
void signin()
{
	MESG *buff;	
	FILE *fp;
	int size;
	char ph[11],pw[10];
	fp=fopen("file.txt","r");
	printf("enter your num:");
	scanf("%s",ph);

	if(!number_verify(ph))
		puts("number doesn't exist,first create account");
	else
	{
		printf("enter password:");
		scanf("%s",pw);
		if(!passwrd_verify(pw))
			puts("wrong password");
		else
		{
			int flag=0;
			if(mkfifo("fifo1",0660)==-1)
				perror("mkfifio");
			if(mkfifo("fifo2",0660)==-1)
				perror("mkfifio");
			int fd1,fd2;
			fd1=open("fifo1",O_RDWR);
			fd2=open("fifo2",O_RDWR);
			char rdbuff[100],wrbuff[100];
			int pid;
			while(1)
			{
//				pid=fork();
//				if(pid)
//				{
					puts("waiting for client:");
					read(fd1,rdbuff,100);
					printf("from client:%s\n",rdbuff);
//					wait(0);
//				}
//				else
//				{
					printf("enter msg to cliient:");
					scanf(" %s",wrbuff);
					write(fd2,wrbuff,strlen(wrbuff)+1);	
//					exit(0);
//				}					
			}
			
//	if(flag==0)
//			puts("number,password are not matching");
		}
	}
}


void forgotpassword()
{
        MESG *temp;
        FILE *fp;
        fp=fopen("file.txt","r");
        temp=calloc(1,sizeof(MESG));
        char ph[11];
	int flag=0;
        puts("enter phone num:");
        scanf("%s",ph);
	fseek(fp,0,0);
        while(fread(temp,sizeof(MESG),1,fp))
	{
		puts(temp->name);
	//	puts(temp->phone);
		if(strcmp(temp->phone,ph)==0)
		{
			printf("password of %s is %s\n",temp->phone,temp->passwrd);
			flag=1;
			break;
		}
	}
	if(flag==0)
		puts("number not exist,please creat the account first");
	fclose(fp);
}

int number_verify(char *number_ptr)
{
	FILE *fp;
	MESG *temp;
	fp=fopen("file.txt","r");
	temp=calloc(1,sizeof(MESG)+1);
//	puts("in fun");
	while(fread(temp,sizeof(MESG),1,fp))
	{
//		puts("in loop");
		puts(temp->phone);
//		puts(number_ptr);
		printf("%d\n",strcmp(temp->phone,number_ptr));
		if(strcmp(temp->phone,number_ptr)==0)
		{
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}


int passwrd_verify(char *passwrd_ptr)
{
	 FILE *fp;
        MESG *temp;
        fp=fopen("file.txt","r");
        temp=calloc(1,sizeof(MESG));
//      puts("in fun");
        while(fread(temp,sizeof(MESG),1,fp))
        {
//              puts("in loop");
//              puts(temp->phone);
//              printf("%d\n",strcmp(temp->phone,number_ptr));
                if(strcmp(temp->passwrd,passwrd_ptr)==0)
                        return 1;

        }
        fclose(fp);
        return 0;
}
int passwrd_validation(char *passwrd)
{
	int index,capital_cnt=0,num_cnt=0,special_cnt=0,small_cnt=0;
	if((strlen(passwrd)>6)&&(strlen(passwrd)<10))
	{	for(index=0;passwrd[index];index++)
		{	
			if((passwrd[index]>='a')&&(passwrd[index]<='z'))
				small_cnt=1;
			else if((passwrd[index]>='A')&&(passwrd[index]<='Z'))
				capital_cnt=1;
			else if((passwrd[index]>='0')&&(passwrd[index]<='9'))
				num_cnt=1;
			else if((passwrd[index]=='@')||(passwrd[index]=='_'))
				special_cnt=1;
		}
		if((small_cnt==0)||(capital_cnt==0)||(num_cnt==0)||(special_cnt==0))
			return 1;
		else
			return 0;
	}
	else
		return 1;
	
}
int main()
{
	int choice;
	while(1)
	{
		printf("1.signup\n2.login\n3.forgot password\n4.clear screen\n5.exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:signup();break;
			case 2:signin();break;
			case 3:forgotpassword();break;
			case 4:system("clear");break;
			case 5:return;
			default:printf("invalid choice\n");
		}
	}	
}

