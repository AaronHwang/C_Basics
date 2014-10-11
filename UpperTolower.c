//大写字母转换为小写
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void method1(char Upper)//十进制，类型转换
{
	printf("This is method1:The upper case letter you typed is %c,its lower case is %c.\n",Upper,Upper+32);//注意不需要使用'Upper'，也不需要做强制类型转换
}

char method2(char Upper)//二进制方法
{
	return Upper|0x20;
}

int main(void)
{
	char Upperletter;
	printf("Please type a capital letter you wanna convert:");
	scanf("%c",&Upperletter);
	if((Upperletter<'A')||(Upperletter>'Z'))
	{
		printf("Wrong Input!\n");
		return 0;
	}
	else
	{
		method1(Upperletter);
		printf("This is method2:The upper case letter you typed is %c,its lower case is %c.\n",Upperletter,method2(Upperletter));
		return 0;
	}

}
