// Orphan

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
		sleep(100);
		printf("Child finished!\n");
	}
	else
	{
		printf("Parent finished!\n");
	}
	return 0;
}

/*

PPID of child changes from 2973 to 1846

>> ./a.out
Child pid: 2974
Parent pid: 2973
Parent finished!

[1]+  Done                    ./a.out
>> ps -l
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1001  2469  2459  0  80   0 -  6768 wait   pts/10   00:00:00 bash
1 S  1001  2974  1846  0  80   0 -  1049 hrtime pts/10   00:00:00 a.out
0 R  1001  2981  2469  0  80   0 -  3554 -      pts/10   00:00:00 ps
>> 

>> ps -l 1846
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY        TIME CMD
4 S  1001  1846  1584  0  80   0 - 10083 poll_s ?          0:00 init --user
>> 

*/
