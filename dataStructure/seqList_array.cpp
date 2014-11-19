#include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>
using namespace std;

const int maxSize = 20;

template<class T>//定义模板类
class seqList
{
public:
	seqList()//无参构造函数
	{
		length = 0;
	}

	seqList(T a[],int n)//有参构造函数，重载构造函数
{
	if (n > maxSize) 
		throw "参数非法";

	for (int i = 0; i < n; i++)
		data[i] = a[i];

	length = n;
}

	~seqList(){};//析构函数为空
	
	int dataLength()
	{
		return length;
	}

	T getData(int i);//获取第i个节点的数据
	int locateData(T x);
	void insertData();
	T deleteData(int i);
	void printList();

private:
	T data[maxSize];
	int length;

};

template<class T>
void seqList<T>::printList()
{
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << endl;
	}
}



int main(void)
{
	string a[] = {"123","234","632716537621"};
	seqList<string> node(a,3);
	node.printList();

}