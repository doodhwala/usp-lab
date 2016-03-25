#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SHMKEY 0x40
#define SHMSIZE 100

main()
{
  int shmid;
  int* array;
  int i;
 
  if( (shmid = shmget( (key_t)SHMKEY , SHMSIZE , IPC_CREAT|IPC_EXCL|0666 )) < 0)
     perror("Error");
     
  array = (int*)shmat(shmid , 0 , 0);
  for(i = 0; i < 100; i++)
    array[i] = rand() % 1000;
    
  printf("Array contents:\n");
  for(i = 0; i < 100; i++)
     printf("%d " , array[i]);
}
     
  
  
