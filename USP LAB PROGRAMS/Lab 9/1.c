#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

void handler(int signo)
{
   wait(NULL);
   exit(0);
}

int main()
{
	int pipe0[2];	
	int pipe1[2];	
    pid_t m;
    
	char str[100];  //string entered by client
	char buf[100];	// used by server
	
	if (pipe(pipe0) == -1 || pipe(pipe1) == -1) 
	    perror("Error");
	signal(SIGCHLD , handler);
	    
	m = fork();
	if(m == 0)     //client
	{
	   close(pipe0[1]);   //close write end of pipe0
	   close(pipe1[0]);   //close read end of pipe1
	   
	   while(1)
	   {
	      
	      printf("Enter a string:\n");
	      gets(str);
	      //printf("%d\n" , strlen(str));
	      
	      if(strcmp(str , "exit") == 0)
	          exit(0);
	      int m;
	      
	      m = write(pipe1[1] , &str , 100);
	      read(pipe0[0] , &str , m);
	      printf("Changed string: %s\n" , str);
	   }
	   
	   
	}
	else           //server
	{
	   
	   close(pipe0[0]);   //close read end of pipe0
	   close(pipe1[1]);   //close write end of pipe1
	   
	   int n;
	   
	   while(1)
	   {
	     n = read(pipe1[0] , &buf , 100);
         buf[0] = toupper(buf[0]);
         write(pipe0[1] , &buf , n);
         
       }
	   
	
	}
}
	
	
	
	
	
	
	
	
	
