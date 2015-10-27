#include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>
using namespace std;

#define TreeStackSize 10
#define TreeQueueSize 50

struct BiTreeNode//二叉树的基本节点结构
{
	char data;
	BiTreeNode *Lchild, *Rchild;
};

class NodeQueue
{
public:
	NodeQueue()
	{
		front = 0;
		rear = 0;
	}
	~NodeQueue(){}

	int front, rear;

	void enQueue(BiTreeNode *root)//从队尾入队
	{
		if (TreeQueueSize - 1 == rear)
		{
			printf("Queue is Full!\n");
		}
		else
		{
			p[++rear] = root;
		}
	}

	BiTreeNode *deQueue()//从队头出队
	{
		if (front == rear)
		{	
			printf("Queue is Empty!\n");
			return NULL;
		}
		else
		{
			return p[++front];
		}
	}


private:
	BiTreeNode *p[TreeQueueSize];

};

class NodeStack//一个用于储存parent和ancestor节点地址的栈
{
public:
	NodeStack() {top = -1;}
	~NodeStack() {};
	
	void push(BiTreeNode *root)//入栈操作
	{
		if (TreeStackSize - 1 == top)
		{
			printf("NodeStack is full!\n");
		}
		else
		{
			p[++top] = root;
		}
	}

	BiTreeNode *pop(void)//出栈操作
	{
		if (-1 == top)
		{
			printf("NodeStack is empty!\n");
			return NULL;
		}
		else
		{
			return p[top--];
		}
	}

	int top;


private:
	BiTreeNode *p[TreeStackSize];//指针数组作为栈的实现结构
};

class BiTree
{
public:
	BiTree()
	{
	 	cout << biTreeRoot <<endl;
		printf("请按照前序遍历顺序输入节点(使用#代表空节点):\n");
		biTreeRoot = createBiTree(biTreeRoot);
	 	// cout << biTreeRoot <<endl;
	}
	~BiTree()
	{
		if (NULL != biTreeRoot)
		{
			releaseBiTree(biTreeRoot);
		}
	}

	void preOrderRecursion(BiTreeNode *root);
	
	void preOrder()
	{
		BiTreeNode *p1 = biTreeRoot;
		rootstack.top = -1;
		while((NULL != p1) || (rootstack.top != - 1))
		{
			while(NULL != p1)
			{
				cout << p1 ->data << " ";
				rootstack.push(p1);
				p1 = p1 ->Lchild;
			}
			if (rootstack.top != - 1)
			{
				p1 = rootstack.pop();
				p1 = p1 ->Rchild;
			}

		}
		cout << rootstack.top << endl;
	}

		void inOrder()
	{
		BiTreeNode *p1 = biTreeRoot;
		rootstack.top = -1;
		while((NULL != p1) || (rootstack.top != - 1))
		{
			while(NULL != p1)
			{
				rootstack.push(p1);
				p1 = p1 ->Lchild;
			}
			if (rootstack.top != - 1)
			{
 				p1 = rootstack.pop();
				cout << p1 ->data << " ";
				p1 = p1 ->Rchild;
			}

		}
		cout << rootstack.top << endl;
	}
	
	void inOrderRecursion(BiTreeNode *root);
	void postOrderRecursion(BiTreeNode *root);
	void postOrder();
	void levelOrder(BiTreeNode *root)//层序遍历
	{
		BiTreeNode *tmp = NULL;

		rootqueue.front = 0;
		rootqueue.rear = 0;

		if (NULL == root)
		{
			return;
		}
		else
		{
			rootqueue.enQueue(root);

			while(rootqueue.front != rootqueue.rear)//当队不为空
			{
				tmp = rootqueue.deQueue();
				cout << tmp ->data << " ";
				if (NULL != tmp ->Lchild)
				{
					rootqueue.enQueue(tmp ->Lchild);
				}
				if (NULL != tmp ->Rchild)
				{
					rootqueue.enQueue(tmp ->Rchild);
				}
			}
		}
		printf("\n%d, %d\n", rootqueue.front, rootqueue.rear);
		rootqueue.front = 0;
		rootqueue.rear = 0;

	}
	void print(void);
	void draw(void)//图形描绘二叉树
	{
		
	}

	BiTreeNode *createBiTree(BiTreeNode *root);
	void releaseBiTree(BiTreeNode *root)
	{
		if (NULL == root)
			return;
		else
		{
			releaseBiTree(root -> Lchild);
			releaseBiTree(root -> Rchild);
			delete root;
			root = NULL;
		}
	}


private:
	BiTreeNode *biTreeRoot;
	NodeStack rootstack;
	NodeQueue rootqueue;
};


BiTreeNode *BiTree::createBiTree(BiTreeNode *root)
{
	char ch;
	cin >> ch;
	if ('#' == ch)
	 {
	 	// cout << "空节点, " << root <<endl;
	 	// cout << "头结点地址:"<< biTreeRoot << endl;
	 	return NULL;
	 } 
	else
	{
		root = new BiTreeNode;//注意要分配节点空间
		root -> data = ch;
	 	// cout << "节点为" << root->data << ", " << root <<endl;
	 	// cout << "头结点地址:"<< biTreeRoot << endl;
		root ->Lchild = createBiTree(root -> Lchild);
		root ->Rchild = createBiTree(root -> Rchild);
		return root;
	}
}

void BiTree::preOrderRecursion(BiTreeNode *root)
{
	if (NULL == root) return;
	else
	{
		cout << root -> data << " ";
		preOrderRecursion(root ->Lchild);
		preOrderRecursion(root ->Rchild);
	}
}

void BiTree::inOrderRecursion(BiTreeNode *root)
{
	if (NULL == root) return;
	else
	{
		inOrderRecursion(root ->Lchild);
		cout << root -> data << " ";
		inOrderRecursion(root ->Rchild);
	}
}

void BiTree::postOrderRecursion(BiTreeNode *root)
{
	if (NULL == root) return;
	else
	{
		postOrderRecursion(root ->Lchild);
		postOrderRecursion(root ->Rchild);
		cout << root -> data << " ";
	}
}

void BiTree::print(void)
{
	if (NULL == biTreeRoot)
	{
		printf("Empty Tree!\n");
	}
	else
	{
		int choice = 0;
		printf("-------- 选择遍历二叉树的方式 --------\n");
		printf("--------      1. 前序       --------\n");
		printf("--------      2. 中序       --------\n");
		printf("--------      3. 后序       --------\n");
		printf("--------      4. 层序       --------\n");
		printf("--------   5. 前序（非递归） --------\n");
		printf("--------   6. 中序（非递归） --------\n");
		printf("--------   7. 后序（非递归） --------\n");

		cin >> choice;
		while((choice < 1) || (choice > 8))
		{
			printf("输入错误，请重新输入:\n");
			cin >> choice;
		}
		switch(choice)
		{
			case 1: preOrderRecursion(biTreeRoot); cout << endl; break;
			case 2: inOrderRecursion(biTreeRoot); cout << endl; break;
			case 3: postOrderRecursion(biTreeRoot); cout << endl; break;
			case 4: levelOrder(biTreeRoot); cout << endl; break;
			case 5: preOrder(); cout << endl; break;
			case 6: inOrder(); cout << endl; break;
			// case 7: postOrder(biTreeRoot); cout << endl; break;
		}
	}
}


//test:pre-order:ABCDEFGH(ABC#D###EF##GH###),in-order:CDBAFEHG
// 				A
// 			   / \
// 			  B   E
// 			 /   / \
// 			C   F   G
//           \     /
//            D   H
int main(void)
{
	BiTree bitree;
	// cout << sizeof(BiTreeNode) <<", " <<sizeof(bitree) << endl;
	while(1)
	{
		bitree.print();
	}
}