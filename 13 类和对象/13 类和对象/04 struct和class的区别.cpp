#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class C1
{
	int m_A;	//Ĭ��private
};
struct C2
{
	int m_A;	//Ĭ��public
};
int main4()
{
	//class Ȩ��Ĭ��˽��
	C1 c1;
	//c1.m_A = 10;	//�޷�����

	C2 c2;
	c2.m_A = 100;	//ok

	system("pause");
	return 0;
}