#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��Ҫ���ؾֲ���������
int& test04_1()
{
	int a = 10;	//��������� ջ��
	return a;
}

//����������Ϊ��ֵ
int& test04_2()
{
	static int a = 10;	//��������� ջ��
	return a;
}
int main4()
{
	//int &ret = test04_1();
	//cout << "ret=" << ret << endl;		//��һ��ok�����������˱���
	//cout << "ret=" << ret << endl;		//�ڶ��β�ok��a�ڴ��Ѿ��ͷ�
	
	int& ret = test04_2();
	cout << "ret=" << ret << endl;		
	cout << "ret=" << ret << endl;		
	//������Ϊ��ֵ��ֵ
	test04_2() = 1000;
	cout << "ret=" << ret << endl;		
	cout << "ret=" << ret << endl;		

	system("pause");
	return 0;
}