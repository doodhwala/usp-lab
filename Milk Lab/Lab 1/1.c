#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int fd;
	fd = open("a.txt", O_RDONLY | O_CREAT | O_EXCL, 0664);
	if(fd == -1)
	{
		if(errno & EEXIST)
		{
			perror("File Exists");
		}
		else
		{
			perror("Some other error occurred");
		}
	}
	else
	{
		printf("It was a success! File created\n");
	}
	return 0;
}
