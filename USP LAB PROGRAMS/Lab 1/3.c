#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

main()
{
  int fd = open("reverse.txt" , O_RDONLY);
  char* buf;
  printf("The reversed contents:\n");
  int offset = lseek(fd , 0 , SEEK_END);
  while(offset != 1)
  {
    lseek(fd , -2 , SEEK_CUR);
    read(fd , buf , 1);
    printf("%s",buf);
    offset = lseek(fd , 0 , SEEK_CUR);
  }
  printf("\n");
}

