/*
	Experiment on exec as to what happens to pending signals. 

	Is it pending in the called process? Is it delivered to the called process if signal blocking is removed?
	a. Create the caller:
	Block a signal, send the signal, exec the "called" process
	b. Create the called:
		Check the pending state, find the current blocking (mask), unblock the signal
*/

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void sighandler(int val)
{
	printf("Finally received signal : KILL(%d)\n", val);
}

int main()
{
	signal(SIGINT, sighandler);
	sigset_t s1, s2;
	
	sigemptyset(&s1);
	sigaddset(&s1, SIGINT);
	
	sigprocmask(SIG_BLOCK, &s1, &s2);
	// Block SIGINT and store old set into s2
	printf("Blocked\n");
	kill(getpid(), SIGINT);
	printf("Created signal and execing\n");
	execl("2execed.out", "", NULL);
	
	return 0;
}
