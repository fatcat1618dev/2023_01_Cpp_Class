//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	
//	////传统初始化
//	//Person(int a,int b,int c)
//	//{
//	//	m_A = a;
//	//	m_B = b;
//	//	m_C = c;
//	//	cout << "有参构造函数" << endl;
//	//}
//
//	////初始化列表，固化版
//	////传统赋值初始化相当于，先声明类，再赋值
//	////初始化列表，直接声明一个有初值的类型，大型项目中，class类中成员变量极多情况下，初始化列表更高效
//	//Person() :m_A(10), m_B(20), m_C(30)
//	//{
//	//}
//	Person(int a,int b,int c):m_A(a),m_B(b),m_C(c)
//	{
//
//	}
//	int m_A;
//	int m_B;
//	int m_C;
//};
//
////用系统的copy构造
//void test01()
//{
//	/*Person p1(1, 2, 3);*/
//
//	Person p1(1,2,3);
//	cout << "m_A=" << p1.m_A << endl;
//	cout << "m_B=" << p1.m_B << endl;
//	cout << "m_C=" << p1.m_C << endl;
//
//}
//
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}