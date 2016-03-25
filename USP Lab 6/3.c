#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

int main()
{
	int fd = open("test.dat", O_RDWR | O_APPEND);
	printf("fd = %d\n", fd);
	if(fd > 0)
	{
		int bytes = write(fd, "I just appended a line of text\n", 31);
		if(bytes == 31)
		{
			printf("Successfully opened and wrote into the file\n");
		}
		else
		{
			perror("Write failed");
		}
		int res = close(fd);
		if(res == -1)
		{
			perror("Close failed");
		}
		else
		{
			printf("Closed file and end of program\n");
		}
	}
	else
	{
		perror("Open failed");
	}
	
}
