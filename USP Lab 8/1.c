// Snakes and Ladders board

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int val;
int done;
int pid;

void pHandler(int sig)
{
	int i;
	for(i = val; i>val-10; --i)
	{
		printf("%4d", i);
	}
	printf("\n");
	val -= 20;
	if(val <= 0)
	{
		done = 1;
	}
	sleep(1);
	kill(pid, SIGUSR1);
}

void cHandler(int sig)
{
	int i;
	for(i = val; i<val+10; ++i)
	{
		printf("%4d", i);
	}
	printf("\n");
	val -= 20;
	if(val <= 0)
	{
		done = 1;
	}
	else
	{
		sleep(1);
		kill(getppid(), SIGUSR1);
	}
}

int main()
{
	done = 0;
	pid = fork();
	if(pid < 0)
	{
		perror("Fork failed");
	}
	else
	{
		if(pid == 0)
		{
			printf("P:%d C:%d\n", getppid(), getpid());
			
			val = 81;
			signal(SIGUSR1, cHandler);
			sleep(1);
			kill(getppid(), SIGUSR1);
			while(!done)
				pause();
		}
		else
		{
			val = 100;
			signal(SIGUSR1, pHandler);
			while(!done)
				pause();
		}
	}
}
