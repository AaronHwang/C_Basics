#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void menu()
{
	printf("\n        Choose a bit operation:\n");
//	printf("-------------------------------------------\n");
	printf("     =================================\n");
	printf("             1 . Bit And .\n");
	printf("             2 . Bit Or .\n");
	printf("             3 . Quit .\n");
	printf("     =================================\n");


}

void deci2bi(int n)//十进制转换为二进制
{
	for (int i = sizeof(int)*8-1; i >=0; i--)//sizeof(int)*8 bits
	{
		int mask = 1 << i;//将1按位移动i位
		//printf("%d\n", mask);
		if(n & mask)//位与
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");

}

void bitand()
{
	unsigned int a,b;
	printf("Please input 2 non-negative decimal digits:");
	scanf("%d %d",&a, &b);
	printf("%d & %d = %d\n", a,b,a&b);
	printf("Because:\n");
	printf("  %10d = ", a);
	deci2bi(a);
	printf("& %10d = ", b);	
	deci2bi(b);
	for (int i = sizeof(int)*8+14; i >=0; i--)
	{
		printf("-");
	}
	printf("\n  %10d = ",a&b);
	deci2bi(a&b);

}

void bitor()
{
	unsigned int a,b;
	printf("Please input 2 non-negative decimal digits:");
	scanf("%d %d",&a, &b);
	printf("%d & %d = %d\n", a,b,a|b);
	printf("Because:\n");
	printf("  %10d = ", a);
	deci2bi(a);
	printf("& %10d = ", b);	
	deci2bi(b);
	for (int i = sizeof(int)*8+14; i >=0; i--)
	{
		printf("-");
	}
	printf("\n  %10d = ",a|b);
	deci2bi(a|b);

}


int main(void)
{

	int choice = 1 ;
	do
	{
		menu();
		scanf("%d",&choice);
		switch(choice)
		{
			case 1  : bitand(); break;
			case 2  : bitor(); break;			
			default : break;
		}

	}
	while((choice < 3)&&(choice > 0));

	return 0;
}
