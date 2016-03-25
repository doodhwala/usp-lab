/*
	Create a structure student having name, usn and marks of 5 subjects stored in an array.
	Create an array of students and sort them based on descending order of total marks.
*/

#include<stdio.h>

struct student
{
	char name[20];
	char usn[12];
	int marks[5];
}	yo[5] =	{
				{"A", "1PI12CS001", {12, 34, 56, 78, 90}},
				{"B", "1PI12CS002", {22, 44, 66, 88, 99}},
				{"C", "1PI12CS003", {90, 90, 90, 90, 90}},
				{"D", "1PI12CS004", {12, 12, 12, 12, 12}},
				{"E", "1PI12CS005", {2, 1, 4, 3, 5}}
			};


void sortmaadi(struct student * arr, int n, int (*f)(struct student *, struct student *))
{
	struct student temp;
	int i, j, c;
	for(i = 0; i<n-1; ++i)
	{
		for(j = i+1; j<n-i; ++j)
		{
			c = f(&arr[i], &arr[j]);
			if(c < 0)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
}

int f(struct student * a, struct student * b)
{
	int i, t1 = 0, t2 = 0;
	for(i = 0; i<5; ++i)
	{	
		t1 += (a->marks)[i];
		t2 += (b->marks)[i];
	}
	return t1 - t2;
}

void display(struct student * arr, int n)
{
	int i;
	for(i = 0; i<n; ++i)
	{
		printf("%s ", arr[i].name);
	}
	printf("\n");
}

int main()
{
	display(yo, 5);
	sortmaadi(yo, 5, f);
	display(yo, 5);
}
