#include <stdio.h>
#include <unistd.h>

main()
{
   pid_t m;
   m = fork();
   
   if(m == 0)
   {
       printf("Child process id = %d\n" , getpid());
       sleep(5);
   }
   
      
}


   
    
   
