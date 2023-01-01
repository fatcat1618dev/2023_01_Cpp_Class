#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main3() {

	/*
		练习1：**5只小猪称体重**
		数组中记录了五只小猪体重，如：int arr[5]={100,200,300,150,250},找出并打印最重的值。
	*/
	int arr[5] = { 100,200,300,150,250 };

	int max = 0;
	for (int i = 0; i < 5; i++) {

		max = (arr[i] > max ? arr[i] : max);
	}
	cout << max << endl;

	system("pause");

	return 0;
}