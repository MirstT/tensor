#include <iostream>
#include <vector>
using namespace std;
#include <stdlib.h>
#include <time.h>


vector<int> getRandMatrixByShape(vector<int> shape) {

	/*定义得到矩阵所有元素的个数的函数，（所有元素的个数通
	过矩阵各个维度的大小相乘来得到*/

	vector<int> matrix;
	int matrixSize = 1;
	for (unsigned int i = 0; i < shape.size(); i++) { //将i定义为无符号整形的变量，否则编译器会报错
		matrixSize *= shape[i];
	}
	for (int j = 0; j < matrixSize; j++) {
		int randomData = rand() % 100;
		matrix.push_back(randomData);
	}
	return matrix;
}

vector<int> addMatrix(vector<int> matrix1, vector<int> matrix2) {
	vector<int> matrixSum(matrix1.size());
	for (unsigned int i = 0; i < matrix1.size(); i++) {
		matrixSum[i] = matrix1[i] + matrix2[i];
	}
	return matrixSum;
}

void printMatrix(string matrixName) {
	cout << "-------------------------------| " << matrixName << " |-------------------------------" << endl;
}

void printMatrix(vector<int> matrix, vector<int> shape) {
	printMatrix("Matrix");
	for (unsigned int i = 1; i <= matrix.size(); i++) {
		cout << matrix[i - 1] << "  ";
		int t = shape[shape.size() - 1];
		for (unsigned int j = shape.size(); j >= 2; j--) {
			if (i % t == 0) {
				cout << "\n";
				if (j <= shape.size() - 1) {
					printf("~~~|%d维分界线|~~~\n", shape.size() - j + 2);

					/*举例说明：在一个三维矩阵中因为多个二维矩阵可以直接在屏幕上打印出来，中间也只需要
					换行符标明多个二维矩阵的界限，但三维矩阵是由多个二维矩阵组成，如果只用换行符表明，
					那么三维的大小也很难在屏幕上看出来，所以最后加个某维的分界线来表明矩阵各个维度的大小
					这个地方的代码也许有些乱和复杂，但最终确实能实现打印各个维度分界线的效果*/

				}
				t *= (shape[j - 2]);
			}
		}
	}
}

int judgeCin() {
	int a;
	cin >> a;
	while (a <= 1 || a >= 11) { //判断输入的列数是否有误
		cout << "输入有错误，请重新输入新的取值=";
		fflush(stdin); //清空输入缓冲区
		cin >> a;
	}
	return a;
}

vector<int> getMatrixDimension() { //定义得到矩阵各个维度大小的函数
	int d = judgeCin();
	vector<int> dimension;
	for (int i = d; i >= 1; i--) {
		printf("请输入第%d维度的大小=", i);
		int t = judgeCin();
		dimension.push_back(t);
	}
	return dimension;
}

int main() {

	srand((unsigned)time(NULL));
	cout << "规定两个n维矩阵相加(注意：所有需要输入的数的取值范围是1至10.)\n请输入矩阵维度的大小d=";
	vector<int> shape = getMatrixDimension();

	vector<int> matrix1 = getRandMatrixByShape(shape);
	printMatrix(matrix1, shape);

	vector<int> matrix2 = getRandMatrixByShape(shape);
	printMatrix(matrix2, shape);

	cout << "\n相加后的矩阵为：" << endl;
	vector<int> matrixSum = addMatrix(matrix1, matrix2);
	printMatrix(matrixSum, shape);

	return -1;
}