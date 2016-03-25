/*
	Implement client - server communication using pipes.
	Client sends a string
	Server makes the first char uppercase and sends it back
	Hint: require two pipes
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int pReq[2];
	int pRes[2];
	
	if(pipe(pReq) == -1)
	{
		perror("Pipe failed");
	}
	else if(pipe(pRes) == -1)
	{
		perror("Pipe failed");
	}
	else
	{
		char buf[100] = {'\0'};
		int pid = fork();
		if(pid < 0)
		{
			perror("Fork failed");
		}
		else
		{
			if(pid == 0)
			{
				printf("Enter the text: ");
				int l = scanf("%[^\n]s", buf);
				// to make it ignore whitespaces and stop at \n character
				write(pReq[1], buf, l+1);
				read(pRes[0], buf, l+1);
				printf("Text returned: %s\n", buf);
			}
			else
			{
				int l = read(pReq[0], buf, 100); // fill the buffer
				if(buf[0] >= 'a' && buf[0] <= 'z')
					buf[0] = buf[0] + 'A' - 'a';
				write(pRes[1], buf, l);
			}
		}
	}
		
}
