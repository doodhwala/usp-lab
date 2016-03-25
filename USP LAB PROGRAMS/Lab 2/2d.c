#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

main()
{
  int fd = open("hi.txt" , O_RDWR , 0777); 
  dup2(fd,1);
  printf("Hello.\n");
  dup2(fd,2);
  perror("Error msg");
}
