/*
5. Open a file for reading in a program. Remove the file from the directory. Confirm that 
   the filename no more exists using ls command. Can you read the file further in the program?
*/
// Code is same for 4 and 5

// O/P Works even after deletion!
// Why? DATA REMANANCE??

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
