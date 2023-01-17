//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////左移运算符重载
//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);//友元
//public:
//	//列表初始化
//	Person(int a,int b):m_A(a),m_B(b){}
//private:
//	int m_A;
//	int m_B;
//};
//
////全局函数 重载 左移<<运算符
//ostream& operator<<(ostream& cout, Person& p)
//{
//	cout << "a:" << p.m_A << " b:" << p.m_B << endl;
//	return cout;
//}
//void test01()
//{
//	Person p1(6, 9);			//有参构造
//
//	cout << p1 << endl;			//链式编程
//
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}