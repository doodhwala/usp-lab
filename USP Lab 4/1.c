#include <stdio.h>
#include <unistd.h>

int main()
{
	fork();
	fork() && fork() || fork();
	fork();
	printf("test\n");
	return 0;
}

/*
	20 processes
	(fork() && fork()) || fork();
	A && B || C

	2(first) * 2(last)
	Middle
	Pf
		~P (AB(C+C'))
		Cf
			~P (AB'C)
			~C (AB'C')
	Cf (evaluate or part)
		~P (A'(B+B')C)
		~C (A'(B+B')C')

	~ ones don't fork further
	So 2*5*2 = 20 processes
	Accounted for all 8 cases
	
	Show tree structure in the observation book
*/
