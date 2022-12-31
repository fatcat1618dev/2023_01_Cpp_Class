#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

int main6() {

	//1.C风格
	//中括号、双引号
	char str[] = "Hello World!";
	cout << str << endl;

	//2.C++风格
	//包含头文件 #include<string>
	string str1 = "Hello World!";
	cout << str1 << endl;

	system("pause");

	return 0;
}