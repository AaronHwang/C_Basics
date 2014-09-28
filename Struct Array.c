#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int id;
	char name[15];
	char hometown[10];
}
student;

int main(void)
{
	student stud[3];
	for (int i = 0; i < 3; i++)
		{
			printf("请输入第%d个学生的ID：",i+1);
			scanf("%d",&stud[i].id);
			printf("请输入第%d个学生的姓名：",i+1);
			scanf("%s",stud[i].name);
			printf("请输入第%d个学生的家乡：",i+1);
			scanf("%s",stud[i].hometown);
			printf("\n");
		}
	printf("\n");

	for (int i = 0; i < 3; ++i)
		{
			printf("%-3d", stud[i].id);
			printf("%-15s", stud[i].name);
			printf("%-10s\n", stud[i].hometown);
		}	
	return 0;
}