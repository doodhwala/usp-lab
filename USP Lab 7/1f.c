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
	int al = alarm(5);
	int pid = fork();
	
	signal(SIGALRM, sighandler);
	if(pid == 0)
	{
		printf("Child(%d) started sleeping\n", getpid());
		sleep(10);
		printf("Child(%d) finished sleeping\n", getpid());
	}
	else if(pid > 0)
	{
		printf("Parent(%d) started sleeping\n", getpid());
		sleep(10);
		printf("Parent(%d) finished sleeping\n", getpid());
	}
	return 0;
}

/*

>> gcc 1f.c
>> ./a.out
Parent(4692) started sleeping
Child(4693) started sleeping
Received alarm in process 4692
Parent(4692) finished sleeping
>> Child(4693) finished sleeping


*/
