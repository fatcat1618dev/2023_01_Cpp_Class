#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

////����
//int max(int, int);

int main5()
{
	int a = 5;
	int b = 6;
	cout << max(a, b) << endl;

	system("pause");	//�����������
	return 0;
}

//����
int max(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}