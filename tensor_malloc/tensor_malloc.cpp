#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>                    //程序中用到了malloc函数和随机数函数，应包含stdlib.h
#include <time.h>                    //为了使程序每次运行产生的随机数不同，应包含time.h 
int main()
{
	int i, m, n, * p1, * p2;
	printf("规定两个m行n列的矩阵相加\n请输入行数m=");
	scanf("%d", &m);
	printf("请输入列数n=");
	scanf("%d", &n);
	p1 = (int*)malloc((m * n) * sizeof(int));        //开辟动态内存区，将地址转换成int*型，放在p1中 
	p2 = (int*)malloc((m * n) * sizeof(int));        //开辟动态内存区，将地址转换成int*型，放在p2中
	printf("\n生成随机数0~99后第一个矩阵的各个数是:\n");

	srand((unsigned)time(NULL));

	for (i = 1; i <= m * n; i++)
	{
		*p1 = rand() % 100;
		printf("%d  ", *p1++);
		if (i % n == 0)
		{
			printf("\n");
		}
	}

	printf("\n\n生成随机数0~99后第二个矩阵的各个数是:\n");
	for (i = 1; i <= m * n; i++)
	{
		*p2 = rand() % 100;
		printf("%d  ", *p2++);
		if (i % n == 0)
		{
			printf("\n");
		}
	}

	p1 = p1 - (m * n); p2 = p2 - (m * n);            // 重新使p1和p2指向首地址

	printf("\n\n两个矩阵相加后为:\n");        //将两个指针变量所指向的内容相加
	for (i = 1; i <= m * n; i++)
	{
		printf("%d  ", *p1 + *p2);
		p1++, p2++;
		if (i % n == 0)
		{
			printf("\n");
		}
	}
	return 0;
}