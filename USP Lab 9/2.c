/*
	Create a message queue with the following message structure.
		char cmd[5];
		int val;
	cmd takes strings sqr or cube.
	Server receives the messages into input msg queue from multiple clients.
	Based on the cmd, server squares or cubes the value in val and sends the message through an output msg queue.
	Each client should receive his message.

	What happens if the message queue is removed
	   a)   when the queue contains # of messages
	   b)   when the client is waiting to read a message
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define LISTENINGPORT 1
#define KEY 0x01

// Split to server and client
// Use two queues

struct myMsg
{
	long type;
	char cmd[5];
	int val;
	int pid;
};

int main()
{
	int msgSize = sizeof(struct myMsg) - sizeof(long);
	int pid = fork();
	if(pid < 0)
	{
		perror("Fork failed");
	}
	else
	{
		if(pid == 0)
		{
			sleep(1);
			struct myMsg m;
			m.type = LISTENINGPORT;
			//int mqid = msgget(ftok("/home/Desktop/doodhwala", 12), 0600);
			int mqid = msgget(KEY, 0600);
			printf("MQID:%d\n", mqid);
			pid = fork(); // two clients
			if(pid == 0)
			{
				strcpy(m.cmd, "sqr\0");
			}
			else
			{
				strcpy(m.cmd, "cube\0");
			}
			fork();
			fork();
			srand(getpid());
			m.pid = getpid();
			m.val = rand()%100;
			printf("PID: %d\tCommand: %s\tValue Sent: %d\n", getpid(), m.cmd, m.val);
			if(msgsnd(mqid, (void *)&m, msgSize, 0) == -1)
			{
				perror("msgsnd in client");
				exit(1);
			}
			if(msgrcv(mqid, &m, msgSize, getpid(), 0) == -1)
			{
				perror("msgsnd in client");
				exit(1);
			}
			printf("PID: %d\tCommand: %s\tValue Received: %d\n", getpid(), m.cmd, m.val);
		}
		else
		{
			//int mqid = msgget(ftok("/home/Desktop/doodhwala", 12), IPC_CREAT | 0666);
			int mqid = msgget(KEY, IPC_CREAT | 0666);
			struct myMsg m;
			while(1)
			{
				if(msgrcv(mqid, &m, msgSize, LISTENINGPORT, 0) == -1)
				{
					perror("msgrcv in server");
					exit(1);
				}
				m.type = m.pid;
				if(strcmp(m.cmd, "sqr") == 0)
					m.val = m.val * m.val;
				else if(strcmp(m.cmd, "cube") == 0)
					m.val = m.val * m.val * m.val;
				if(msgsnd(mqid, &m, msgSize, 0) == -1)
				{
					perror("msgsnd in server");
					exit(1);
				}
			}
		}
	}	
}
