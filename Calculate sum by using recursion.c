#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sigma();//交换两个数

int main(void)
{
	int n;
	printf("请输入一个数字：");
	scanf("%d",&n);
	printf("从1连加至%d的和为:%d\n", n,sigma(n));
}

int sigma(int a)
{
	if (a<1)
	{
		return 0;
	}
	else
	{
		return sigma(a-1) + a;
	}
}

/*
int sigma(int a)
{
	if (a>0)
	{
		return sigma(a-1) + a;
	}
	else
	{
		return 0;
	}
}
*/