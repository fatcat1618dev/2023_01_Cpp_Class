//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
////��ͨʵ��
//class Calc
//{
//public:
//	Calc(int a, int b)	//���캯��
//	{
//		m_Num1 = a;
//		m_Num2 = b;
//	}
//	//����
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
//		//��չ����Ҫ�޸�Դ��
//		//����ԭ����չ���š��޸Ĺر�
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
////��̬ʵ�ּ�������
////������������
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
////�ӷ�
//class AddCalc :public AbstractCalc
//{
//public:
//	int getResult()
//	{
//		return m_Num1 + m_Num2;
//	}
//};
////����
//class SubCalc :public AbstractCalc
//{
//public:
//	int getResult()
//	{
//		return m_Num1 - m_Num2;
//	}
//};
////�˷�
//class MulCalc :public AbstractCalc
//{
//public:
//	int getResult()
//	{
//		return m_Num1 * m_Num2;
//	}
//};
//
////����
//class DivCalc :public AbstractCalc
//{
//public:
//	int getResult()
//	{
//		return m_Num1 / m_Num2;
//	}
//};
//
////��̬����
////�������ã�ָ�룩ָ���������
////�麯��
//
//void test02()
//{
//	//�˷�
//	AbstractCalc* p = new MulCalc;
//	p->m_Num1 = 5;
//	p->m_Num2 = 10;
//	cout << p->getResult() << endl;
//	//����
//	delete p;
//
//	//����
//	p = new SubCalc;
//	p->m_Num1 = 5;
//	p->m_Num2 = 10;
//	cout << p->getResult() << endl;
//	//����
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