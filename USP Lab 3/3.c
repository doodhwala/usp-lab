#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

int main()
{
	DIR * dir = opendir(".");
	struct dirent * entry;
	struct stat buffer;
	int res;
	
	if(dir == NULL)
	{
		perror("Couldn't open directory");
	}
	else
	{
		printf("Opened!\n");
		while((entry = readdir(dir)) != NULL)
		{
			printf("%s\n", entry->d_name);
			res = stat(entry->d_name, &buffer);
       		if(res == -1)
       		{
       			perror("Stat failed");
       		}
       		else
       		{
       			if(buffer.st_size == 0)
       			{
       				res = unlink(entry->d_name);
       				if(res == -1)
       				{
       					perror("Unlink failed");
       				}
       			}
       		}
		}
	}
}
