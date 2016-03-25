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
	int shmid = shmget(KEY, 400, 0666);
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
	double avg = 0;
	int min = arr[0], max = arr[0];
	for(i = 1; i<100; ++i)
	{
		min = min > arr[i] ? arr[i] : min;
		max = max < arr[i] ? arr[i] : max;
		avg += arr[i];
	}
	avg /= 100.0;
	
	printf("First one is %d\n", arr[0]);
	printf("Minimum is %d\n", min);
	printf("Maximum is %d\n", max);
	printf("Average is %f\n", avg);
	
	if(shmdt((void *)arr) == -1)
	{
		perror("shmdt");
		exit(1);
	}
	return 0;
}

/*
	>> gcc 2process.c -o process.out
	>> ./process.out
	First one is 384
	Minimum is 12
	Maximum is 997
	Average is 474.000000
*/
