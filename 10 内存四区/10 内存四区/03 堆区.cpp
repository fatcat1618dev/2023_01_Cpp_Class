#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int* func()
{
	//new �������ݵ�����
	return new int(10);		//���ص�ָ��
}

int main3()
{
	//������������
	int* p = func();

	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	system("pause");
	return 0;
}