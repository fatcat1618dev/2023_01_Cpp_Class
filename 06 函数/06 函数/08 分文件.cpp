#define _CRT_SECURE_NO_WARNINGS 1

#include"swap.h"

int main()
{
	int a = 5;
	int b = 6;
	swap(&a, &b);
	cout << a << " " << b << endl;

	system("pause");	//�����������
	return 0;
}