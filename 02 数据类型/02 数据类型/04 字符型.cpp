#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main4() {

	//1.字符型变量
	char ch = 'a';
	cout << ch << endl;

	cout << "char占用" << sizeof(char) << "字节" << endl;		

	//ascii码
	//a-97
	//A-65
	cout << (int)'a' << endl;
	cout << (int)'A' << endl;

	system("pause");

	return 0;
}