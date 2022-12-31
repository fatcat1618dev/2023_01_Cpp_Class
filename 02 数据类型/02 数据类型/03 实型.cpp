#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main3() {

	/*
		单精度	float
		双精度	double
		默认情况，显示6位有效数字
	*/

	float f1 = 3.1415926f;
	double d1 = 3.1415926;

	cout << "f1=" << f1 << endl;
	cout << "d1=" << d1 << endl;

	cout << "float占用" << sizeof(float) << "字节"<<endl;		//4字节
	cout << "double占用" << sizeof(double) << "字节" << endl;	//8字节

	//科学计数法
	float f2 = 9e-2;
	cout << "f2=" << f2 << endl;

	system("pause");

	return 0;
}