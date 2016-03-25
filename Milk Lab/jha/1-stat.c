/*
	a. File name
	b. File type
	c. File permissions
	d. File size
	e. inode number
	f. time stamp
	g. no: of links
Check for different file types
Create links and check the output
When does time stamp of directory get changed?
What is the significance of no: of links for a directory?
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main()
{
	struct stat s;
	struct stat *ps = &s;

	char* name = "a.txt";
	if(stat(name, ps) == -1)
		perror("Error!");

	printf("\n");
	printf("name:\t\t\t%s\n", name);
	printf("inode:\t\t\t%ld\n", ps->st_ino);
	printf("size:\t\t\t%ld bytes\n", ps->st_size);
	printf("no. of links:\t\t%d\n", ps->st_nlink);
	printf("Last status change:\t%s", ctime(&(ps->st_ctime)));
	
	printf("type:\t\t\t");
	int mode = ps->st_mode & S_IFMT;
	if(mode == S_IFBLK)
		printf("block device\n");
	else if(mode == S_IFCHR)
		printf("character device\n");
	else if(mode == S_IFDIR)
		printf("directory\n");
	else if(mode == S_IFREG)
		printf("regular file\n");
	else
		printf("unknown\n");
	//IFIFO - fifo pipe, IFLNK - symlink, IFREG, IFSOCK - socket
	
	printf("File Permissions:\t");
    printf( (S_ISDIR(ps->st_mode)) ? "d" : "-");
    printf( (ps->st_mode & S_IRUSR) ? "r" : "-");
    printf( (ps->st_mode & S_IWUSR) ? "w" : "-");
    printf( (ps->st_mode & S_IXUSR) ? "x" : "-");
    printf( (ps->st_mode & S_IRGRP) ? "r" : "-");
    printf( (ps->st_mode & S_IWGRP) ? "w" : "-");
    printf( (ps->st_mode & S_IXGRP) ? "x" : "-");
    printf( (ps->st_mode & S_IROTH) ? "r" : "-");
    printf( (ps->st_mode & S_IWOTH) ? "w" : "-");
    printf( (ps->st_mode & S_IXOTH) ? "x" : "-");
	printf("\n\n");
	
	char *ctime(const time_t *timep);
    
	return 0;
}
