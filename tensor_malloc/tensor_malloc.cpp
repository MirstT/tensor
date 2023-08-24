#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>                      //程序中用到了malloc函数和随机数函数，应包含stdlib.h
#include <time.h>                      //为了使程序每次运行产生的随机数不同，应包含time.h 
int main()
{
	void tianchong(int* po, int m, int n);        //声明给矩阵填入各个数的函数 
	void add(int* x, int* y, int m, int n);        //声明两个矩阵相加的函数 
	int i, * p1, * p2, * p3;
	int m, n;
	printf("规定两个m行n列的矩阵相加(注意：m和n的取值范围是1至10.)\n请输入行数m=");
	scanf("%d", &m);

	while (m <= 0 || m >= 11)                  //判断输入的行数是否有误 
	{
		printf("行数输入有错误，请重新输入行数m=");
		fflush(stdin);                //清空输入缓冲区 
		scanf("%d", &m);
	}
	printf("请输入列数n=");
	scanf("%d", &n);
	while (n <= 0 || n >= 11)                  //判断输入的列数是否有误 
	{
		printf("行数输入有错误，请重新输入行数n=");
		fflush(stdin);                //清空输入缓冲区 
		scanf("%d", &n);
	}

	p1 = (int*)malloc((m * n) * sizeof(int));        //开辟动态内存区，将地址转换成int*型，放在p1中 
	p2 = (int*)malloc((m * n) * sizeof(int));        //开辟动态内存区，将地址转换成int*型，放在p2中
	p3 = (int*)malloc((m * n) * sizeof(int));
	srand((unsigned)time(NULL));

	for (i = 1; i <= m * n; i++)                //让这两个矩阵的各个数的初始数为0 
	{
		*p1 = 0, p1++;
		*p2 = 0, p2++;
	}

	printf("\n生成随机数0~99后第一个矩阵的各个数是:\n");
	tianchong(p1, m, n);                  //函数调用 
	printf("\n\n生成随机数0~99后第二个矩阵的各个数是:\n");
	tianchong(p2, m, n);                  //函数调用 
	printf("\n\n两个矩阵相加后为:\n");
	add(p1, p2, m, n);                     //函数调用
}

void add(int* x, int* y, int m, int n)              //定义两个矩阵相加的函数
{
	int i;
	for (i = 1; i <= m * n; i++)
	{
		printf("%d  ", *x + *y);
		x++, y++;
		if (i % n == 0)
		{
			printf("\n");
		}
	}
}

void tianchong(int* po, int m, int n)              //定义给矩阵填入各个数的函数
{
	int i;
	for (i = 1; i <= m * n; i++)
	{
		*po = rand() % 100;
		printf("%d  ", *po++);
		if (i % n == 0)
		{
			printf("\n");
		}
	}
}

