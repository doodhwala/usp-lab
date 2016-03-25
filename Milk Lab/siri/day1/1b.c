#include<stdio.h>
#include<fcntl.h>


int main()
{

int fd;
fd = open("/home/student/CS160/a.txt", O_CREAT|O_EXCL);

if(fd==-1)
{
	perror(" file cant be opened/created, it already exists");
}
else
{
	printf("file has been succesfully created");
}

return 0;
}

