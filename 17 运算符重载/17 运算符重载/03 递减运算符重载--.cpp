//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////递-运算符重载		
////前置--、后置--
////5 --5 4 4
////5 5-- 5 4
//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger i);
//
//public:
//	MyInteger() :m_Num(5) {}	//列表初始化，构造函数
//
//	//重载前置--	--a
//	MyInteger& operator--()
//	{
//		m_Num--;
//		return *this;
//	}
//	//重载后置--	a--
//	MyInteger operator--(int)	//占位符
//	{
//		//副本
//		MyInteger tmp = *this;			//用指针
//		m_Num--;
//		return tmp;
//	}
//private:
//	int m_Num;
//};
//
//ostream& operator<<(ostream& cout, MyInteger i)
//{
//	cout << i.m_Num;
//	return cout;
//}
//void test01()	//常规使用
//{
//	int i = 0;
//	cout << i << endl;
//}
//
//void test02()
//{
//	MyInteger j;
//	cout << j << endl;
//}
//
//void test03()
//{
//	MyInteger a;
//	cout << --a << endl;
//	cout << a << endl;
//
//	MyInteger b;
//	cout << b-- << endl;
//	cout << b << endl;
//}
//int main()
//{
//	test01();//常规使用
//	test02();//重载MyInteger运算符
//	test03();
//
//	system("pause");
//	return 0;
//}