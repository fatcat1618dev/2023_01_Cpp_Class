#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��������
//��ֵ
void myswap01(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//��ַ
void myswap02(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//������
void myswap03(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main3()
{
	int a = 10;
	int b = 20;

	//myswap01(a,b);					//��ֵ	ʵ�β��䣬�βα�
	//myswap02(&a, &b);					//��ַ	ʵ�α�
	myswap03(a, b);

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	system("pause");
	return 0;
}