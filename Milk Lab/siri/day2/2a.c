#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdlib.h>
int main()
{
	int fd1 = open("sample.txt",O_RDWR);
	char arfd1[10];
	char arfd2[10];
	if(fd1 < 0)
	{
		perror("open");
		exit(1);
	}
	
	printf("fd1 : %d\n" ,  fd1);
	read(fd1,arfd1,8);
	arfd1[9]='\0';
	int fd2 = dup(fd1);
	

	int fd3 = dup2(fd1,5);
	printf("fd3 : %d\n" ,  fd3);
	read(fd3,arfd2,8);
	arfd2[9]='\0';
	
	
	printf("reading form fd1 : %s\n" ,arfd1);
	printf("reading from fd3 : %s\n", arfd2);
	


	
	
}
