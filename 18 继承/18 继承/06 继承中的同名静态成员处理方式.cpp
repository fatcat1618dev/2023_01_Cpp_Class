//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////ͬ����̬��Ա
//
//class Base
//{
//public:
//	static int m_A;
//	static void func()
//	{
//		cout << "Base �� func()" << endl;
//	}
//	static void func(int)
//	{
//		cout << "Base �� func(int)" << endl;
//	}
//};
////�����ʼ��
//
//int Base::m_A = 45;
//
//class Son:public Base
//{
//public:
//	static int m_A;
//	static void func()
//	{
//		cout << "Son �� func()" << endl;
//	}
//};
//int Son::m_A = 20;
//
//void case01()
//{
//	//ͨ���������
//	cout << "ͨ��������ʣ� "<<endl;
//	Son s;
//	cout << "Son �� m_A " << s.m_A << endl;
//	cout << "Base �� m_A " << s.Base::m_A << endl;
//
//	//2.ͨ����������
//	cout << "ͨ����������" << endl;
//	cout << "Son �� m_A " << Son::m_A << endl;
//	//ͨ��������������������
//	cout << "Base �� m_A " <<Son::Base::m_A<< endl;
//}
//
//void case02()
//{
//	//ͨ���������
//	cout << "ͨ��������ʣ� " << endl;
//	Son s;
//	s.func();
//	s.Base::func();
//
//	//2.ͨ����������
//	cout << "ͨ����������" << endl;
//	Son::func();
//	//ͨ��������������������
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