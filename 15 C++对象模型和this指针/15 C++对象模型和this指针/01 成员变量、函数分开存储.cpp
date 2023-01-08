//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////变量、成员分开存储
//class Person1
//{
//};
//class Person2
//{
//	int m_A;	//非静态成员变量
//};
//class Person3
//{
//	int m_A;				//非静态成员变量，属于类对象上
//	static int m_B;			//	静态成员变量，不属于类上
//	void func() {};		//非静态成员函数，不属于类上
//	static void func2() {};	//	静态成员函数，不属于类上
//};
//int Person3::m_B = 10;		//类外赋值
//
//void test01()
//{
//	Person1 p;
//	//空对象占用内存空间：1
//	//c++编译器会给每个空对象分配一个字节空间，区分占的位置，
//	//每个空对象也应该有一个独一无二的内存地址
//	cout << "sizeof p= " << sizeof(p) << endl;
//}
//void test02()
//{
//	Person2 p;
//	cout << "sizeof p= " << sizeof(p) << endl;
//}
//void test03()
//{
//	Person3 p;
//	cout << "sizeof p= " << sizeof(p) << endl;
//}
//int main()
//{
//	test01();	//空对象
//	test02();	//非静态成员变量	
//	test03();	//静态成员变量	  不在类上
//
//	system("pause");
//	return 0;
//}