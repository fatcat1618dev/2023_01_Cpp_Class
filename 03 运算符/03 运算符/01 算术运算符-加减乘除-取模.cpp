#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main1() {

	//除
	int a = 10;
	int b = 3;
	cout << a / b << endl;//两个整数相除，结果仍为整数	——失真

	cout << a % b << endl;
	system("pause");

	return 0;
}