//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////拷贝构造函数的调用时机
///*
//* 使用一个已经创建完毕的对象来初始化一个新对象
//* 值传递的方式给函数传值
//* 以值方式返回局部对象
//*/
//class Person
//{
//public:
//	Person()
//	{
//		cout << "无参构造函数" << endl;
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
////1.使用1个已经创建完毕的对象来初始化
//void test01()
//{
//	Person p2(10);
//	Person p3(p2);
//	cout << "p3的年龄：" << p3.m_Age << endl;
//}
//
////2.使用值传递方式给函数传值
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
////3.以值方式返回局部对象
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