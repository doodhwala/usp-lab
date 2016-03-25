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
  struct shmid_ds s;
  char* str;
  char* input;
  pid_t m;
  
  if( (shmid = shmget( (key_t)SHMKEY , SHMSIZE , IPC_CREAT|IPC_EXCL|0666 )) < 0)
     perror("Error");
     
  str = (char*)shmat(shmid , 0 , 0);
  shmctl(shmid , IPC_STAT , &s);
  printf("No. of attaches before fork = %d\n" , (int)s.shm_nattch);
  printf("Enter a string:\n");
  gets(input);
  strcpy(str , input);
  
  m = fork();
  if(m != 0)   //parent
  {
      wait(NULL);
      printf("The changed string = %s\n" , str);
      shmctl(shmid , IPC_RMID , NULL);
  }
  else         //child
  {
      shmctl(shmid , IPC_STAT , &s);
      printf("No. of attaches after fork = %d\n" , (int)s.shm_nattch);
      
      while(*str != NULL)
         *str = toupper(*str) , str++;
  }
}
         
      
      
      
      
      
      
      
      
      
      
      
      
  
  
