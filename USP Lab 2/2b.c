#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd1 = open("sample1.txt", O_RDWR);
	if(fd1 == -1)
	{
		perror("Error opening the file\n");
	}
	else
	{
		int fd2 = dup2(fd1, 1);		// stdout - 1
		printf("fd2: %d\n", fd2);
		int fd3 = dup2(fd1, 2);		// stderr - 2
		printf("fd3: %d\n", fd3);

		printf("How are you?\n");
		perror("What's up?\n");
	}
}
