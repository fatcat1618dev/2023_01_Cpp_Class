#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define DAY 7
/*
	常量
	1.#define宏常量
	2.const修饰的变量
*/

int main4() {

	cout << "一周共有" << DAY << "天" << endl;

	const int month = 12;

	cout << "一年共有" <<month<<"个月" << endl;

	system("pause");

	return 0;
}