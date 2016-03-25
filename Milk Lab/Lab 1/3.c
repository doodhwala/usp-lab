#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h> // for lseek

int main()
{
	int fd;
	fd = open("c.txt", O_RDONLY);
	if(fd == -1)
	{
		perror("open failed with error: ");
	}
	else
	{
		int l = lseek(fd, -1, SEEK_END) + 1;
		
		char buf[16] = {0};
		printf("Our string:");
		while(l--)
		{
			int bytes = read(fd, buf, 1);
			printf("%s", buf);
			lseek(fd, -2, SEEK_CUR);
			//printf("File contents: %s\nBytes Read: %d\n", buf, bytes);
			//printf("LSEEK : %d\n", lseek(fd, -2, SEEK_CUR));
		}
		printf("\n");
		close(fd);
		
	}
	return 0;
}
