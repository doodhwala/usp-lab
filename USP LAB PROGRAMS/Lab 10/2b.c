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
 
  if( (shmid = shmget( (key_t)SHMKEY , SHMSIZE , 0666 )) < 0)
     perror("Error");
     
  array = (int*)shmat(shmid , 0 , 0);
  
  int min = array[0] ,max = array[0]; 
  double avg = array[0];
  for(i = 1; i < 100; i++)
  {
      if(array[i] < min)
         min = array[i];
      if(array[i] > max)
         max = array[i];
      avg += array[i];
  }
  avg /= 100.0;
  printf("\nMinimum = %d\nMaximum = %d\nAverage = %lf\n" , min , max , avg);
  shmctl(shmid , IPC_RMID , NULL);
}
         
         
         
         
         
         
   
