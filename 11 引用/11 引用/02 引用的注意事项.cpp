#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main2()
{
	int a = 10;
	
	//���ó�ʼ��
	int& b = a;

	//��ʼ���󲻿ɸı�
	int c = 20;
	b = c;		//��ֵ

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	system("pause");
	return 0;
}