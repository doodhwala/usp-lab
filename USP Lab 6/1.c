// Static and Dynamic Linking

#include <stdio.h>
int main()
{
	printf("hello world\n");
	return 0;
}

/*

>> gcc -o 1dyna.out 1.c
>> gcc -static -o 1static.out 1.c

>> size 1dyna.out 
   text	   data	    bss	    dec	    hex	filename
   1186	    560	      8	   1754	    6da	1dyna.out

>> size 1static.out 
   text	   data	    bss	    dec	    hex	filename
 780955	   7532	   9600	 798087	  c2d87	1static.out

*/
