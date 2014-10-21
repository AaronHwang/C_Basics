#include <iostream>
using namespace std;

void select_sort(int array[], int length)//选择排序,
{
	if (length == 0 || array == NULL)
	{
		return;
	}

	int inner, outer, tmp;
	for (int outer = 0; outer < length - 1; outer++)
	{
		for (int inner = outer + 1; inner < length; inner++)
		{
			if (array[inner] < array[outer])
			{
				tmp = array[outer];
				array[outer] = array[inner];
				array[inner] = tmp;
			}
		}

		for (int i = 0; i < length ; i++)
		{
			cout<<array[i]<<" ";
		}
		cout << endl;
	}
}

void print(int array[], int length)
{
	if (array == NULL || length == 0)
	{
		return;
	}

	for (int index = 0; index < length; index++)
	{
		cout << array[index] << " ";
	}

	cout << endl;
}

void test()
{
	int array[] = {1, 3, 5, 4, 2, 7, 9 , 8, 0, 12, 76, 23, 38};
	int length = sizeof(array)/sizeof(int);
	print(array,length);
	select_sort(array,length);//传入参量为数组地址，因此直接可以修改数组的值
//	print(array,length);
}

int main(void)
{
	test();
}