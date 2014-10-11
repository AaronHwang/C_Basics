/*...
malloc 和free 一定要成对出现配套使用，否则会出现内存泄露
...*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5

int main(void)
{
	char *s = NULL;//声明并指向空是好习惯，NULL实际上是指针类型，(void *) 0	
	s = (char *)malloc(sizeof(char)*(N+1));//malloc返回的数据类型是(void *)，但是强制转换类型是个好习惯，另外多分配一个字节可以用于存储'\0'	
	scanf("%s", s);//分配内存后可以赋值
	printf("%s\n", s);
	s[1] = 'A';
	printf("%s\n", s);
	s[3] = '\0';
	printf("%s\n", s);
	s = NULL;//再次指向空防止后面误用这个指针
	free(s);//使用完成之后释放内存

}
