#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


struct msgbuf
{
    long    mtype;
    char    cmd[5];
    int     value;
};

//client program
 
main()
{
    int msqid_i , msqid_o , num;
    long type;
    key_t key_i , key_o;
    struct msgbuf sbuf;
    key_i = 1234;     //input queue
    key_o = 5678;     //output queue
    char input[4];
    
    if ((msqid_i = msgget(key_i, 0666)) < 0)    //input queue access
          perror("Error");          
          
    if ((msqid_o = msgget(key_o, 0666)) < 0)    //output queue access
          perror("Error");
          
          
    while(1)
    {
       printf("\nEnter 'sqr' or 'cube' or 'quit':\n");
       scanf("%s" , input);
       if(strcmp("quit" , input) == 0)
          exit(0);
       else if( (strcmp("sqr" , input) != 0) && (strcmp("cube" , input) != 0) )
       {
          printf("Invalid command....\n");
          continue; 
       }
       else
       {
          printf("Enter the value:\n");
          scanf("%d" , &num);
          sbuf.value = num;
          if(strcmp("sqr" , input) == 0)
             type = sbuf.mtype = 1l, strcpy(sbuf.cmd , input);
          else if(strcmp("cube" , input) == 0)
             type = sbuf.mtype = 2l, strcpy(sbuf.cmd , input); 
       }
                

       if(msgsnd(msqid_i, &sbuf, sizeof(sbuf) - sizeof(long) , 0) < 0)     //send the message to input queue
           perror("Error"); 
       else
           printf("Message put to input queue with value = %d\n" , sbuf.value);        

       if(msgrcv(msqid_o, &sbuf, sizeof(sbuf) - sizeof(long) , type , 0) < 0 )    //receive the message of required 'type' from output queue
           perror("Error");
       else
           printf("Message received from output queue.\nUpdated value = %d\n" , sbuf.value);
             
    }
}


