#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main1() {

	/*
		1.`�������� ������[���鳤��]`

		2.`�������� ������[���鳤��]={ֵ1,ֵ2,...}`

		3.`�������� ������[]={ֵ1,ֵ2,...}`
	*/

	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = 10 * (i+1);
		cout << arr[i] << " ";
	}
	cout << endl;

	int arr2[5] = {1,3,5,7};	//δ��ֵ�����0
	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;


	system("pause");

	return 0;
}