// Zombie
// Try kill -9 pid

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
	int pid = fork();
	if(pid < 0)
	{
		perror("Fork failed");
	}
	else if(pid == 0)
	{
		printf("Child pid: %d\nParent pid: %d\n", getpid(), getppid());
		printf("Child finished!\n");
	}
	else
	{
		sleep(100);
		printf("Parent finished!\n");
	}
	return 0;
}

/*

Can't kill it!

>> ./a.out&
[1] 2946
>> Child pid: 2947
Parent pid: 2946
Child finished!
ps
  PID TTY          TIME CMD
 2469 pts/10   00:00:00 bash
 2946 pts/10   00:00:00 a.out
 2947 pts/10   00:00:00 a.out <defunct>
 2949 pts/10   00:00:00 ps
>> kill -9 2947
>> ps
  PID TTY          TIME CMD
 2469 pts/10   00:00:00 bash
 2946 pts/10   00:00:00 a.out
 2947 pts/10   00:00:00 a.out <defunct>
 2951 pts/10   00:00:00 ps
>> 

*/
