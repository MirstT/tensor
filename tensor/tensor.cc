#include <iostream>
#include <vector>
using namespace std;
#include <stdlib.h>            //程序中用到了malloc函数和随机数函数，应包含stdlib.h
#include <time.h>

vector<int> getMatrixSize(int size) {
	vector<int> matrix;
	for (int i = 0; i < size; i++) {
		int t = rand() % 100;
		matrix.push_back(t);
	}
	return matrix;
}

vector<int> matrixAdd(vector<int> matrix1, vector<int> matrix2) {
	vector<int> matrixsum(matrix1.size());            //matrixsum的意思是矩阵相加后的总和
	for (int i = 0; i < matrix1.size(); i++) {
		matrixsum[i] = matrix1[i] + matrix2[i];
	}
	return matrixsum;
}

void printMatrix(string matrixName) {
	cout << "------| " << matrixName << " |------" << endl;
}

void printMatrixShape(vector<int> matrix, int m, int n) {
	printMatrix("Matrix");
	for (int i = 1; i <= matrix.size(); i++) {
		cout << matrix[i - 1] << "  ";
		if (i % n == 0) {                    //打印出三维矩阵中二维矩阵的形状
			cout << "\n";
		}
		if (i % (m * n) == 0) {                  //打印出三维矩阵的形状
			cout << "\n";
		}
	}
}

int judgeCin() {
	int a;
	cin >> a;
	while (a <= 0 || a >= 11) {                  //判断输入的列数是否有误
		cout << "输入有错误，请重新输入新的取值=";
		fflush(stdin);                      //清空输入缓冲区 
		cin >> a;
	}
	return a;
}

int main() {

	srand((unsigned)time(NULL));
	cout << "定两个l层m行n列的矩阵相加(注意：l和m和n的取值范围是1至10.)\n请输入层数l=";
	int l = judgeCin();
	cout << "请输入行数n=";
	int m = judgeCin();
	cout << "请输入列数n=";
	int n = judgeCin();
	int size = l * m * n;

	vector<int> matrix1 = getMatrixSize(size);
	printMatrixShape(matrix1, m, n);

	vector<int> matrix2 = getMatrixSize(size);
	printMatrixShape(matrix2, m, n);

	cout << "\n相加后的矩阵为：" << endl;
	vector<int> matrixsum = matrixAdd(matrix1, matrix2);
	printMatrixShape(matrixsum, m, n);

	return 0;
}