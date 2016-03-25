#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{

printf("2a\n");
printf("file created\n");
int fd,fsize;
fd = open("/home/student/CS160/b.txt", O_RDWR);

		if(fd==-1)
		{
			perror(" file cant be opened/created, it already exists");
		}
		else
		{
			printf("2b\n");
			printf("%d\n",fd);
			int r=lseek(fd,-2,SEEK_SET);
			printf("seek to the beginning of the file: %d\n",r);
			close(fd);
		}
fd = open("/home/student/CS160/b.txt", O_RDWR);
printf("2c\n");
		if(fd==-1)
		{
			perror(" file cant be opened/created, it already exists");
		}
		else
		{
			printf("%d\n",fd);
			fsize = lseek(fd,0,SEEK_END);
			int r=lseek(fd,2,SEEK_END);
			printf("file size , offset: %d , %d\n",fsize,2);
			printf("seek to the end of the file: %d\n",r);
			close(fd);
		}
fd = open("/home/student/CS160/b.txt", O_RDWR);
printf("2d\n");
		if(fd==-1)
		{
			perror(" file cant be opened/created, it already exists");
		}
		else
		{
			printf("%d\n",fd);
			fsize = lseek(fd,0,SEEK_END);
			printf("file size :%d\n",fsize);
			write(fd," hello iam adding extra bytes", 10);
			fsize = lseek(fd,0,SEEK_END);
			printf("file size  after writing:%d\n",fsize);
			close(fd);
		}


	
return 0;
}

