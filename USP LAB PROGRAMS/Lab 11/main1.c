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

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};


int main()
{
   int semid;

   /*if( (semid = semget((key_t)SEMKEY, 2, IPC_CREAT | 0666)) < 0)
	perror("Semaphore get error");
	
   union semun sem_union;
   sem_union.val = 1;
   semctl(semid,0,SETVAL,sem_union);

   sem_union.val = 0;
   semctl(semid,1,SETVAL,sem_union);*/

   if( (semid = semget((key_t)SEMKEY, 1, IPC_CREAT | 0666)) < 0)
	perror("Semaphore get error");

   int shmid;
   int* array;

   if( (shmid = shmget( (key_t)SHMKEY , 10*sizeof(int) , IPC_CREAT|IPC_EXCL|0666 )) < 0)
       perror("Error");

   array = (int*)shmat(shmid , 0 , 0);

   int i;
   for(i = 0; i < 10; i++)
     array[i] = rand() % 10;

   printf("\nInitial array elements(by parent , pid = %d):-\n" , getpid());
   for(i = 0; i < 10; i++)
     printf("%d " , array[i]);
   printf("\n");

   pid_t m1 , m2;
   m1 = fork();
   
   
   if(m1 != 0)    //parent
   {

       m2 = fork();
       if(m2 == 0)         //second child
       {
          printf("\nSecond child being execed(pid = %d).\n" , getpid());
          if( execl("./exec2" , "exec2" , (char*)0 ) < 0 )
              perror("Error");
       }
       else
       {
          waitpid(m2 , NULL , 0);
          printf("\nFinal Contents of shared memory (by parent , pid = %d):-\n" , getpid());
          for(i = 0; i < 10; i++)
              printf("%d " , array[i]);
          printf("\n\n");
          semctl(semid , 0 , IPC_RMID , 0);
          shmctl(shmid , IPC_RMID , NULL);
       }
   }
   else          //first child
   {
      printf("\nFirst child being execed(pid = %d).\n" , getpid());
      if( execl("./exec1" , "exec1" , (char*)0 ) < 0 )
          perror("Error");
   }
   
}














