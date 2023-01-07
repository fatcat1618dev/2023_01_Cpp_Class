#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//函数重载
/*
* 同一个作用域下
* 函数名称相同
* 函数参数类型、个数、顺序不同
*/

void func()
{
	cout << "func()在调用" << endl;
}

void func(int a)
{
	cout << "func(int)在调用" << endl;
}
void func(double)
{
	cout << "func(double)在调用" << endl;
}
int main3()
{
	func();
	func(3);
	func(3.14);

	system("pause");
	return 0;
}