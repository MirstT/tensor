#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
int main()
{
	int i, j;
	int a[3][2];


	int b[3][2];
	int c[3][2];
	printf("规定两个3行2列矩阵相加\n\n");

	printf("请输入第一个矩阵的元素：\n");
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 1; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	printf("\n");

	printf("第1个矩阵为:\n");
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 1; j++)
		{
			printf("%d  ", a[i][j]);
			if (j == 1)
			{
				printf("\n");
			}
		}
	}
	printf("\n");

	printf("请输入第二个矩阵的元素：\n");
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 1; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}
	printf("\n");

	printf("第2个矩阵为:\n");
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 1; j++)
		{
			printf("%d  ", b[i][j]);
			if (j == 1)
			{
				printf("\n");
			}
		}
	}
	printf("\n");


	printf("这两个矩阵相加的结果如下:\n");
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 1; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
			printf("%d  ", c[i][j]);
			if (j == 1)
			{
				printf("\n");
			}
		}
	}
	return 0;
}