//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
////普通实现
//class Calc
//{
//public:
//	Calc(int a, int b)	//构造函数
//	{
//		m_Num1 = a;
//		m_Num2 = b;
//	}
//	//计算
//	int getResult(string oper)
//	{
//		if (oper == "+")
//			return m_Num1 + m_Num2;
//		else if (oper == "-")
//			return m_Num1 - m_Num2;
//		else if (oper == "*")
//			return m_Num1 * m_Num2;
//		else if (oper == "/")
//			return m_Num1 / m_Num2;
//
//		//扩展，需要修改源码
//		//开闭原则，扩展开放、修改关闭
//	}
//	int m_Num1;
//	int m_Num2;
//};
//
//void test01()
//{
//	Calc c(5, 10);
//	cout << c.m_Num1<<" + "<<c.m_Num2<<" = "<<c.getResult("+") << endl;
//	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
//	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
//	cout << c.m_Num1 << " / " << c.m_Num2 << " = " << c.getResult("/") << endl;
//
//}
//
////多态实现计算器类
////计算器抽象类
//class AbstractCalc
//{
//public:
//	virtual int getResult()
//	{
//		return 0;
//	}
//	int m_Num1;
//	int m_Num2;
//};
////加法
//class AddCalc :public AbstractCalc
//{
//public:
//	int getResult()
//	{
//		return m_Num1 + m_Num2;
//	}
//};
////减法
//class SubCalc :public AbstractCalc
//{
//public:
//	int getResult()
//	{
//		return m_Num1 - m_Num2;
//	}
//};
////乘法
//class MulCalc :public AbstractCalc
//{
//public:
//	int getResult()
//	{
//		return m_Num1 * m_Num2;
//	}
//};
//
////除法
//class DivCalc :public AbstractCalc
//{
//public:
//	int getResult()
//	{
//		return m_Num1 / m_Num2;
//	}
//};
//
////多态条件
////父类引用（指针）指向子类对象
////虚函数
//
//void test02()
//{
//	//乘法
//	AbstractCalc* p = new MulCalc;
//	p->m_Num1 = 5;
//	p->m_Num2 = 10;
//	cout << p->getResult() << endl;
//	//销毁
//	delete p;
//
//	//减法
//	p = new SubCalc;
//	p->m_Num1 = 5;
//	p->m_Num2 = 10;
//	cout << p->getResult() << endl;
//	//销毁
//	delete p;
//}
//int main()
//{
//	//test01();
//
//	test02();
//	system("pause");
//	return 0;
//}