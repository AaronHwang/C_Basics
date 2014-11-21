#include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>
using namespace std;

#define TreeStackSize 10

struct BiTreeNode
{
	char data;
	BiTreeNode *Lchild, *Rchild;
};

class NodeStack//一个用于储存节点地址的栈
{
public:
	NodeStack() {top = -1;}
	~NodeStack() {};
	
	void push(BiTreeNode *root)
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

	BiTreeNode *pop(void)
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
	BiTreeNode *p[TreeStackSize];
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
			releasesBiTree(biTreeRoot);
		}
	}

	void preOrderRecursion(BiTreeNode *root);
	
	void preOrder(BiTreeNode *root)
	{
		BiTreeNode *p1 = root;
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

		void inOrder(BiTreeNode *root)
	{
		BiTreeNode *p1 = root;
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
	void levelOrder();
	void print(void);
	void print1()
	{
		cout << biTreeRoot->data << ", "<< biTreeRoot << endl;
	}

	BiTreeNode *createBiTree(BiTreeNode *root);
	void releasesBiTree(BiTreeNode *root)
	{
		if (NULL == root)
			return;
		else
		{
			releasesBiTree(root -> Lchild);
			releasesBiTree(root -> Rchild);
			delete root;
			root = NULL;
		}
	}


private:
	BiTreeNode *biTreeRoot;
	NodeStack rootstack;
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
		printf(":1、前序  2、中序  3、后序  4、层序 5、前序(非递归)?\n");
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
			
			case 5: preOrder(biTreeRoot); cout << endl; break;
			case 6: inOrder(biTreeRoot); cout << endl; break;
			// case 7: postOrder(biTreeRoot); cout << endl; break;
		}
	}
}


//test:pre-order:ABCDEFGH(ABC#D###EF##GH###),in-order:CDBAFEHG
int main(void)
{
	BiTree bitree;
	// cout << sizeof(BiTreeNode) <<", " <<sizeof(bitree) << endl;
	while(1)
	{
		bitree.print();
	}
}