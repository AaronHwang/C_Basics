#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

typedef struct student//设计链表的数据结构
{
	int id;
	string name;
	student *next;
}node;

node *creat()//新建链表
{
	node *head = NULL, *p = NULL, *s = NULL;
	int x, cycle = 1;
	head = (node *)malloc(sizeof(node));
	p = head;

	while(cycle)//当输入为0时结束录入新数据
	{
		printf("\nPlease input ID：");
		scanf("%d", &x);
		if (x != 0)
		{
			s = (node *)malloc(sizeof(node));
			cout<<"Please input name:";
			s ->id = x;
			cin >> s ->name;
			p ->next = s;
			p = s;
		}
		else
			cycle = 0;
	}

	s = head;//取原始头结点地址
	head = head ->next;//头结点后移一位到有数据的节点上
	s ->next = NULL;//断开原始头结点
	p ->next = NULL;//尾节点指向空表示结束
	free(s);//free原始头结点的内存
//	printf("\n yyy %d \n", head -> id);//head指针指向第一个节点
	return head; 
}

node *insertnode(node *head)//插入新节点
{
	if (NULL != head)
	{
		node *p1, *p2, *p0;
		p1 = head;
		p0 = (node *)malloc(sizeof(node));
		cout << "Please input a new ID you want to add：";
		cin >> p0 ->id ;
		cout << "Please input his/her name：";
		cin >> p0 ->name ;

		while((p1 ->id < p0 ->id)&&(NULL != p1 ->next))
		{
			p2 = p1;
			p1 = p1 ->next;
		}

		if (p1 ->id == p0 ->id)
		{
			cout << "ID号码已存在！"<<endl;
			return head;		
		}
		else if (p1 == head)//考虑头结点
		{
			p0 ->next = p1;
			head = p0;
		}
		else if (NULL == p1 ->next)//考虑尾节点
		{
			if (p0 ->id < p1 ->id)
			{
				p0 ->next = p1;
				p2 ->next = p0;
			}
			else
			{
				p1 ->next = p0;
				p0 ->next = NULL;	
			}
			
		}
		else//中间节点
		{	
			if (p0 ->id < p1 ->id)
			{
				p0 ->next = p1;
				p2 ->next = p0;
			}
			else
			{
				p2 = p1 ->next;
				p0 ->next = p2;	
				p1 ->next = p0;
			}
		}

		return head;

	}
	else
	{
		printf("Empty List!\n");
		return NULL;
	}
}

node *delet(node *head)//删除节点
{
	if (head != NULL)
	{
		int num;
		cout << "Please input the ID you want to delete：";
		cin >> num;
		node *p1 = NULL, *p2 = NULL;//地址为0
		p1 = head;
		
		while(NULL != p1 ->next && num != p1 ->id)
		{
			p2 = p1;
			p1 = p1 ->next;
		}

		if (num == p1->id)
		{
			if (NULL == p1 ->next)//先考虑尾结点
			{
				p2 ->next = NULL;
			}
			else if(p1 == head)//考虑头节点
			{
				head = head ->next;	
				p1 -> next = NULL;		
			} 
			else
			{
				p2 ->next = p1 ->next;
				p1 ->next = NULL;
			}
		}
		else
			printf("The information whose ID =%d cannot be found.\n", num);
		//这之前都不能free p1，因为还要判断

		free(p1);
		return(head);
	}
	else
	{
		printf("Empty list!\n");
		return NULL;
	}
}

int length(node *head)//测链表的长度
{
	int cnt = 0;
	node *p;//不能更改head的值
	p = head;
	while(p != NULL)
	{
		p = p ->next;
		cnt++;
	}
	return cnt;
}

void print(node *head)
{
	if (NULL != head)
	{
		int cnt = 0;
		node *p;//不能更改head的值
		p = head;
		if(head != NULL)
		{
			printf("The length of this linked list is : %d\n", length(p));

			while(p!=NULL)
			{
			//			printf("%d ", p -> id);
				cout <<p->id <<" "<< p ->name <<"; ";
				p = p ->next;
				cnt ++;
				if (0 == cnt % 5)
				{
					printf("\n");
					cnt = 0;
				}
			}
			printf("\n");
		}
		
	}
	else
		printf("Empty List!\n");
}

node *sortlistselection(node *head)
{
	if (NULL != head)
	{
		node *p1, *p2;
		int tmpid;
		string tmpname;
		int n = length(head);


		if (1 == n)//如果链表只有一个节点
			printf("Only one node in the list.\n");
		else
		{
			p1 = head;
			p2 = p1 ->next;

			for (int i = 0; i < n - 1; i ++)//selection sort way
			{
				for (int j = i + 1; j < n; j ++)
				{
					if (p1 ->id > p2 ->id)
					{
						tmpid = p1 ->id;
						tmpname = p1 ->name;
						p1 ->id = p2 ->id;
						p1 ->name = p2 ->name;
						p2 ->id = tmpid;
						p2 ->name = tmpname;
					}
					p2 = p2 ->next;
				}
				p1 = p1 ->next;
				p2 = p1 ->next;
			}
		}

		return head;
	}
	else
	{
		printf("Empty List!\n");
		return NULL;
	}
		
}

node *sortlistbubble(node *head)
{
	if (NULL != head)
	{
		node *p;
		int tmpid,flag = 1;
		string tmpname;
		int n = length(head);

		if (NULL == head ->next)//如果链表只有一个节点
			printf("Only one node in the list.\n");
		else
		{
			p = head;
			for (int i = 0; i < n - 1 && flag; i ++)//bubble sort way
			{
				p = head;
				flag = 0;

				for (int j = 0; j < n - i - 1; j ++)
				{
					if (p ->id > p ->next->id)
					{
						tmpid = p ->id;
						tmpname = p ->name;
						p ->id = p ->next ->id;
						p ->name = p ->next ->name;
						p ->next ->id = tmpid;
						p ->next ->name = tmpname;
						flag = 1;
					}
					p = p ->next;
				}
				
			}
		}

		return head;
	}
	else
	{
		printf("Empty List!\n");
		return NULL;
	}
		
}

void menu(void)
{
	cout << "==================================="<<endl;
	cout << "    1. Create a new linked list    "<<endl;
	cout << "    2. Delete a node from list     "<<endl;
	cout << "    3. Insert a node into list     "<<endl;
	cout << "    4.    sort  present list       "<<endl;
	cout << "    5.    print present list       "<<endl;
	cout << "    6.         quit                "<<endl;
	cout << "==================================="<<endl; 

}

int main(void)
{
	int choice;
	node *head = NULL;
	do
	{
		menu();
		cin >> choice;
		switch(choice)
		{
			case 1  :head = creat();print(head);break;
			case 2  :head = delet(head);print(head);break;
			case 3  :head = insertnode(head);print(head);break;
			case 4  :head = sortlistbubble(head);print(head);break;
			case 5  :print(head);break;
			default :break; 
		}
	}
	while(choice > 0 && choice < 6);
	
	
}