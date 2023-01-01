#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main2()
{
	int a = 100;
	int* p = &a;

	cout << "size of (int *)=\t" << sizeof(int *) << endl;
	cout << "size of (double *)=\t" << sizeof(double*) << endl;

	system("pause");

	return 0;
}