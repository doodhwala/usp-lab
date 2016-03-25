/*
4. Open a file for reading in a program. As the program is still executing, move the file
   to a different name and/or different directory in the same file system. Can you read the 
   file further in the program? Experiment and check.
*/

// O/P You can still read it in both cases

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h> // for lseek

int main()
{
	int fd;
	fd = open("parallel.txt", O_RDONLY);
	if(fd == -1)
	{
		perror("open failed with error: ");
	}
	else
	{
		int dummy;
		scanf("%d", &dummy);
		
		char buf[1024] = {0};
		printf("Our string:\n\n");
		
		int bytes = read(fd, buf, 1024);
		printf("%s\n", buf);
		close(fd);
		
	}
	return 0;
}
