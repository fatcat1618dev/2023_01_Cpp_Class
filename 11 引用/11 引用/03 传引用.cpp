#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//交换函数
//传值
void myswap01(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//传址
void myswap02(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//传引用
void myswap03(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main3()
{
	int a = 10;
	int b = 20;

	//myswap01(a,b);					//传值	实参不变，形参变
	//myswap02(&a, &b);					//传址	实参变
	myswap03(a, b);

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	system("pause");
	return 0;
}