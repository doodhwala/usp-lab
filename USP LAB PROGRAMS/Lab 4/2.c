#include<stdio.h>
#include<stdlib.h>
int main()
{
   printf("abcd by %d\n" , getpid());
   pid_t m = fork();
   if(m != 0)
     sleep(1);
   printf("pqrs %d\n" , getpid());
   return 0;
}
