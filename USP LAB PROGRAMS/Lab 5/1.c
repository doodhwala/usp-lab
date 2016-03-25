#include <unistd.h>
#include <errno.h>

main(int argc , char*argv[])
{
   if(execvp(argv[1] , &argv[1]) == -1)
      perror("Error");
   
   // if(execv("/bin/ls" , &argv[1]) == -1)
   //    perror("Error");
   
   //if(execl("/bin/ls" , "ls" , "-l" , (char*)0) == -1)
    //   perror("Error");
       
   //if(execlp("ls" , "ls" , "-l" , (char*)0) == -1)
   //    perror("Error");
   
   
   
}
