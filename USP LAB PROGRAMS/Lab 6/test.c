#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

main()
{
   int fd;
   if( (fd = open("test.txt" , O_RDWR|O_APPEND)) == -1)
      perror("Error");
   write(fd , "usp lab 5" , 9);
   close(fd);
   
}
   

