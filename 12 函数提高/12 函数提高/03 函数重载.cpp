#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��������
/*
* ͬһ����������
* ����������ͬ
* �����������͡�������˳��ͬ
*/

void func()
{
	cout << "func()�ڵ���" << endl;
}

void func(int a)
{
	cout << "func(int)�ڵ���" << endl;
}
void func(double)
{
	cout << "func(double)�ڵ���" << endl;
}
int main3()
{
	func();
	func(3);
	func(3.14);

	system("pause");
	return 0;
}