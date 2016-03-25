/*
	Write a program (use signal system call)
	a. which calls a signal handler on SIGINT signal and then reset the default action of the SIGINT signal 
	b. which ignores SIGINT signal and then reset the default action of SIGINT signal
	
	Rewrite the program using sigaction system call
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void sighandler(int val)
{
	// Ignore by not doing anything special
	if(signal(SIGINT, SIG_DFL) == SIG_ERR)
	{
		perror("Unable to reset SIGINT handler to default behaviour");
		exit(1);
	}
}

int main()
{
	if(signal(SIGINT, sighandler) == SIG_ERR)
	{
		perror("Unable to assign new SIGINT handler");
	}
	else
	{
		printf("First sleep\n");
		sleep(10);
		printf("Second sleep\n");
		sleep(10);
		printf("Third sleep\n");
		sleep(10);
		printf("Done\n");
	}
	return 0;
}

/*

>> gcc 2b-s.c
>> ./a.out
First sleep
^CSecond sleep
^C
>>

*/
