#include<stdio.h>
#include<fcntl.h>


int main()
{

int fd;
fd = open("/home/student/CS160/a.txt", O_CREAT|O_RDWR,0664);

if(fd==-1)
{
	perror(" file cant be opened/created, it already exists");
}

return 0;
}

