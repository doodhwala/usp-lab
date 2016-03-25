/*
Write a program in which the parent displays uppercase characters A-Z and child displays lowercase characters a-z with a delay of max of 2 seconds (try randomizing the delay) between each character. Run the program repeatedly and see if there is racing.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Yes, racing is observed even for 2-3 different trials
int main()
{
	char c;
	int delay;
	
	int pid = fork();
	if(pid < 0)
	{
		perror("Fork failed");
	}
	else if(pid == 0)	// child
	{
		for(c = 'a'; c <= 'z'; ++c)
		{
			printf("%c\n", c);
			delay = rand()%3;
			sleep(delay);
		}
	}
	else	// parent
	{
		for(c = 'A'; c <= 'Z'; ++c)
		{
			printf("%c\n", c);
			delay = rand()%3;
			sleep(delay);
		}
	}	
}
