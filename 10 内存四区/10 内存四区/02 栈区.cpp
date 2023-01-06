#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int* func1()
{
	int a = 10;		//局部变量，存放在栈区
	return &a;		//返回局部变量地址
}

int main2()
{
	//接收返回值
	int* p = func1();
	cout << *p << endl;//第一次可以打印，编译器做了保留？
	cout << *p << endl;//第二次，不再保留了


	system("pause");
	return 0;
}