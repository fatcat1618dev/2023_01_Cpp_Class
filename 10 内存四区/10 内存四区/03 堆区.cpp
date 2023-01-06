#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int* func()
{
	//new 创建数据到堆区
	return new int(10);		//返回的指针
}

int main3()
{
	//堆区开辟数据
	int* p = func();

	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	system("pause");
	return 0;
}