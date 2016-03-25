#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/types.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>

#define SEMKEY 0x30

#define P -1
#define V 1

int semid;

void handler(int signo)
{
   wait(NULL);
   semctl(semid , 0 , IPC_RMID , 0);
   exit(0);
}

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};


int main()
{
   struct sembuf semoperation[1];

   if( (semid = semget((key_t)SEMKEY, 2, IPC_CREAT | 0666)) < 0)
	perror("Semaphore get error");
	
   union semun sem_union;
   sem_union.val = 1;
   semctl(semid,0,SETVAL,sem_union);

   sem_union.val = 0;
   semctl(semid,1,SETVAL,sem_union);

   signal(SIGCHLD , handler);
   printf("Charcters from 'a' to 'z':-\n\n");

   pid_t m = fork();
   
   if(m != 0)      //parent
   {
      char c = 'a';
      while(1)
      {
        semoperation[0].sem_num = 0;
        semoperation[0].sem_op = P;
        semoperation[0].sem_flg = SEM_UNDO;
        semop(semid,semoperation,1);

        printf("%c   - pid = %d\n\n" , c , getpid());
        c += 2;

        semoperation[0].sem_num = 1;
        semoperation[0].sem_op = V;
        semoperation[0].sem_flg = SEM_UNDO;
        semop(semid,semoperation,1);
      }
   }
   else            //child
   {
      char c = 'b';
      while(1)
      {
        semoperation[0].sem_num = 1;
        semoperation[0].sem_op = P;
        semoperation[0].sem_flg = SEM_UNDO;
        semop(semid,semoperation,1);

        printf("%c   - pid = %d\n\n" , c , getpid());
        if(c == 'z')
           exit(0);
        c += 2;

        semoperation[0].sem_num = 0;
        semoperation[0].sem_op = V;
        semoperation[0].sem_flg = SEM_UNDO;
        semop(semid,semoperation,1);
      }
   }

}



















