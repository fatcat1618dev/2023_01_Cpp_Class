#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main2() {

	int arr[5] = {2,4,6,8,10};

	//�ڴ��С
	cout << "����ռ�õ��ڴ�ռ�" << sizeof(arr) << endl;

	//�����׵�ַ
	cout <<arr<< endl;
	//��Ԫ�ص�ַ
	cout << &arr[0] << endl;
	//�ڶ���Ԫ�ص�ַ
	cout << &arr[1] << endl;	//���������Կռ�
	//
	cout << *(arr) << endl;		//ָ��

	system("pause");

	return 0;
}