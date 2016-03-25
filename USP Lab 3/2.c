#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// >> ln -s 2.c link
// Reads the linked file and not the link contents

int main()
{
	int fd = open("link", O_RDONLY);
	if(fd < 0)
	{
		perror("Couldn't open the file");
	}
	else
	{
		char buf[1024] = {0};
		int bytes = read(fd, buf, 1023);
		buf[1023] = '\0';
		if(bytes < 0)
		{
			perror("Issue will reading file");
		}
		else
		{
			printf("Using read:\n\n%s\n", buf);
		}
		
		//ssize_t readlink(const char *path, char *buf, size_t bufsiz);
		bytes = readlink("link", buf, 1024);
		if(bytes == -1)
		{
			perror("Readlink failed");
		}
		else
		{
			buf[bytes] = '\0';
			printf("Using readlink:\n%s\n", buf);
		}

	}
}
