#include<stdio.h>
#include<stdlib.h>
int main()
{
   fork();
   fork()&&fork()||fork();
   fork();
   printf("text by %d\n" , (int)getpid());
   return 0;
}
