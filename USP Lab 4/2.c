#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("abcd\n");
	fork(); 
	printf("pqrs\n");
	return 0;
}

/*

a. Run the program as it is
	abcd
	pqrs
	pqrs

b. Remove the new line in the first printf and try it
	abcdpqrs
	abcdpqrs

c. Re-introduce the new line in the first printf and run the program as ./pgm > out and check what is stored in the file out 
	abcd
	pqrs
	abcd
	pqrs

Reasons:
a) Normal behaviour just as expected.
b) printf flushes output to stdout only when it encounters \n. Hence, at the time of forking, the buffer has abcd in it and that gets printed twice when we print pqrs.
c) For files, it does not flush on newline so that it can reduce disk accesses and hence we get abcd despite the newline for the forked process as well.

*/
