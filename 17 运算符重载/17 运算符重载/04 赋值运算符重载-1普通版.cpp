//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////p3(30)=p2(20)=p1(10)	连等，链式编程
//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);	//友元
//
//public:
//	//列表
//	Person(int a) :m_A(a){}
//	void showValue()
//	{
//		cout << "内部值=" << m_A << endl;
//	}
//private:
//	int m_A;
//};
//
////左移<<重载
//ostream& operator<<(ostream&cout,Person&p)
//{
//	cout << p.m_A;
//	return cout;
//}
////测试01
//void test01()
//{
//	Person p1(10);
//	p1.showValue();
//
//}
//void test02()	//成员函数
//{
//
//	Person p1(10);
//	Person p2(20);
//	Person p3(30);
//
//	p3 = p2 = p1;
//	p2.showValue();
//	p3.showValue();
//
//}
//void test03()	//<<、=运算符重载
//{
//
//	Person p1(2);
//	Person p2(4);
//	Person p3(6);
//	p3 = p2 = p1;
//	cout << p2<< endl;
//	cout << p3 << endl;
//
//}
//int main() 
//{
//	cout << "1.普通" << endl;
//	test01();//正常赋值、显示
//
//	cout << "2.成员函数" << endl;
//	test02();
//
//	//test03
//	cout << "3.运算符重载——左移<<	赋值=——" << endl;
//	test03();
//
//	system("pause");
//	return 0;
//}