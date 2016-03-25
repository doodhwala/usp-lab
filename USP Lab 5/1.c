/*
	Write a program which takes a command with arguments from the command line and executes it.
	./mypgm ls -l -i
	This should execute the ls cmd.
	Hint : - Experiment with execvp call
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
	// int execvp(const char *file, char *const argv[]);
	// "location", "commandwithhardlinkname, flag, flag, NULL"

	int res = execvp(argv[1], (argv+1));
	return 0;
}

// ./a.out ls -l -i
//    0    1   2  3
