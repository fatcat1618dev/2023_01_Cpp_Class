#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��
class Person
{
public:
	//��ʼ���б�
	Person()
	{	
		cout << "Person���캯��" << endl;
	}
	~Person()
	{
		cout << "Person��������" << endl;
	}
	static string m_Name;

};
string Person::m_Name = "����";	//�������ʼ��

void test01()
{
	Person p;
	cout << p.m_Name << endl;

	Person p2;
	p2.m_Name = "������";
	cout << p.m_Name << endl;

	//��������
	cout << Person::m_Name << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}