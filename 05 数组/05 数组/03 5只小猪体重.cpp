#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main3() {

	/*
		��ϰ1��**5ֻС�������**
		�����м�¼����ֻС�����أ��磺int arr[5]={100,200,300,150,250},�ҳ�����ӡ���ص�ֵ��
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