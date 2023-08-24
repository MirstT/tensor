//------------------------------------------------------
//  禁止使用 std::array
//  禁止使用与堆区内存相关的操作，比如 malloc,new,std::vector等
//  禁止使用与全局区内存相关的操作，比如 全局变量,static 等
//------------------------------------------------------
#include<iostream>
int main()
{
	constexpr int col{ 2 };
	constexpr int row{ 3 };

	int matrix1[row][col]{};
	int matrix2[row][col]{};
	int matrix_sum[row][col]{};

	std::cout << "第一个矩阵为\n";
	PopulateRandomDataByPointer(&matrix1);
	//PopulateRandomDataByReference(matrix1);
	Print(matrix1);

	std::cout << "第二个矩阵为\n";
	PopulateRandomDataByPointer(&matrix2);
	//PopulateRandomDataByReference(matrix2);
	Print(matrix2);

	std::cout << "相加后的矩阵为\n";
	AddByPointer(&matrix_sum, &matrix1, &matrix2);
	//AddByReference(matrix_sum, matrix1, matrix2);
	Print();
}

//matrix1 = PopulateRandomDataByValue(matrix1); 
//PopulateRandomDataByValue() {}; 为什么c原生数组在“上述条件限制下”不能使用这种方式获取返回值？
PopulateRandomDataByPointer() {};
PopulateRandomDataByReference() {};

AddByValue() {};
AddByPointer() {};
AddByReference() {};

Print() {};


