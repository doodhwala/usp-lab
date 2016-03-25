#include <unistd.h>

main()
{
  int a = dup(1);
  printf("On duplicating std_out, new descriptor: %d\n" , a);
  write(a,"Hello\n",7);
}


