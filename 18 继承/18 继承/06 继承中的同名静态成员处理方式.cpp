//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////同名静态成员
//
//class Base
//{
//public:
//	static int m_A;
//	static void func()
//	{
//		cout << "Base 下 func()" << endl;
//	}
//	static void func(int)
//	{
//		cout << "Base 下 func(int)" << endl;
//	}
//};
////类外初始化
//
//int Base::m_A = 45;
//
//class Son:public Base
//{
//public:
//	static int m_A;
//	static void func()
//	{
//		cout << "Son 下 func()" << endl;
//	}
//};
//int Son::m_A = 20;
//
//void case01()
//{
//	//通过对象访问
//	cout << "通过对象访问： "<<endl;
//	Son s;
//	cout << "Son 下 m_A " << s.m_A << endl;
//	cout << "Base 下 m_A " << s.Base::m_A << endl;
//
//	//2.通过类名访问
//	cout << "通过类名访问" << endl;
//	cout << "Son 下 m_A " << Son::m_A << endl;
//	//通过类名、父类作用域下
//	cout << "Base 下 m_A " <<Son::Base::m_A<< endl;
//}
//
//void case02()
//{
//	//通过对象访问
//	cout << "通过对象访问： " << endl;
//	Son s;
//	s.func();
//	s.Base::func();
//
//	//2.通过类名访问
//	cout << "通过类名访问" << endl;
//	Son::func();
//	//通过类名、父类作用域下
//	Son::Base::func();
//}
//int main()
//{
//	case01();
//	cout << "---------------------------" << endl;
//	case02();
//	system("pause");
//	return 0;
//}