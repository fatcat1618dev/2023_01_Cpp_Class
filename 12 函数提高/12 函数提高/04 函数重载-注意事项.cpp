#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/*
* 引用作为重载条件
* 函数重载碰到函数默认参数
*/

//引用
void func04(int&a)
{
	cout << "func(int&a)调用" << endl;
}

void func04(const int& a)
{
	cout << "func(const int&a)调用" << endl;
}

//默认参数
void func04_1(int a, int b = 10)
{
	cout << "func04_1(int a,int b)" << endl;
}

void func04_1(int a)
{
	cout << "func04_1(int a)" << endl;
}

int main()
{
	int a = 10;
	func04(a);

	func04(10);			//

	//func04_1(10);		//默认参数，重载出现歧义，编译器傻了

	system("pause");
	return 0;
}