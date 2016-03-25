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
	int al = alarm(2);
	//signal(SIGALRM, sighandler);
	printf("Execing Process(%d)\n", getpid());
	execl("./1execed.out", "", NULL);
	return 0;
}

/*

>> gcc 1execing.c
>> gcc 1execed.c -o 1execed.out
>> ./a.out
Execing Process(4943)
Execed Process(4943) sleeping for 10s
Received alarm in process 4943
Woken up by alarm :(
>> 

(after 2s)
*/
