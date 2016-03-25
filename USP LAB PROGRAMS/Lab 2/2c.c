#include <unistd.h>
#include <fcntl.h>

main()
{
  dup2(1,8);
  close(8);
  int a = fcntl(2 , F_DUPFD , 8);
  printf("On duplicating std_out, new descriptor: %d\n" , a);
}

