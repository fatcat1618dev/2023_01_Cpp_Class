#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main12() {

	for (int i = 1; i <=100; i++) 
	{
		if (i % 10 == 7 || i / 10 % 10 == 7 || i % 7 == 0)
		{
			cout << "ÇÃ×À×Ó" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}

	system("pause");

	return 0;
}