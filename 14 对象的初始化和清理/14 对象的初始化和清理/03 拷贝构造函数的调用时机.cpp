//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////�������캯���ĵ���ʱ��
///*
//* ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
//* ֵ���ݵķ�ʽ��������ֵ
//* ��ֵ��ʽ���ؾֲ�����
//*/
//class Person
//{
//public:
//	Person()
//	{
//		cout << "�޲ι��캯��" << endl;
//	}
//	Person(int age)
//	{
//		m_Age = age;
//		cout << "�вι��캯��" << endl;
//	}
//	Person(const Person& p)
//	{
//		m_Age = p.m_Age;
//		cout << "COPY���캯��" << endl;
//
//	}
//	~Person()
//	{
//		cout << "��������" << endl;
//	}
//	int m_Age;
//};
//
////1.ʹ��1���Ѿ�������ϵĶ�������ʼ��
//void test01()
//{
//	Person p2(10);
//	Person p3(p2);
//	cout << "p3�����䣺" << p3.m_Age << endl;
//}
//
////2.ʹ��ֵ���ݷ�ʽ��������ֵ
//void doWork(Person p)
//{
//
//}
//void test02()
//{
//	Person p;
//	doWork(p);
//}
//
////3.��ֵ��ʽ���ؾֲ�����
//Person doWork2()
//{
//	Person p1;
//	cout << (int)&p1 << endl;
//	return p1;
//}
//void test03()
//{
//	Person p = doWork2();
//	cout << (int)&p << endl;
//}
//int main()
//{
//	//test01();			
//	//test02();
//	test03();
//
//	system("pause");
//	return 0;
//}