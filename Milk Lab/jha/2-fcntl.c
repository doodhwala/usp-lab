#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
	int fd;
	int res;
	fd = open("a.txt", O_RDONLY);
	if(fd < 0)
		perror("Error!");
	res = fcntl(fd, F_GETFL);
	if(res < 0)
		perror("Error!");
	printf("mode = %o\n", res);
	if(res == O_RDONLY)
		printf("read only");
	else if(res == O_WRONLY)
		printf("write only");
	else if(res == O_RDWR)
		printf("read write");
	else
		printf("lol");
	return 0;
}
