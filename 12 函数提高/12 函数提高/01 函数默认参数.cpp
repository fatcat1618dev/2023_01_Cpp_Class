#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//函数默认参数
//传入数据则用自己的，否则用默认值
int func1(int a, int b, int c=99)
{
	return a + b + c;
}

//注意1：如果某个位置已经有了默认参数，从这个位置后从左向右都必须有默认值
//int func(int a, int b=10, int c)
//注意2：函数声明、定义中，有一个有默认参数即可
int func2(int a, int b, int c=99);

int func2(int a, int b, int c)
{
	return a * b * c;
}

int main1()
{
	cout << func1(10, 20) << endl;
	cout << func2(10, 10) << endl;

	system("pause");
	return 0;
}