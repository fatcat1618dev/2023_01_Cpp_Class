#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//�β�
void swap(int num1, int num2)
{
	cout << "����ǰ:";
	cout << num1 << " " << num2 << endl;

	int tmp = num1;
	num1 = num2;
	num2 = tmp;
	cout << "������:";
	cout << num1 << " " << num2 << endl;
}
int main3()
{
	int a = 5;
	int b = 6;
	swap(a, b);

	system("pause");	//�����������
	return 0;
}