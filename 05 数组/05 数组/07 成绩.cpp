#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main() {

	/*
		���Գɼ�ͳ�ƣ��ֱ����3��ͬѧ���ܳɼ�
	*/
	int arr[][3] =
	{
		{100,100,100},
		{90,50,100},
		{60,70,80}
	};
	
	string names[] = { "����","����","����" };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	//�ܳɼ�
	int sum[3] = { 0,0,0 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum[i]+=arr[i][j];
		}
		cout << names[i]<<"���ܷ�Ϊ��"<<sum[i] << endl;
	}

	system("pause");

	return 0;
}