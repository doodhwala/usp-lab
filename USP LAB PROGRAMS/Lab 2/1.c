#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>

main()
{
  struct stat buf;
  int a;
  if((a = lstat("hello.txt" , &buf)) >= 0)
  {
    printf("File Type: ");
    if(S_ISREG(buf.st_mode))
      printf("Regular file\n");
    else if(S_ISDIR(buf.st_mode))
      printf("Directory\n");
    else if(S_ISCHR(buf.st_mode))
      printf("Character device file\n");
    else if(S_ISBLK(buf.st_mode))
      printf("Block device file\n");
    else if(S_ISLNK(buf.st_mode))
      printf("Symbolic Link File\n");
    
    printf("Inode number: %d\n" , (int)buf.st_ino);
    printf("File Size: %d\n" , (int)buf.st_size);
    printf("Number of hard links: %d\n" , (int)buf.st_nlink);
    printf("Time of last access: %s" , ctime(&buf.st_atime));
    printf("Time of last modification: %s" ,ctime (&buf.st_mtime));
    printf("Time of last status change: %s" ,ctime(&buf.st_ctime));
    printf("File permissions: %o\n" , (int)buf.st_mode);
    
  }
}


