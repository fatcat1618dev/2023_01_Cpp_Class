//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
///*
//1. Ĭ��==����==�������޲Ρ�������Ϊ�գ�
//2. Ĭ��==����==�������޲Ρ�������Ϊ�գ�
//3. Ĭ��==��������==�����������Խ���ֵ����
//*/
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Ĭ�Ϲ��캯��" << endl;
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
//void test01()		//Ĭ������£�C++���������ٸ�һ�������3������
//{
//	Person p;
//	p.m_Age = 18;
//
//	Person p2(p);
//	cout << "p2�����䣺" <<p2.m_Age<< endl;
//}
//
////�ṩ�в�
//void test02()
//{
//	Person p;
//}
//int main()
//{
//	//test01();	//3������
//	test02();
//
//	system("pause");
//	return 0;
//}