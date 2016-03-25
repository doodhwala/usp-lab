#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/types.h>
#include <sys/shm.h>
#include <errno.h>
#include <stdlib.h>

#define SEMKEY 0x30
#define SHMKEY 0x40

#define P -1
#define V 1

main()
{

   int semid;
   struct sembuf semoperation[1];

   /*if( (semid = semget((key_t)SEMKEY, 2, 0666)) < 0)
       perror("Semaphore get error");*/
   if( (semid = semget((key_t)SEMKEY, 1, 0666)) < 0)
       perror("Semaphore get error");

   int shmid;
   int* array;

   if( (shmid = shmget( (key_t)SHMKEY , 10*sizeof(int) , 0666 )) < 0)
       perror("Error");

   array = (int*)shmat(shmid , 0 , 0);

   semoperation[0].sem_num = 0;
   //semoperation[0].sem_op = P;
   semoperation[0].sem_op = 0;
   semoperation[0].sem_flg = SEM_UNDO;
   semop(semid,semoperation,1);

   int i;
   for(i = 0; i < 10; i++)
     array[i] *= 2;

   printf("\nFirst child completed multiplying 2(pid = %d).\nArray Contents:-\n" , getpid());
   for(i = 0; i < 10; i++)
     printf("%d " , array[i]);
   printf("\n");

   //semoperation[0].sem_num = 1;
   semoperation[0].sem_num = 0;
   semoperation[0].sem_op = V;
   semoperation[0].sem_flg = SEM_UNDO;
   semop(semid,semoperation,1);

}















