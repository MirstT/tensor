#include <iostream>
#include <vector>
using namespace std;
#include <stdlib.h>
#include <time.h>


class Matrix {
public:
	vector<int> dimension_;// 矩阵各个维度大小
	vector<int> matrix_;//矩阵中的所有的数


	int judge_cin() {
		int a;
		cin >> a;
		while (a <= 1 || a >= 11) { //判断输入的列数是否有误
			cout << "输入有错误，请重新输入新的取值=";
			fflush(stdin); //清空输入缓冲区
			cin >> a;
		}
		return a;
	}

	void get_matrix_dimension() { //定义得到矩阵各个维度大小的函数
		int d = judge_cin();
		//vector<int> dimension;
		for (int i = d; i >= 1; i--) {
			printf("请输入第%d维度的大小=", i);
			int t = judge_cin();
			dimension_.push_back(t);
		}
	}

	vector<int> get_rand_matrix_by_dimension() {

		/*定义得到矩阵所有元素的个数的函数，（所有元素的个数通
		过矩阵各个维度的大小相乘来得到*/

		vector<int> matrix;
		int matrixSize = 1;
		for (unsigned int i = 0; i < dimension_.size(); i++) { //将i定义为无符号整形的变量，否则编译器会报错
			matrixSize *= dimension_[i];
		}
		for (int j = 0; j < matrixSize; j++) {
			int randomData = rand() % 100;
			matrix.push_back(randomData);
		}
		return matrix;
	}

	vector<int> add_matrix(vector<int> matrix1, vector<int> matrix2) {
		vector<int> matrix_sum(matrix1.size());
		for (unsigned int i = 0; i < matrix1.size(); i++) {
			matrix_sum[i] = matrix1[i] + matrix2[i];
		}
		return matrix_sum;
	}

	void print_matrix(string matrixName) {
		cout << "-------------------------------| " << matrixName << " |-------------------------------" << endl;
	}

	void print_matrix(vector<int> matrix) {
		print_matrix("Matrix");
		for (unsigned int i = 1; i <= matrix.size(); i++) {

			/*我先用debug去调试，最终发现打印这个地方出了一个小问题，原先wolai失败的第八版里，在上面这个for循环里，我把i的跳出循
			环的判断条件写的是 i <= dimension_，其实应该是 i <= matrix.size()所以打印矩阵这个地方出了一个小问题，然后我继续用
			debug去调试，但还是没解决，最后我对比原来第七版才发现问题，这才解决了，原先失败的第八版出现这种低级错误，第一是因为不
			能十分集中注意力，第二是总觉得打印这个地方没有问题。*/

			cout << matrix[i - 1] << "  ";
			int t = dimension_[dimension_.size() - 1];
			for (unsigned int j = dimension_.size(); j >= 2; j--) {
				if (i % t == 0) {
					cout << "\n";
					if (j <= dimension_.size() - 1) {
						printf("~~~|%d维分界线|~~~\n", dimension_.size() - j + 2);

						/*举例说明：在一个三维矩阵中因为多个二维矩阵可以直接在屏幕上打印出来，中间也只需要
						换行符标明多个二维矩阵的界限，但三维矩阵是由多个二维矩阵组成，如果只用换行符表明，
						那么三维的大小也很难在屏幕上看出来，所以最后加个某维的分界线来表明矩阵各个维度的大小
						*/

					}
					t *= (dimension_[j - 2]);
				}
			}
		}
	}
};

int main() {

	Matrix matrix1, matrix2, matrix_sum;//通过矩阵类，创建矩阵的对象
	srand((unsigned)time(NULL));//注意这个其实不应该在放到主函数里,这个应该放到上面生成随机数的函数里，但暂时没想到方法

	cout << "规定两个n维矩阵相加(注意：所有需要输入的数的取值范围是1至10.)\n请输入矩阵维度的大小d=";

	matrix1.get_matrix_dimension();//得到matrix1的维度
	matrix2.dimension_ = matrix1.dimension_;//令matrix2的维度和matrix1的维度相等
	matrix_sum.dimension_ = matrix1.dimension_;//令matrix_sum的维度和matrix1的维度相等

	matrix1.matrix_ = matrix1.get_rand_matrix_by_dimension();//填充矩阵对象matrix1中的所有的数
	matrix2.matrix_ = matrix2.get_rand_matrix_by_dimension();//填充矩阵对象matrix2中的所有的数
	matrix_sum.matrix_ = matrix_sum.add_matrix(matrix1.matrix_, matrix2.matrix_);//通过matrix1和matrix2相加，得到矩阵对象matrix_sum中的所有的数

	matrix1.print_matrix(matrix1.matrix_);//打印matrix1中的所有的数
	matrix2.print_matrix(matrix2.matrix_);//打印matrix2中的所有的数

	cout << "\n相加后的矩阵为：" << endl;
	matrix_sum.print_matrix(matrix_sum.matrix_);//打印matrix_sum中的所有的数

	return -2;
}