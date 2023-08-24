#include<stdio.h>
int main()
{
	int i, j;
	int a[3][2] = { {1,3},{1,0},{1,2} };
	int b[3][2] = { {0,0},{7,5},{2,1} };
	int c[3][2];
	printf("规定两个3行2列矩阵相加\n\n");

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