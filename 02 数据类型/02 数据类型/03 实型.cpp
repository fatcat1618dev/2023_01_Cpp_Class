#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main3() {

	/*
		������	float
		˫����	double
		Ĭ���������ʾ6λ��Ч����
	*/

	float f1 = 3.1415926f;
	double d1 = 3.1415926;

	cout << "f1=" << f1 << endl;
	cout << "d1=" << d1 << endl;

	cout << "floatռ��" << sizeof(float) << "�ֽ�"<<endl;		//4�ֽ�
	cout << "doubleռ��" << sizeof(double) << "�ֽ�" << endl;	//8�ֽ�

	//��ѧ������
	float f2 = 9e-2;
	cout << "f2=" << f2 << endl;

	system("pause");

	return 0;
}