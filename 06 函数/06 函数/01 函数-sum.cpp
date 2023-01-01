#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//形参
int add(int num1, int num2)
{
	return num1 + num2;
}
int main1()
{
	int a = 5;
	int b = 6;
	//实参
	cout << add(a, b) << endl;

	system("pause");	//按任意键继续
	return 0;
}