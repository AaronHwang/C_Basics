#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
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

void straightInsertSort(int array[], int length)  
{  
    if (NULL == array || 1 == length )//如果数组为空或长度为零
        return ;

    for(int i= 1; i < length; i++)
    {  
        printf("key = %d,", array[i]);

        if(array[i] < array[i - 1])//若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入
        {                 
            int j = i - 1;   
            int key = array[i];        //复制 待排序元素 为哨兵  
            while(key < array[j] && j >= 0)//查找在有序表的插入位置
            {    
                array[j + 1] = array[j];  
                j--;         //元素后移  
            }  
            array[j + 1] = key;      //插入到正确位置  
        }  
        print(array, length);  //打印每趟排序的结果  
    }
    return ;  
      
} 
void test()
{
	int array[] = {3, 1, 5, 4, 2, 7, 9, 8, 0, 12, 76, 23, 38};
	int length = sizeof(array)/sizeof(int);
	print(array,length);
	straightInsertSort(array,length);//传入参量为数组地址，因此直接可以修改数组的值
	print(array,length);
}

int main(void)
{
	test();	
}