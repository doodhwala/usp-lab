#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main()
{

    int i;
    pid_t m;
    m=fork();
    if(m==0)
    {
        for(i='a';i<='z';i++)
        {
          sleep(rand() % 3);
          printf("%c\n",i);
        }
    }
    else
    {
        for(i='A';i<='Z';i++)
        {
           sleep(rand() % 3);
           printf("%c\n",i);
        }
    }
}


