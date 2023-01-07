#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//占位参数
//占位参数可以有默认参数

void func02(int a, int=10)				//没用，更没用了
{
	cout << "this is func" << endl;
}
int main2()
{
	func02(10, 10);

	system("pause");
	return 0;
}