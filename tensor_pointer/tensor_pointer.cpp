// 第二版
#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<stdlib.h>                  //程序中用到了malloc函数，应包含stdlib.h 
int main()
{
	int* p1, * p2, i;
	p1 = (int*)malloc(6 * sizeof(int));      //开辟动态内存区，将地址转换成int*型，放在p1中 
	p2 = (int*)malloc(6 * sizeof(int));      //开辟动态内存区，将地址转换成int*型，放在p2中 
	printf("规定两个三行二列的矩阵相加\n请输入第一个矩阵的6个数:\n");
	for (i = 0; i < 6; i++)
	{
		scanf("%d", p1++);
	}
	printf("请输入第二个矩阵的6个数:\n");
	for (i = 0; i < 6; i++)
	{
		scanf("%d", p2++);
	}
	for (i = 5; i >= 0; i--)              // 重新使p1和p2指向首地址 
	{
		--p1;
		--p2;
	}

	printf("两个矩阵相加后为:\n");        //将两个指针所指向的内容相加 
	for (i = 0; i < 6; i++)
	{
		printf("%d  ", *p1 + *p2);
		p1++;
		p2++;
		if (i == 1 || i == 3)
		{
			printf("\n");
		}
	}
	return 0;
}