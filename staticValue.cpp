#include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>
using namespace std;

static int value = 10;

void func(void)
{
	printf("value = %d\n", value);
	value /= 5;
}

int main(void)
{
	func();
	printf("value = %d\n", value);
	value += 20;
	// printf("value = %d\n", value);
	func();
	printf("value = %d\n", value);
}