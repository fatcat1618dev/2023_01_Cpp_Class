#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main5() {

	/*
		���õ������㷨���������У���{4,2,8,0,5,7,1,3,9}
	*/
	//int arr[] = { 4,2,8,0,5,7,1,3,9 };
	int arr[] = { 9,8,7,5,4,3,2,1,0 };
	//int arr[] = { 1,2,3,4,5,6,7,9,8 };

	cout << "����ǰ��";
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	int lunshu = 0;
	int cishu = 0;

	for (int j = 0; j < len-1; j++)	//���������Ԫ�ظ���-1
	{
		bool flag = 0;					//������־λ

		for (int i = 0; i < len-1-j; i++)	//�ڲ������Ԫ�ظ���-1-����
		{
			int tmp = 0;
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = 1;				//������
				cishu++;
			}
		}

		if (flag == 0)
		{
			break;
		}
		lunshu = j + 1;

	}
	cout << "������" << lunshu << "��" << endl;
	cout << "������" << cishu << "��" << endl;

	cout << "�����";				//ð������
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");

	return 0;
}