#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main6()
{
	/*
		ָ�����������Ԫ��
	*/
	int arr[] = { 1,3,5,7,9 };

	//ָ�����
	int* p = arr;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << *p << " ";
		p++;
	}
	cout << endl;

	system("pause");

	return 0;
}