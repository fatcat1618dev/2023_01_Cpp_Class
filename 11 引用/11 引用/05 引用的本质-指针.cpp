#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void func05(int& ref)		//�Զ�תΪ��int* const ref=&a;
{
	ref = 99;				//�ڲ�ת��*ref=99
}
int main5()
{
	int a = 10;

	int& ref = a;		//�Զ�ת��Ϊ int* const ref=&a;ָ��ָ�򲻿ɸģ������ò��ɸ���
	ref = 100;			//�Զ��ڲ����������ã��Զ�תΪ*ref=100

	cout << "a=" << a << endl;
	cout << "ret=" << ref << endl;

	func05(a);
	cout << "a=" << a << endl;

	system("pause");
	return 0;
}