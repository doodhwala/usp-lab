#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

main()
{
  if(open("a.txt",O_RDWR|O_CREAT|O_EXCL, 0664) == -1)
    perror();
}


