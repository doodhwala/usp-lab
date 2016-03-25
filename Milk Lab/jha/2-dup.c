#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int ofd = open("a.txt", O_RDONLY);
	if(ofd == -1)
		perror("Error!");
	else
	{
		int fd = dup(fd);
		int nfd = dup2(ofd, fd);
		printf("Old FD = %d\n", ofd);
		printf("FD = %d\n", fd);
		printf("New FD = %d\n", nfd);
	}
	close(ofd);
	//int dup(int oldfd);
	//int dup2(int oldfd, int newfd);
	return 0;
}
