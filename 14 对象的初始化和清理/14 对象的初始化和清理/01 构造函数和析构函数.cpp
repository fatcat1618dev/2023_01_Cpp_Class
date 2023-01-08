//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////对象的初始化和清理
////构造函数 进行初始化操作
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person构造函数的调用" << endl;
//	}
//	~Person()
//	{
//		cout << "Person析构函数的调用" << endl;
//	}
//};
//
////构造和析构都是必有的实现，如果我们不提供，编译器会提供一个空实现的构造和析构，，，即没有上述cout语句的空实现
//void test01()
//{
//	Person p;	//栈上的数据，创建和销毁
//}
//int main1()
//{
//	test01();	//构造、析构
//
//	Person p1;	//程序结束，才调用析构
//
//	system("pause");
//	return 0;
//}