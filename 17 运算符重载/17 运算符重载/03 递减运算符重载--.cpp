//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////��-���������		
////ǰ��--������--
////5 --5 4 4
////5 5-- 5 4
//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger i);
//
//public:
//	MyInteger() :m_Num(5) {}	//�б��ʼ�������캯��
//
//	//����ǰ��--	--a
//	MyInteger& operator--()
//	{
//		m_Num--;
//		return *this;
//	}
//	//���غ���--	a--
//	MyInteger operator--(int)	//ռλ��
//	{
//		//����
//		MyInteger tmp = *this;			//��ָ��
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
//void test01()	//����ʹ��
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
//	test01();//����ʹ��
//	test02();//����MyInteger�����
//	test03();
//
//	system("pause");
//	return 0;
//}