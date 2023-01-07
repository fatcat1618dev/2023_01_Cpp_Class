#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main2()
{
	int a = 10;
	
	//引用初始化
	int& b = a;

	//初始化后不可改变
	int c = 20;
	b = c;		//赋值

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	system("pause");
	return 0;
}