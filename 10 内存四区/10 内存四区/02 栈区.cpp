#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int* func1()
{
	int a = 10;		//�ֲ������������ջ��
	return &a;		//���ؾֲ�������ַ
}

int main2()
{
	//���շ���ֵ
	int* p = func1();
	cout << *p << endl;//��һ�ο��Դ�ӡ�����������˱�����
	cout << *p << endl;//�ڶ��Σ����ٱ�����


	system("pause");
	return 0;
}