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
//		cout << "Person的无参构造函数的调用" << endl;
//	}
//	Person(int a)
//	{
//		age = a;
//		cout << "Person的有参构造函数的调用" << endl;
//	}
//
//	//拷贝构造函数
//	Person(const Person &p)
//	{
//		//将传入人的属性全部拿到
//		age = p.age;
//		cout << "Person的拷贝构造函数的调用" << endl;
//	}
//	~Person()
//	{
//		cout << "Person析构函数的调用" << endl;
//	}
//	int age;
//};
//
////构造和析构都是必有的实现，如果我们不提供，编译器会提供一个空实现的构造和析构，，，即没有上述cout语句的空实现
//void test01()
//{
//	////1.括号法
//	//Person p;	//栈上的数据，创建和销毁，默认调用法
//	//Person p2(10);	//有参构造
//	//Person p3(p2);	//拷贝构造
//
//	//cout << "p2的年龄：" << p2.age << endl;
//	//cout << "p3的年龄：" << p3.age << endl;		//和p2一样，直接拷贝的p2的
//
//	////注意1：调用默认构造函数时，不要加()
//	////编译器会认为是一个函数声明，不创建对象
//	////Person p4();
//
//	////2.显式法
//	//Person p1;
//	//Person p2 = Person(10);	//有参构造
//	//Person p3 = Person(p2);	//拷贝构造
//
//	//Person(10);	//匿名对象 当前执行结束后，立即回收			生存周期短
//	//cout << "aaa" << endl;
//	////注意2：
//	////不要利用拷贝构造函数 初始化匿名对象 编译器会认为Person(p3)=Person p3,重定义
//
//	//3.隐式转换法
//	Person p4 = 10;	//相当于Person p4=Person(10);	
//	Person p5 = p4;//
//}
//
//
//int main()
//{
//	test01();	//构造、析构
//
//	system("pause");
//	return 0;
//}