#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main2() {

	/*
		sizeof
		语法：sizeof(类型/变量)
	*/

	cout << "short占用内存空间：" << sizeof(short) << endl;
	cout << "int占用内存空间：" << sizeof(int) << endl;
	cout << "long占用内存空间：" << sizeof(long) << endl;
	cout << "long long占用内存空间：" << sizeof(long long) << endl;

	system("pause");

	return 0;
}