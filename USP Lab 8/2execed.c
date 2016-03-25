/*
	Check the pending state, find the current blocking (mask), unblock the signal
*/

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void sighandler(int val)
{
	printf("Finally received signal after exec : KILL(%d)\n", val);
}

int main()
{
	signal(SIGINT, sighandler);
	sigset_t s1, s2, pend;
	
	sigpending(&pend);
	if(sigismember(&pend, SIGINT))
	{
		printf("SIGINT : KILL(%d) is pending\n", SIGINT);
	}
	
	sigemptyset(&s1);
	sigprocmask(SIG_BLOCK, &s1, &s2);
	
	if(sigismember(&s2, SIGINT))
	{
		printf("SIGINT : KILL(%d) is blocked\n", SIGINT);
	}
	
	printf("Unblocking\n");
	
	sigaddset(&s1, SIGINT);
	sigprocmask(SIG_UNBLOCK, &s1, &s2);
	
	printf("Done\n");
	return 0;
}
