#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

////声明
//int max(int, int);

int main5()
{
	int a = 5;
	int b = 6;
	cout << max(a, b) << endl;

	system("pause");	//按任意键继续
	return 0;
}

//定义
int max(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}