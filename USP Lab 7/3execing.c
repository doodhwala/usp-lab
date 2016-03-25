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
		printf("Opened without FD_CLOEXEC\n");
		printf("fd in execing process is %d\n", fd);
		// 3 usually
		execl("./3execed.out", "", NULL);
		// extra argument to make it work
	}
	return 0;
}

/*

>> gcc 3execing.c
>> gcc 3execed.c -o 3execed.out
>> ./a.out
Opened without FD_CLOEXEC
fd in execing process is 3

Entered the execed process
Read the following data:

1.
	Experiment signals on fork and exec.
	Setup a timer (alarm) - setup handler for the timer - fork (or exec) – check who gets the timer signal (SIGALRM)

2.
	Write a program (use signal system call)
	a. which calls a signal handler on SIGINT signal and then reset the default action of the SIGINT signal 
	b. which ignores SIGINT signal and then reset the default action of SIGINT signal
	
	Rewrite the program using sigaction system call

3.
	Experiment with close-on-exec (FD_CLOEXEC) flag. 

	Write a program which execs another program. Check if file descriptors remain open across exec call. Set close-on-exec flag in exec-ing process using fcntl system call and observe what happens in exec-ed process.

>> 

*/
