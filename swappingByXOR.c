#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
	printf("\"o\" represents \"original\"\n");
	*a = *a ^ *b;
	printf("a = a ⊕ b = ao ⊕ bo\n");
	*b = *a ^ *b;
	printf("b = a ⊕ b = (ao ⊕ bo) ⊕ bo = ao\n");
	*a = *a ^ *b;
	printf("a = a ⊕ b = (ao ⊕ bo) ⊕ ao = bo\n");
}

int main(void)
{
	int a,b;
	printf("please input 2 numbers you wanna swap:");
	scanf("%d %d",&a,&b);
	printf("a = %d, b = %d\n", a , b);
	printf("swapping 2 numbers...\n");
	swap(&a,&b);
	printf("a = %d, b = %d\n", a , b);
}

