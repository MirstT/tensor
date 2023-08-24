
#include<iostream>
using namespace std;

int main() {
	int a[3][2] = { 0 }, b[3][2] = { 0 };
	int* p1, * p2 = nullptr;
	p1 = new int[6];//开辟动态内存区
	p2 = new int[6];//开辟动态内存区
	cout << "规定两个三行二列的矩阵相加\n请输入第一个矩阵的6个数:" << endl;
	for (p1 = a[0]; p1 < a[0] + 6; p1++) {
		cin >> *p1;
	}
	cout << "请输入第二个矩阵的6个数:" << endl;
	for (p2 = b[0]; p2 < b[0] + 6; p2++) {
		cin >> *p2;
	}
	cout << "两个矩阵相加后为：" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << *(*(a + i) + j) + *(*(b + i) + j) << "    ";
			if (j == 1 || j == 3) {
				cout << "\n";
			}
		}
	}
	delete[]p1, delete[]p2;//如果这行去掉，就不会出现最后那个错误提示窗口了！！！但这个错误并不影响打印矩阵，目标还是实现了。
}