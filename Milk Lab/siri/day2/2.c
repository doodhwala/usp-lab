#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdlib.h>
int main()
{
	int fd1 = open("sample.txt",O_RDWR);
	char arfd1[10];
	char arfd2[10];
	char arfd3[10];
	if(fd1 < 0)
	{
		perror("open");
		exit(1);
	}
	
	printf("fd1 : %d\n" ,  fd1);
	read(fd1,arfd1,8);
	arfd1[9]='\0';
	int fd2 = dup(fd1);
	
	if(fd2 < 0)
	{
		perror("open");
		exit(1);
	}
	
	printf("fd2 : %d\n" ,  fd2);
	read(fd2,arfd2,8);
	arfd2[9]='\0';
	

	
	int fd3 =fcntl(fd1 ,F_DUPFD , 6);
	read(fd3,arfd3,7);
	arfd3[8]='\0';
	if(fd3 < 0)
	{
		perror("open");
		exit(1);
	}
	
	printf("reading form fd1 : %s\n" ,arfd1);
	printf("reading from fd2 : %s\n", arfd2);
	printf("reading from fd3 : %s\n", arfd3);
	if( close(fd1) < 0)
	{
		perror("close");
		exit(2);
		
	}
	
	if( close(fd2) < 0)
	{
		perror("close");
		exit(2);
		
	}

	
	
}
