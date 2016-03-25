/*
	Experiment with environment variable. Create an environment variable. Fork and check whether the variable is available in both the parent and the child. Change in the child and check whether the variable has changed in the parent. Now change in the parent and check  whether the variable has changed in the child. Note down observations.

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

// Changes made by the parent, are not reflected in the child's environment and vice versa!

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
			sleep(2);
			printf("BestMilkman in child's environment: %s\n", getenv("BestMilkman"));
			printf("Child finished!\n");
		}
		else
		{
			printf("BestMilkman in parent's environment: %s\n", getenv("BestMilkman"));
			setenv("BestMilkman", "DadaDoodhwala", 1);
			printf("BestMilkman in parent's changed environment: %s\n", getenv("BestMilkman"));
			printf("Parent finished!\n");
		}
	}
	return 0;
}
