#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main1() {

	/*
		1.`数据类型 数组名[数组长度]`

		2.`数据类型 数组名[数组长度]={值1,值2,...}`

		3.`数据类型 数组名[]={值1,值2,...}`
	*/

	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = 10 * (i+1);
		cout << arr[i] << " ";
	}
	cout << endl;

	int arr2[5] = {1,3,5,7};	//未给值，填充0
	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;


	system("pause");

	return 0;
}