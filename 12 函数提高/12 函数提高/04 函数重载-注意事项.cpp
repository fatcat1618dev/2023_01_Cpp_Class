#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/*
* ������Ϊ��������
* ����������������Ĭ�ϲ���
*/

//����
void func04(int&a)
{
	cout << "func(int&a)����" << endl;
}

void func04(const int& a)
{
	cout << "func(const int&a)����" << endl;
}

//Ĭ�ϲ���
void func04_1(int a, int b = 10)
{
	cout << "func04_1(int a,int b)" << endl;
}

void func04_1(int a)
{
	cout << "func04_1(int a)" << endl;
}

int main()
{
	int a = 10;
	func04(a);

	func04(10);			//

	//func04_1(10);		//Ĭ�ϲ��������س������壬������ɵ��

	system("pause");
	return 0;
}