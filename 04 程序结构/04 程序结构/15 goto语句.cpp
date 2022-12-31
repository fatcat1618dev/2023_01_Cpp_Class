#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main() {

	cout << "1.xxxx" << endl;
	goto FLAG;

	cout << "2.xxxx" << endl;
	cout << "3.xxxx" << endl;
	cout << "4.xxxx" << endl;

	FLAG:
	cout << "5.xxxx" << endl;

	system("pause");

	return 0;
}