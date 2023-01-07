#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


int main1()
{
	//引用的基本语法
	//数据类型 &别名=原名

	int a = 10;
	int& b = a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	b = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	cout << "原名a地址：" << (int)&a << endl;
	cout << "别名b地址：" << (int)&b << endl;

	int* p = &a;
	cout << "原名a地址：" << (int)&a << endl;
	cout << "指针p地址：" << (int)&(p) << endl;

	system("pause");
	return 0;
}