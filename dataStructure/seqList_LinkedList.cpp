//搞清楚C++的一些基础知识和用法，例如重载，类中函数的互相调用，继承和派生怎么用
#include <iostream>
using namespace std;

struct node
{
	int id;
	string name;
	node *next;
};

class linkedList
{
public:
	linkedList();
	~linkedList();

	void update(int n);//更新第n个节点
	void update(string str);//更新name为str的节点，函数重载

	void deleteNode(int n);//删除第n个节点

	int locate(string str);//找到name为str的节点的位置
	string getName(int n);//得到第n个节点的name

	void insertNode();//插入n个节点

	int Length();

	void print();

	void destroy();

private:
	node *head;
};

linkedList::linkedList()
{
	head = new node;
	head ->next = NULL;
}

linkedList::~linkedList()
{
	node *p;
	while(NULL != head)
	{
		p = head;
		head = head ->next;
		delete p;
	}
}

void linkedList::update(int n)
{
	if (NULL == head || NULL == head ->next) 
		cout << "链表为空" << endl;
	else
	{
		node *p = head ->next;	
		while(p)
		{
			if (n == p->id)
			{
				p ->name += "#&@&^";
				return;
			}
			else
				p = p->next;
		}
	}
	
}

void linkedList::update(string str)
{
	if (NULL == head || NULL == head ->next) 
		cout << "链表为空" << endl;
	else
	{
		node *p = head ->next;	
		while(str != p->name)
			p = p->next;
		if (str == p->name)
		{
			p->id += 123;
			return;
		}
		else
			cout << "未找到" << endl;
	}
}

void linkedList::deleteNode(int n)
{

}

int linkedList::locate(string str)
{
	if (NULL == head || NULL == head ->next) 
		cout << "链表为空" << endl;
	else
	{
		node *p = head->next;
		while(NULL != p)
		{
			if (str == p->name)
				return p->id;
			p = p ->next;
		}

		if (NULL == p)
		{
			cout << "str" << "的数据未找到." << endl;
			return 0;
		}
	}
}

string linkedList::getName(int n)
{

}

void linkedList::insertNode()
{
	if (NULL == head || NULL == head ->next) 
		cout << "链表为空" << endl;

	int n = 0;
	node *p1 = head;
	cout << "请输入要创建数据的个数:" ;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		node *p2 = new node;
		cout << "请输入第" << i+1 << "个数据:" <<endl;
		cout << "ID:";
		cin >> p2 ->id;
		cout <<"姓名:";
		cin >>p2 ->name;
		p1 ->next = p2;
		p1 = p1 ->next;
	}
	p1 ->next = NULL;
}

int linkedList::Length()
{
	if (NULL == head || NULL == head ->next) 
	{
		cout << "链表为空" << endl;
		return 0;
	}	
	int cnt = 0;
	node *p = head;
	while(NULL != p)
	{
		cnt++;
		p = p->next;
	}

	return cnt-1;

}

void linkedList::print()
{
	if (NULL == head || NULL == head ->next) 
		cout << "链表为空" << Length() << endl;//直接调用class内的public函数
	else
	{
		cout << "链表长度为" << Length() << endl;
		node *p = head ->next;
		while(NULL != p)
		{
			cout << "ID:" << p->id <<", 姓名:" << p ->name << endl;
			p = p ->next;
		}
	}

}

void linkedList::destroy()
{

}

int main(void)
{
	linkedList List1;
	List1.print();
	List1.insertNode();
	List1.print();
	string str = "李丹青";
	cout << "李丹青的ID是:" << List1.locate(str) << endl;
	cout << List1.Length() << endl;
	List1.update(2);
	List1.print();
	List1.update("黄奕龙");
	List1.print();
	List1.~linkedList();
	List1.print();
}