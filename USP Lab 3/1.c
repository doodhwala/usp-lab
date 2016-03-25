/*
Write a program which takes a list of arguments from the command line.

	a. If the argument is a file, it should display the file contents. 

	b. If the argument is a directory, it should display all files and subdirectories in that directory (Display the no: of files and no: of  directories also)

	c. If there are no arguments, output should be all files and directories in the current working directory (Display the no: of files and no: of directories also)

Ignore . and .. entries while reading directory contents
Use opendir() and readdir() system calls
Arguments can be a combination of filenames and directories.

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

void readDirContents(char * path)
{
	DIR * dir = opendir(path);
	struct dirent * entry;
	
	struct stat buffer;
	int res;
	
	int fc = 0, dc = 0;
	if(dir == NULL)
	{
		perror("Couldn't open directory");
	}
	else
	{
		printf("Opened current directory!\n");
		while((entry = readdir(dir)) != NULL)
		{
			//printf("%s\n", entry->d_name);
			if(strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
			{
				// New to create the entire path
				char newPath[64] = {'\0'};
				strcat(newPath, path);
				strcat(newPath, "/");
				strcat(newPath, entry->d_name);
				
				res = stat(newPath, &buffer);
				//res = stat(entry->d_name, &buffer);
				if(res == -1)
				{
					perror("Stat failed");
				}
				else
				{
					if(S_ISREG(buffer.st_mode))
						fc++;
					else if(S_ISDIR(buffer.st_mode))
						dc++;
				}
			}
		}
		printf("%d file(s) and %d directories\n", fc, dc);
	}
}

void readFileContents(char * path)
{
	int fd = open(path, O_RDONLY);
	
	if(fd < 0)
	{
		perror("Couldn't open file");
	}
	else
	{
		char buf[4096];
		int bytes = read(fd, buf, 4095);
		if(bytes < 0)
		{
			perror("Read failed");
		}
		else
		{
			buf[bytes] = '\0';
			printf("%s\n", buf);
		}
	}
}

int main(int argc, char ** argv)
{
	struct stat buffer;
	int res;
	int i;
	
	if(argc == 1)
	{
		readDirContents(".");
	}
	else
	{
		for(i = 1; i<argc; ++i)
		{
			printf("%s\n", argv[i]);
			res = stat(argv[i], &buffer);
			if(res != -1)
			{
				if(S_ISREG(buffer.st_mode))
				{
					readFileContents(argv[i]);
				}
				else if(S_ISDIR(buffer.st_mode))
				{
					readDirContents(argv[i]);
				}
			}
		}
	}
	
}
