#include <iostream>
#include <vector>
using namespace std;
#include <stdlib.h>
#include <time.h>

class Matrix {
public:
	vector<int> dimension_;// 矩阵各个维度大小
	vector<int> matrix_;//矩阵中的所有的数


	void print_matrix(string matrixName) {
		static int counter = 0;

		/*counter只是一个计数器，这样就能更清晰地看到相加后的矩阵的位置，同时主函数里
		就不需要在写“cout << "\n相加后的矩阵为：" << endl;”这句代码了*/

		counter++;
		if (counter == 3) {
			cout << "-------------------------------| " << "相加后的矩阵如下" << " |---------------------" << endl;
		}
		cout << "-------------------------------| " << matrixName << " |-------------------------------" << endl;
	}

	void print_matrix() {
		print_matrix("Matrix");
		for (unsigned int i = 1; i <= matrix_.size(); i++) {
			cout << matrix_[i - 1] << "  ";
			int t = dimension_[dimension_.size() - 1];
			for (unsigned int j = dimension_.size(); j >= 2; j--) {
				if (i % t == 0) {
					cout << "\n";
					if (j <= dimension_.size() - 1) {
						printf("~~~|%d维分界线|~~~\n", dimension_.size() - j + 2);
					}
					t *= (dimension_[j - 2]);
				}
			}
		}
	}

	void add_matrix(vector<int> matrix1, vector<int> matrix2) {
		for (unsigned int i = 0; i < matrix1.size(); i++) {
			matrix_.push_back(matrix1[i] + matrix2[i]);
		}
	}

	void get_rand_matrix_by_dimension() {
		vector<int> matrix;
		int matrixSize = 1;
		for (unsigned int i = 0; i < dimension_.size(); i++) {
			matrixSize *= dimension_[i];
		}
		for (int j = 0; j < matrixSize; j++) {
			int randomData = rand() % 100;
			matrix_.push_back(randomData);
		}
	}

	int judge_cin() {
		int a;
		cin >> a;
		while (a <= 1 || a >= 11) {
			cout << "输入有错误，请重新输入新的取值=";
			fflush(stdin);
			cin >> a;
		}
		return a;
	}

	void get_matrix_dimension() { //定义得到矩阵各个维度大小的函数
		cout << "规定两个n维矩阵相加(注意：所有需要输入的数的取值范围是1至10.)\n请输入矩阵维度的大小d=";
		int d = judge_cin();
		for (int i = d; i >= 1; i--) {
			printf("请输入第%d维度的大小=", i);
			int t = judge_cin();
			dimension_.push_back(t);
		}
	}
};

int main() {

	Matrix matrix1, matrix2, matrix_sum;
	srand((unsigned)time(NULL));//注意这个其实不应该在放到主函数里,这个应该放到上面生成随机数的函数里，但暂时没想到方法

	matrix1.get_matrix_dimension();
	matrix2.dimension_ = matrix1.dimension_;
	matrix_sum.dimension_ = matrix1.dimension_;

	matrix1.get_rand_matrix_by_dimension();
	matrix2.get_rand_matrix_by_dimension();

	matrix_sum.add_matrix(matrix1.matrix_, matrix2.matrix_);//这行暂时还没想到省去里面参数的方法

	matrix1.print_matrix();
	matrix2.print_matrix();
	matrix_sum.print_matrix();
}