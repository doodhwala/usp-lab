#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int fd1 = open("sample1.txt",O_RDWR);
	if(fd1 == -1)
	{
		perror("Error opening the file\n");
	}

	int fd2 = dup2(fd1,1); 	//fd1 is for stdout
	printf("fd2: %d \n",fd2);
	int fd3 = dup2(fd1,2); // fd 2 is for stderr
	printf("fd3: %d \n",fd3);


	printf("hello, how are you");
	perror("whats up in life? ");
	
	
}
