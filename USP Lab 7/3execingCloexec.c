/*
	Experiment with close-on-exec (FD_CLOEXEC) flag. 

	Write a program which execs another program. Check if file descriptors remain open across exec call. Set close-on-exec flag in exec-ing process using fcntl system call and observe what happens in exec-ed process.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = open("Questions.txt", O_RDONLY);
	if(fd < 0)
	{
		perror("Open failed");
	}
	else
	{
		if(fcntl(fd, F_SETFD, FD_CLOEXEC) == -1)
		{
			perror("Fcntl failed");
		}
		else
		{
			printf("Open with FD_CLOEXEC\n");
			printf("fd in execing process is %d\n", fd);
			// 3 usually
			execl("./3execed.out", "", NULL);
			// extra argument to make it work
		}
	}
	return 0;
}

/*

>> gcc 3execed.c -o 3execed.out
>> gcc 3execingCloexec.c
>> gcc 3execed.c -o 3execed.out
>> ./a.out
Open with FD_CLOEXEC
fd in execing process is 3

Entered the execed process
Read failed: Bad file descriptor

*/
