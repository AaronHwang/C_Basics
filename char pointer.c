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
		printf("%c   ", ch[i]);//注意是%c，不能是%s
		printf("%s   ", ch + i);//注意是%s，不能是%c
		printf("%s   \n", s + i);//注意是%s
	}

  	char *s2 = malloc((strlen(s)+1)*sizeof(char));//从堆heap分配内存并返回改内存地址
  	// char *s2 ;s2 = malloc((strlen(s)+1)*sizeof(char));
  	//同理，char *s2 = "Aaron";

  	s2 = s;//复制s赋值给s2
  	printf("%s\n", s2);

  	s2 = "Aaron";//分配内存后可以赋值
  	printf("\n%s\n", s2);

	return 0;
}
