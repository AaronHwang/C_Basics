#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void menu()
{
	printf("\n          Choose a bit operation:\n");
	printf("      ===============================\n");
	printf("             ①   Bitwise And.\n"); 
	printf("             ②   Bitwise Or .\n");
	printf("             ③   Bitwise Not.\n");
	printf("             ④   Bitwise XOR.\n");
	printf("             ⑤   Quit .\n");
	printf("      ===============================\n");


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
	printf("Bitwise And:Please input 2 non-negative decimal digits:");
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
	printf("Bitwise Or:Please input 2 non-negative decimal digits:");
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

void bitnot()
{
	unsigned int a;
	printf("Bitwise Not:Please input a non-negative decimal digit:");
	scanf("%d",&a);
	printf("~ %d  = %d\n", a, ~a);
	printf("Because:\n");
	printf("  %10d = ", a);
	deci2bi(a);

	for (int i = sizeof(int)*8+14; i >=0; i--)
	{
		printf("-");
	}
	printf("\n  %10d = ",~a);
	deci2bi(~a);

}

void bitxor()
{
	unsigned int a,b;
	printf("Bitwise Exclusive Or(XOR):Please input 2 non-negative decimal digits:");
	scanf("%d %d",&a, &b);
	printf("%d ⊕ %d = %d\n", a,b,a^b);
	printf("Because:\n");
	printf("  %10d = ", a);
	deci2bi(a);
	printf("⊕ %10d = ", b);	
	deci2bi(b);
	for (int i = sizeof(int)*8+14; i >=0; i--)
	{
		printf("-");
	}
	printf("\n  %10d = ",a^b);
	deci2bi(a^b);

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
			case 3  : bitnot(); break;			
			case 4  : bitxor(); break;			
			default : printf("Quit.\n");break;
		}

	}
	while((choice < 5)&&(choice > 0));

	return 0;
}
