#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//ȫ�ֱ���
int g_a = 10;
int g_b = 10;

//const���ε�ȫ�ֱ�����ȫ�ֳ��� 
const int c_g_a = 10;
const int c_g_b = 10;

int main1()
{
	//�ֲ�����
	int a = 10;
	int b = 10;
	cout << "�ֲ�����a�ĵ�ַ��" << (int)&a << endl;
	cout << "�ֲ�����a�ĵ�ַ��" << (int)&a << endl;

	//ȫ�ֱ���
	cout << "ȫ�ֱ���a�ĵ�ַ��" << (int)&g_a << endl;
	cout << "ȫ�ֱ���a�ĵ�ַ��" << (int)&g_b << endl;

	//��̬����
	static int s_a = 10;
	static int s_b = 10;
	cout << "��̬����s_a�ĵ�ַΪ��" << (int)&s_a << endl;
	cout << "��̬����s_b�ĵ�ַΪ��" << (int)&s_b << endl;

	//����
	//�ַ�������
	cout << "�ַ��������ĵ�ַ��" << (int)&"hello world" << endl;

	//const���εı���
	//ȫ�ֱ������ֲ�����
	cout << "const���ε�ȫ�ֱ���c_g_a��" << (int)&c_g_a << endl;
	cout << "const���ε�ȫ�ֱ���c_g_b��" << (int)&c_g_b << endl;

	//�ֲ�����
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "const���εľֲ�����c_l_a��" << (int)&c_l_a << endl;
	cout << "const���εľֲ�����c_l_a��" << (int)&c_l_b << endl;

	system("pause");
	return 0;
}