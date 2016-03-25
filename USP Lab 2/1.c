#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main()
{
	struct stat s;
	struct stat *ps = &s;

	if( stat("/dev/log", ps) < 0)
	{
		perror("error");
	} 

	printf("File type:\t\t\t");

	switch (s.st_mode & S_IFMT)
	{
	   case S_IFBLK:  printf("block device\n");            break;
	   case S_IFCHR:  printf("character device\n");        break;
	   case S_IFDIR:  printf("directory\n");               break;
	   case S_IFIFO:  printf("FIFO/pipe\n");               break;
	   case S_IFLNK:  printf("symlink\n");                 break;
	   case S_IFREG:  printf("regular file\n");            break;
	   case S_IFSOCK: printf("socket\n");                  break;
	   default:       printf("unknown\n");                 break;
	}

	printf("Inode # : %d\n" , ps->st_ino);
	printf("Mode  : %o\n" , ps->st_mode);
	printf("No of hardlinks : %d\n", ps->st_nlink);
	printf("Size of the file : %dB\n", ps->st_size);
	printf("Last status change:       %s", ctime(&s.st_ctime));
	printf("Last file access:         %s", ctime(&s.st_atime));
	printf("Last file modification:   %s", ctime(&s.st_mtime));

}
