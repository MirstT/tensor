#include <iostream>
#include <vector>
using namespace std;
#include <stdlib.h>                          //程序中用到了malloc函数和随机数函数，应包含stdlib.h
#include <time.h>


vector<int> getMatrixWithSizeByVector(int size) {          //定义用vector得到矩阵中各个数的大小的函数
	vector<int> matrix;
	for (int i = 0; i < size; i++) {
		int t = rand() % 100;
		matrix.push_back(t);
	}
	return matrix;
}

vector<int> matrixAdd(vector<int> matrix1, vector<int> matrix2) {  //定义让两个矩阵相加的函数
	vector<int> matrixs(matrix1.size());              //对vector进行初始化，即规定相加后的矩阵matrixs中共多少个数
	for (int i = 0; i < matrix1.size(); i++) {
		matrixs[i] = matrix1[i] + matrix2[i];
	}
	return matrixs;
}

void printMatrix(string matrixName) {
	cout << "------| " << matrixName << " |------" << endl;
}

void printMatrixWithShape(vector<int> matrix, int n) {        //定义打印矩阵形状的函数
	printMatrix("Matrix");
	for (int i = 1; i <= matrix.size(); i++) {
		cout << matrix[i - 1] << "  ";
		if (i % n == 0) {
			cout << "\n";
		}
	}
}

int judgeCinRightAndWrong() {                    //定义判断输入的数是否在规定范围内的函数
	int a;
	cin >> a;
	while (a <= 0 || a >= 11) {                    //判断输入的数是否有误
		cout << "输入有错误，请重新输入新的取值=";
		fflush(stdin);                        //清空输入缓冲区 
		cin >> a;
	}
	return a;
}

int main() {

	srand((unsigned)time(NULL));
	cout << "定两个m行n列的矩阵相加(注意：m和n的取值范围是1至10.)\n请输入行数m=";
	int m = judgeCinRightAndWrong();
	cout << "请输入列数n=";
	int n = judgeCinRightAndWrong();
	int size = m * n;                        //size的含义为矩阵中共有多少个数

	vector<int> matrix1 = getMatrixWithSizeByVector(size);      //函数调用，得到matrix1
	printMatrixWithShape(matrix1, n);

	vector<int> matrix2 = getMatrixWithSizeByVector(size);      //函数调用，得到matrix2
	printMatrixWithShape(matrix2, n);

	cout << "\n两个矩阵相加后的矩阵如下：" << endl;
	vector<int> matrix3 = matrixAdd(matrix1, matrix2);        //函数调用，得到相加后的matrix3
	printMatrixWithShape(matrix3, n);

	return 0;
}
