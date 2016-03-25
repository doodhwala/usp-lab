/*
	Create a shared memory segment. Write a program to populate memory with 100 random numbers between 1 and 1000. Write another program to find the average, the biggest and smallest numbers in the array created.
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

#define KEY 0xABCD1234

int main()
{
	int shmid = shmget(KEY, 400, 0666 | IPC_CREAT);
	if(shmid == -1)
	{
		perror("shmget");
		exit(1);
	}
	int * arr = (int *) shmat(shmid, (void *)0, 0);
	if(arr == (void *) -1 )
	{
		perror("shmat");
		exit(1);
	}
	
	int i;
	printf("Generating 100 random numbers!\n");
	for(i = 0; i<100; ++i)
	{
		arr[i] = 1 + (rand()%1000);
	}	
	printf("Generated 100 random numbers!\nFirst one is %d\n", arr[0]);
	if(shmdt((void *)arr) == -1)
	{
		perror("shmdt");
		exit(1);
	}
	return 0;
}

/*
	>> gcc 2gen.c -o gen.out
	>> ./gen.out
	Generating 100 random numbers!
	Generated 100 random numbers!
	First one is 384
*/
