//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////
//class Person
//{
//public:
//	Person(int age)
//	{
//		//thisָ�򱻵��õĳ�Ա���������Ķ���,��Ա����p1
//		this->age = age;
//	}
//
//	//���� ��ʽ���
//	Person& PersonAddAge(Person& p)
//	{
//		this->age += p.age;
//		return *this;	//���ر���
//	}
//
//	//ֵ���ء����������� ����
//	Person PersonAddAge1(Person& p)
//	{
//		this->age += p.age;
//		return *this;	//���ر���
//	}
//	int age;
//};
//
////1.������Ƴ�ͻ
////����1������淶 m_age
////����2��thisָ��
//void test01()
//{
//	Person p1(18);	//�вι���
//	cout << "����Ϊ��" << p1.age << endl;
//}
//
////2.���ض�����*this
//
//void test02()
//{
//	Person p2(20);
//	Person p3(10);
//	p2.PersonAddAge(p3).PersonAddAge(p2);	//20+10+30
//	cout << "p3���䣺" << p2.age << endl;
//}
//
//void test03()
//{
//	Person p2(20);
//	Person p3(10);
//	p2.PersonAddAge1(p3).PersonAddAge1(p2);	//��������,1�κ��copy����
//	cout << "p3���䣺" << p2.age << endl;
//}
//
//int main()
//{
//	test01();	//
//	test02();	//��ʽ����
//	test03();
//
//	system("pause");
//	return 0;
//}