#include<iostream>
#include<array>
using namespace std;

int main() {
	std::array<std::array<int, 2>, 3> matrix1 = { 1,3,1,0,1,2 };
	std::array<std::array<int, 2>, 3> matrix2 = { 0,0,7,5,2,1 };
	cout << "第一个矩阵为" << endl;
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 1; j++) {
			cout << matrix1[i][j] << "  ";
			if (j == 1) {
				cout << endl;
			}
		}
	}
	cout << "第二个矩阵为" << endl;
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 1; j++) {
			cout << matrix2[i][j] << "  ";
			if (j == 1) {
				cout << endl;
			}
		}
	}
	cout << "相加后的矩阵为" << endl;
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 1; j++) {
			cout << matrix1[i][j] + matrix2[i][j] << "  ";
			if (j == 1) {
				cout << endl;
			}
		}
	}
}