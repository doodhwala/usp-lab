#include <unistd.h>

main()
{
  int a = dup2(1 , 8);
  printf("On duplicating std_out, new descriptor: %d\n" , a);
  write(8 , "hello\n" , 7);
}

