#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


int main1()
{
	//���õĻ����﷨
	//�������� &����=ԭ��

	int a = 10;
	int& b = a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	b = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	cout << "ԭ��a��ַ��" << (int)&a << endl;
	cout << "����b��ַ��" << (int)&b << endl;

	int* p = &a;
	cout << "ԭ��a��ַ��" << (int)&a << endl;
	cout << "ָ��p��ַ��" << (int)&(p) << endl;

	system("pause");
	return 0;
}