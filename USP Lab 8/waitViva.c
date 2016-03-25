#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pid = fork();
	if(pid == 0)
	{
		exit(0);
	}
	else
	{
		sleep(5);
		wait(0);
		wait(0);
	}
}
