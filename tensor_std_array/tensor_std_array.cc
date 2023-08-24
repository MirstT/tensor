//------------------------------------------------------
//  禁止使用与堆区内存相关的操作，比如 malloc,new,std::vector等
//  禁止新增与全局区内存相关的操作，比如 全局变量,static 等
//------------------------------------------------------
#include<iostream>
#include<array>

constexpr int kCol{ 2 };
constexpr int kRow{ 3 };
using Matrix = std::array<std::array<int, kCol>, kRow>;

int main() {


	Matrix matrix1{};
	Matrix matrix2{};
	Matrix matrix_sum{};


	std::cout << "第一个矩阵为\n";
	matrix1 = PopulateRandomDataByValue(matrix1);
	//PopulateRandomDataByPointer(&matrix1);
	//PopulateRandomDataByReference(matrix1);
	Print(matrix1);

	std::cout << "第二个矩阵为\n";
	matrix2 = PopulateRandomDataByValue(matrix2);
	//PopulateRandomDataByPointer(&matrix2);
	//PopulateRandomDataByReference(matrix2);
	Print(matrix2);

	std::cout << "相加后的矩阵为\n";
	matrix_sum = AddByValue(matrix1, matrix2);
	//AddByPointer(&matrix_sum, &matrix1, &matrix2);
	//AddByReference(matrix_sum, matrix1, matrix2);
	Print();
}

PopulateRandomDataByValue() {};
PopulateRandomDataByPointer() {};
PopulateRandomDataByReference() {};

AddByValue() {};
AddByPointer() {};
AddByReference() {};

Print() {};
