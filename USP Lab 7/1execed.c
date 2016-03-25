/*
	Experiment signals on fork and exec.
	Setup a timer (alarm) - setup handler for the timer - fork (or exec) – check who gets the timer signal (SIGALRM)
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void sighandler(int val)
{
	printf("Received alarm in process %d\n", getpid());
}

int main()
{
	signal(SIGALRM, sighandler);
	
	/*
		Unless you do this, the default handler will be called.
			Default handler prints alarm clock and stops the sleep
	*/
	
	printf("Execed Process(%d) sleeping for 10s\n", getpid());
	if(sleep(10) != 0)
		printf("Woken up by alarm :(\n");
	return 0;
}


