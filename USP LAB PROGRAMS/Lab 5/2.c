#include <stdlib.h>
#include <stdio.h>

main()
{
    char name[10] = "Harsha";
    setenv(name , "1pi12cs177" , 1);
    printf("In Parent, value = %s\n" , getenv(name));
    pid_t m = fork();
    if(m == 0)
    {
       printf("In child, value = %s\n" , getenv(name));
       setenv(name , "CSE" , 1);
       printf("In child, changed value = %s\n" , getenv(name));
       sleep(10);
       printf("In child, value = %s\n" , getenv(name));
    }
    else
    {
       sleep(5);
       printf("In parent, value = %s\n" , getenv(name));
       setenv(name , "PESIT" , 1);
       printf("In parent, changed value = %s\n" , getenv(name));
    }
}
