#include <iostream>
#include <stdio.h>
using namespace std;

#define N 10

class recursionHanoi
{
public:
	recursionHanoi()
	{
		for (int i = 0; i < N; i++)
		{
			A[i] = i + 1;
			B[i] = 0;
			C[i] = 0;
		}

		print();
		HanoiMove(N, A, B, C);
	}
	~recursionHanoi(){};

	void move(int a[],int b[])
	{
		int tmp, i = 0;
		while(i < N)
		{
			if (0 != a[i])
			{
				tmp = a[i];
				a[i] = 0;
				break;
			}
			else i++;
		}
		i = N - 1;
		while(i >= 0)
		{
			if (0 == b[i])
			{
				b[i] = tmp;
				break;
			}
			else i--;
		}

	}

	void print();

	void HanoiMove(int n, int a[], int b[], int c[]);

private:
	int A[10],B[10],C[10];

};

void recursionHanoi::print()
{
	for (int i = 0; i < N; i++)
	{
		printf("    %3d    %3d    %3d\n", A[i], B[i], C[i]);
	}

	printf("\n");
}

void recursionHanoi::HanoiMove(int n, int a[], int b[], int c[])
{	
	if (1 == n) 
	{
		move(a, c);
		print();
	}
	else
	{
		HanoiMove(n-1, a, c, b);
		move(a, c);
		print();
		HanoiMove(n-1, b, a, c);
	}
}

int main(void)
{
	recursionHanoi Hanoi;
}