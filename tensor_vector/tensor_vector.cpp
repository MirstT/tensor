#include<iostream>
using namespace std;
#include<vector>
#include <stdlib.h>                      //程序中用到了malloc函数和随机数函数，应包含stdlib.h
#include <time.h>

int m, n, t = 0;                        //定义全局变量m，n，t 

void tianchong(int a[])                    //声明给矩阵填入各个数的函数 
{
	vector<int>v0;                      //创建一个vector容器 
	for (int i = 1; i <= m * n; i++)
	{
		t = rand() % 100;
		v0.push_back(t);                  //向容器中插入随机数 
		cout << v0[i - 1] << "  ";
		if (i % n == 0)
		{
			cout << "\n";
		}
		a[i - 1] = v0[i - 1];
	}
}

void add(int* x, int* y)                    //声明让两个矩阵相加的函数 
{
	for (int i = 1; i <= m * n; i++)
	{
		cout << x[i - 1] + y[i - 1] << "  ";
		if (i % n == 0)
		{
			cout << "\n";
		}
	}
}


int main()
{
	srand((unsigned)time(NULL));
	cout << "定两个m行n列的矩阵相加(注意：m和n的取值范围是1至10.)\n请输入行数m=";
	cin >> m;
	while (m <= 0 || m >= 11)                    //判断输入的行数是否有误 
	{
		cout << "行数输入有错误，请重新输入行数m=";
		fflush(stdin);                    //清空输入缓冲区 
		cin >> m;
	}
	cout << "请输入列数n=";
	cin >> n;
	while (n <= 0 || n >= 11)                    //判断输入的列数是否有误 
	{
		cout << "行数输入有错误，请重新输入行数n=";
		fflush(stdin);                    //清空输入缓冲区 
		cin >> n;
	}

	int* v1, * v2;
	v1 = (int*)malloc((m * n) * sizeof(int));
	v2 = (int*)malloc((m * n) * sizeof(int));
	cout << "\n生成随机数0~99后第一个矩阵的各个数是:\n";
	tianchong(v1);                      //函数调用 
	cout << "\n生成随机数0~99后第二个矩阵的各个数是:\n";
	tianchong(v2);                      //函数调用    
	cout << "\n\n两个矩阵相加后为:\n";
	add(v1, v2);                        //函数调用 
}