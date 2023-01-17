//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////多继承，多个父类
//class Base1
//{
//public:
//	Base1()
//	{
//		m_A = 1;
//		m_B = 0;
//	}
//	int m_A;
//	int m_B;
//};
//
//class Base2
//{
//public:
//	Base2()
//	{
//		m_B = 2;
//	}
//	int m_B;
//};
//
//class Son :public Base1, public Base2
//{
//public:
//	Son()
//	{
//		m_C = 3;
//	}
//	int m_C;
//};
//
//void test01()
//{
//	Son	s;
//	cout << s.m_A << endl;
//	cout << s.Base1::m_B << endl;
//	cout << s.Base2::m_B << endl;
//	cout << s.m_C << endl;
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
