/*	
	Create a shared memory segment. Attach to a process. Then fork and create a new child. Examine what happens to the # number of attaches. Make the parent write a string in the shared memory. Make the child change this string to uppercase. Make the parent display the changed string.
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

#define KEY 0xABCD0987

/*
	int shmget(key_t key, size_t size, int shmflg);
	void *shmat(int shmid, const void *shmaddr, int shmflg);
	int shmdt(const void *shmaddr);
*/

int main()
{
	int shmid = shmget(KEY, 100, 0666 | IPC_CREAT);
	if(shmid == -1)
	{
		perror("shmget");
		exit(1);
	}
	char * s = (char *) shmat(shmid, (void *)0, 0);
	if(s == (void *) -1 )
	{
		perror("shmat");
		exit(1);
	}
	int pid = fork();
	if(pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if(pid == 0)	// Child
	{
		pid = getppid();
		struct shmid_ds details;
		shmctl(shmid, IPC_STAT, &details);
		printf("Child still alive!\n# attaches: %d\n", details.shm_nattch);
		pause();
		//sleep(1);
		char c;
		int l = strlen(s);
		printf("Len: %d\n", l);
		int i;
		for(i = 0; i<l; ++i)
		{
			char c = s[i];
			if(c >= 'a' && c <= 'z')
				c = c + 'A' - 'a';
			s[i] = c;
		}
	}
	else	// Parent
	{
		strcpy(s, "he does not exist.");
		kill(pid, SIGCONT);
		wait((int *)0);
		struct shmid_ds details;
		shmctl(shmid, IPC_STAT, &details);
		printf("Child is dead!\n# attaches: %d\n", details.shm_nattch);
		printf("Changed string: %s\n", s);
	}
	if(shmdt((void *)s) == -1)
	{
		perror("shmdt");
		exit(1);
	}
	return 0;
}

/*
	ipcs -m (before executing a.out)
		key        shmid      owner      perms      bytes      nattch 
		0xabcd0987 2129939    student    666        100        0    
	ipcs -m (while a.out is getting executing a.out)
		0xabcd0987 2129939    student    666        100        2     
	
>>./a.out	
	Child still alive!
	# attaches: 2
	Len: 18
	Child is dead!
	# attaches: 1
	Changed string: HE DOES NOT EXIST.

*/
