#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//形参
void swap(int num1, int num2)
{
	cout << "交换前:";
	cout << num1 << " " << num2 << endl;

	int tmp = num1;
	num1 = num2;
	num2 = tmp;
	cout << "交换后:";
	cout << num1 << " " << num2 << endl;
}
int main3()
{
	int a = 5;
	int b = 6;
	swap(a, b);

	system("pause");	//按任意键继续
	return 0;
}