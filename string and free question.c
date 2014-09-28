#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *s = malloc(sizeof(char));//size of memory allocated?
	scanf("%s",s);
	free(s);//free's location question?
	printf("%s\n", s);
	printf("%zu\n", strlen(s));

	char ch[]="This is really a long sentence.";
	s = ch;
	printf("%s\n", s);
	printf("%zu\n", strlen(s));

}
