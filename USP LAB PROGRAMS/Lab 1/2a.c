
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

main()
{
  int fd = open("a.txt",O_RDWR);
  printf("Seeking before the beginning of a file:\n");
  if(lseek(fd,-5,SEEK_SET) == -1)
    perror("Error");
}
  
  
