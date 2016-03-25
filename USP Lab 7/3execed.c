/*
	Experiment with close-on-exec (FD_CLOEXEC) flag. 

	Write a program which execs another program. Check if file descriptors remain open across exec call. Set close-on-exec flag in exec-ing process using fcntl system call and observe what happens in exec-ed process.
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
	char buf[2048] = {'\0'};
	printf("\nEntered the execed process\n");
	if(read(3, buf, 2047) < 0)
	{
		perror("Read failed");
	}
	else
	{
		printf("Read the following data:\n\n%s\n", buf);
	}
	return 0;
}


