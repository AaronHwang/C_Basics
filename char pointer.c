#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *s;
	s="This is a char pointer.";//字符指针赋值
	printf("\n%s\n",s);
	
	char ch[]="This is also a char pointer.";//字符数组
	printf("\n%s\n", ch);
	s = ch;//都是地址
	printf("\n%s\n", s);

	for (int i = 0; i < strlen(ch); i++)
	{	
		printf("%c   ", ch[i]);//注意是%c
		printf("%s   ", ch + i);//注意是%s，不能是%c
		printf("%s   \n", s + i);//注意是%s
	}
	return 0;
}
