#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main5()
{
	/*
		1. const����ָ�롪������ָ��  const int * p����ָ�����ݲ��ɸ�
		2. const���γ�������ָ�볣��  int * const p����ָ��ָ�򲻿ɸ�
		3. const����ָ�롢��������const int * const p
	*/
	//����ָ��
	int a = 100;
	const int* p = &a;
	//*p=		//����ָ�룬����Ŷ�����ɸġ�������ͨ��*p��ֵ
	a = 1000;
	cout << *p << endl;

	//
	int a2 = 100;
	int* const p2 = &a2;
	//p2=		//ָ�볣�������ܸ�ָ��

	system("pause");

	return 0;
}