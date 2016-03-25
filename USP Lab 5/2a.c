/*
	Experiment with environment variable. Create an environment variable. Fork and check whether the variable is available in both the parent and the child. Change in the child and check whether the variable has changed in the parent. Now change in the parent and check  whether the variable has changed in the child. Note down observations.

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

// char *getenv(const char *name);
// ptr on success, NULL if no match

// int setenv(const char *name, const char *value, int overwrite);
// If overwrite is non-zero, it overwrites
// 0 on success, -1 on error

// Environment variables available to both child and parent

int main()
{
	if(setenv("BestMilkman", "PapaDoodhwala", 1) == 0)
	{
		int pid = fork();
		if(pid < 0)
		{
			perror("Fork failed");
		}
		else if(pid == 0)
		{
			printf("BestMilkman in child's environment: %s\n", getenv("BestMilkman"));
			//sleep(100);
			printf("Child finished!\n");
		}
		else
		{
			printf("BestMilkman in parent's environment: %s\n", getenv("BestMilkman"));
			printf("Parent finished!\n");
		}
	}
	return 0;
}
