#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main14() {

	for (int i = 1; i < 100; i++)
	{
		if(i%2==0)
		{
			continue;
		}
		cout << i << " ";
	}

	system("pause");

	return 0;
}