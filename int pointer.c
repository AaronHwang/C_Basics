#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap();//交换两个数

int main(void)
{
	int *n = malloc(sizeof(int));//an int type usually uses 4 bytes(32 bits)
	*n = 65;//从heap分配内存后可以赋值，注意*号，直接 int *n =65; 是错误的，与字符串的赋值要区别
	printf("%d\n", *n);

	int *n1;//从stack随机分配内存
	n1 = n;
	printf("%d\n", *n1);

	int n2 = 56;
	printf("%d	%d\n", *n1,n2);
	swap(n1,&n2); //注意参数!!!!!
	printf("%d	%d\n", *n1,n2);

}

void swap(int *a,int *b)//注意参数!!!!!这里*不代表go to
{
	printf("Swapping...\n");
	int tmp = *a;
	*a = *b;
	*b = tmp;
	printf("Done!\n");
}