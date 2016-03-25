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


/*
	int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
	
	struct sigaction {
		void     (*sa_handler)(int);
		void     (*sa_sigaction)(int, siginfo_t *, void *);
		sigset_t   sa_mask;
		int        sa_flags;
		void     (*sa_restorer)(void);
	};

*/

void sighandler(int val)
{
	printf("\nReceived SIGINT(%d)\nResetting behaviour to default behaviour\n", val);
	if(signal(SIGINT, SIG_DFL) == SIG_ERR)
	{
		perror("Unable to reset SIGINT handler to default behaviour");
		exit(1);
	}
}

int main()
{
	struct sigaction sa;
	sa.sa_handler = sighandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	if(sigaction(SIGINT, &sa, 0) == -1)
	{
		perror("Unable to assign new SIGINT handler using sigaction");
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

>> gcc 2a-sa.c
>> ./a.out
First sleep
^C
Received SIGINT(2)
Resetting behaviour to default behaviour
Second sleep
^C
>> 

*/
