#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert_sort(int array[], int length)
{
	int i = 0, j = 0, tmp = 0;

	if(NULL == array || 0 == length)
		return;

	for(i = 1; i <length; i++)
	{
		for(j = i; j >= 1; j--)
		{
			if(array[j] < array[j -1])
			{
				tmp = array[j];
				array[j] = array[j -1];
				array[j -1] = tmp;
			}
			else
			{
				break;
			}
		}

		for (int n = 0; n < length; n++)
		{
			printf("%d ", array[n]);
		}
		printf("\n");
	}	
}

void print(int array[], int length)
{
	if ( NULL == array || 0 == length)//这样写条件判断可以防止误赋值！
	{
		return;
	}

	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void test()
{
	int array[] = {1, 3, 5, 4, 2, 7, 9 , 8, 0, 12, 76, 23, 38};
	int length = sizeof(array)/sizeof(int);
	print(array,length);
	insert_sort(array,length);//传入参量为数组地址，因此直接可以修改数组的值
	print(array,length);
}

int main(void)
{
	test();	
}