#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main4() {

	/*
		声明一个5元素数组，将元素逆序，如1，2，3，4，5，逆序后为5，4，3，2，1。
	*/
	int arr[] = { 100,200,300,150,250,1000};

	int len = sizeof(arr)/sizeof(arr[0]);
	int left = 0;
	int right = len-1;
	int temp = 0;
	for (left = 0; left<right;left++,right--) 
	{
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}
	for (int i = 0; i < len; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;

	system("pause");

	return 0;
}