//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
///*
//1. 默认==构造==函数（无参、函数体为空）
//2. 默认==析构==函数（无参、函数体为空）
//3. 默认==拷贝构造==函数，对属性进行值拷贝
//*/
//class Person
//{
//public:
//	Person()
//	{
//		cout << "默认构造函数" << endl;
//	}
//	Person(int age)
//	{
//		m_Age = age;
//		cout << "有参构造函数" << endl;
//	}
//	Person(const Person& p)
//	{
//		m_Age = p.m_Age;
//		cout << "COPY构造函数" << endl;
//
//	}
//	~Person()
//	{
//		cout << "析构函数" << endl;
//	}
//	int m_Age;
//};
//
//void test01()		//默认情况下，C++编译器至少给一个类添加3个函数
//{
//	Person p;
//	p.m_Age = 18;
//
//	Person p2(p);
//	cout << "p2的年龄：" <<p2.m_Age<< endl;
//}
//
////提供有参
//void test02()
//{
//	Person p;
//}
//int main()
//{
//	//test01();	//3个函数
//	test02();
//
//	system("pause");
//	return 0;
//}