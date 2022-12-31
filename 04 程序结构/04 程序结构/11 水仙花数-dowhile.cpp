#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cmath>

int main11() {

	//Ë®ÏÉ»¨Êý
	//153=1^3+5^3+3^3

	int num = 152;
	do
	{
		int temp = num;
		if (pow(temp%10,3) + pow(temp/10 % 10,3) + pow(temp / 100,3) == num)
		{
			cout << num << endl;
		}

		num++;
	} while (num < 1000);

	system("pause");

	return 0;
}