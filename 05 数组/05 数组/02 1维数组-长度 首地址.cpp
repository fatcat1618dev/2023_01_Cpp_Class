#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main2() {

	int arr[5] = {2,4,6,8,10};

	//内存大小
	cout << "数组占用的内存空间" << sizeof(arr) << endl;

	//数组首地址
	cout <<arr<< endl;
	//首元素地址
	cout << &arr[0] << endl;
	//第二个元素地址
	cout << &arr[1] << endl;	//连续的线性空间
	//
	cout << *(arr) << endl;		//指针

	system("pause");

	return 0;
}