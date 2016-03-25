#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

main()
{
  int fd = open("a.txt",O_RDWR) , offset;
  char *buf = "abcdefghijkl";
  printf("Seeking beyond the end of file:\n");
  offset = lseek(fd,30,SEEK_END);
  printf("The offset is %d\n" , offset);
  write(fd,buf,7);
  printf("Successfully written.\n");
}
