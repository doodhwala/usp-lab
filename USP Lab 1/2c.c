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
		int l = lseek(fd, 12, SEEK_END);
		if(l == -1)
		{
			perror("Unable to seek beyond end of file: ");
		}
		else
		{
			printf("Bytes Seeked: %d\n", l);
			close(fd);
			// NO DIFFERENCE IN FILE SIZE
		}
	}
	return 0;
}
