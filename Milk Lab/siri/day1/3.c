#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
int fd;
fd = open("/home/student/CS160/b.txt", O_RDONLY);
		if(fd==-1)
		{
			perror(" file cant be opened");
		}
		else
		{
			printf("%d\n",fd);
			int n=lseek(fd,0,SEEK_END);
			int i;
			char buf;
			for(i = n-1 ; i >=0 ; i--)
			{
				lseek(fd,i,SEEK_SET);
				read(fd,&buf,1);
				printf("%c",buf);
			}
			close(fd);
		}

return 0;
}
