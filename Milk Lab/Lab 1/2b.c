#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h> // for lseek

int main()
{
	int fd;
	fd = open("b.txt", O_RDWR);
	if(fd == -1)
	{
		perror("open failed with error: ");
	}
	else
	{
		int l = lseek(fd, -1, SEEK_SET);
		if(l == -1)
		{
			perror("Unable to seek before beginning of file: ");
		}
		else
		{
			printf("Bytes Seeked: %d\n", l);
		}
		close(fd);
	}
	return 0;
}
