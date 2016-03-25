#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

main()
{
   int fd;
   char buf[10];
   if( symlink("abc.txt" , "R") == -1)
     perror("Error:");
   if( (fd = open("R" , O_RDONLY , 0777)) == -1)
     perror("Error:");
   printf("Reading the symbolic link directly.\n");
   read(fd , buf , sizeof(buf));
   printf("%s" , buf);
   char buf1[10];
   printf("\nThe actual contents of symbolic link is:\n");
   readlink("R" , buf1 , sizeof(buf1));
   printf("%s" , buf1);
   printf("\n");
  
}


