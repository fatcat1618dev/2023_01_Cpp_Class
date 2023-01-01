#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main1()
{
	int a = 100;
	int* p = &a;
	cout << "a的地址：" << &a << endl;
	cout << "p指针为：" << p << endl;

	system("pause");

	return 0;
}