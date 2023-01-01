#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void swap1(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void swap2(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
int main7()
{
	//传值,实参未变
	int a = 10;
	int b = 20;
	swap1(a, b);
	cout << a << " " << b << endl;
	
	//传址，实参变
	int x = 1;
	int y = 9;
	swap2(&x, &y);	//传址
	cout << x << " " << y << endl;

	system("pause");

	return 0;
}