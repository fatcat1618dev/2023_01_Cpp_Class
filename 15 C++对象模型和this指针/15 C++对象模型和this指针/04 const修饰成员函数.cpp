#include<iostream>
using namespace std;

//������
class Person
{
public:

	//thisָ��ı��� ָ�볣�� ָ�򲻿ɸ�
	//const Person* const this
	Person() :m_Age(18), m_B(22) {}

	void showPersonAge() const
	{
		//m_Age = 100;	//���ɸ�
		//m_B = 100;
		cout << m_B << endl;
	}
	void func(){}

	int m_Age;
	mutable int m_B;
};

void test01()
{
	Person p1;
	p1.showPersonAge();
}

//������
void test02()
{
	const Person p2;	//��Ϊ������
	//p2.m_Age = 100;		
	p2.m_B = 99;		//mutable
	p2.showPersonAge();

	//������ֻ�ܵ�������
	//p2.func();
}
int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}