#include <sys/types.h>
#include<string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

 
struct msgbuf
{
    long    mtype;
    char    cmd[5];
    int     value;
} ;
 
//server program

main()
{
    int msqid_i , msqid_o;
    key_t key_i, key_o;
    struct msgbuf rbuf;
    key_i = 1234;     //input queue
    key_o = 5678;     //output queue
    
 
    if ((msqid_i = msgget(key_i, IPC_CREAT | 0666)) < 0)    //input queue creation
          perror("Error");          
          
    if ((msqid_o = msgget(key_o, IPC_CREAT | 0666)) < 0)    //output queue creation
          perror("Error");
          
    while(1)
    {   
        if(msgrcv(msqid_i, &rbuf, sizeof(rbuf) - sizeof(long) , 0l , 0) < 0 )    //receive the first message on input queue
           perror("Error");  
        else
        {
            printf("\nMessage received from input queue.\n");
            printf("Command = %s\n" , rbuf.cmd);
            printf("Value = %d\n" , rbuf.value);
            
            //modify the rbuf structure(by squaring or cubing the value) and put it to output queue
            if(rbuf.mtype == 1l)
               rbuf.value = rbuf.value*rbuf.value;
            else
               rbuf.value = rbuf.value*rbuf.value*rbuf.value;
               
            if(msgsnd(msqid_o, &rbuf, sizeof(rbuf) - sizeof(long) , 0) < 0)     //send the updated message to output queue
               perror("Error"); 
            else
               printf("Updated message put to output queue with updated value = %d\n" , rbuf.value); 
        }
     }
        
}










