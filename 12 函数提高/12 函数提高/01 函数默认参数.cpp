#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//����Ĭ�ϲ���
//�������������Լ��ģ�������Ĭ��ֵ
int func1(int a, int b, int c=99)
{
	return a + b + c;
}

//ע��1�����ĳ��λ���Ѿ�����Ĭ�ϲ����������λ�ú�������Ҷ�������Ĭ��ֵ
//int func(int a, int b=10, int c)
//ע��2�����������������У���һ����Ĭ�ϲ�������
int func2(int a, int b, int c=99);

int func2(int a, int b, int c)
{
	return a * b * c;
}

int main1()
{
	cout << func1(10, 20) << endl;
	cout << func2(10, 10) << endl;

	system("pause");
	return 0;
}