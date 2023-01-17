//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////继承中的同名成员
////成员属性
////函数
//class Base
//{
//public:
//	Base()
//	{
//		m_A = 100;
//	}
//	void func()
//	{
//		cout << "Base 成员函数" << endl;
//	}
//	int m_A;
//};
//class Son:public Base
//{
//public:
//	Son()
//	{
//		m_A = 200;
//	}
//	void func()
//	{
//		cout << "Son 成员函数" << endl;
//	}
//	int m_A;
//};
//
//void case01()
//{
//	Son s;
//	cout << "Son m_A	" << s.m_A << endl;
//	cout << "Base m_A	" << s.Base::m_A << endl;
//
//}
//int main()
//{
//
//	case01();
//	system("pause");
//	return 0;
//}