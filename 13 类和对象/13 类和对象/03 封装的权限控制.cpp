#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//����Ȩ��
//����
//pulic			��Ա ���ڿ� �����  ����
//protected		��Ա ���ڿ� ���ⲻ��		�̳�	���ӿ��Է��ʸ����еı�������
//private		��Ա ���ڿ�	���ⲻ��				���Ӳ��ɷ��ʸ��׵�˽������

class Person
{
public:
	string m_Name;
protected:
	string m_Car;
private:
	int m_Password;
public:
	void func()
	{
		m_Name = "����";
		m_Car = "���ͺ�";
		m_Password = 123456;
	}
};
int main3()
{
	Person p1;
	p1.m_Name = "������";
	//p1.m_car = "����";
	//p1.m_password = 125436;

	system("pause");
	return 0;
}