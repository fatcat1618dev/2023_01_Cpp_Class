//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////�Ӻ����������
////�Զ������ͣ�������person���Եļӷ�����
//
//class Person
//{
//public:
//	//Person operator+(Person& p);
//	int m_A;
//	int m_B;
//};
//
//
//////1 ��Ա��������+��ȫ�����ƣ�����Ҫ������������
////Person Person::operator+(Person& p)
////{
////	Person tmp;
////	tmp.m_A = this->m_A + p.m_A;
////	tmp.m_B = this->m_B + p.m_B;
////	return tmp;
////}
//
////ȫ�ֺ�������+
//Person operator+(Person& p1, Person& p2)
//{
//	Person tmp;
//	tmp.m_A = p1.m_A + p2.m_A;
//	tmp.m_B = p1.m_A + p2.m_B;
//	return tmp;
//}
//
//void test01()
//{
//	Person p1;
//	p1.m_A = 1;
//	p1.m_B = 2;
//
//	Person p2;
//	p2.m_A = 10;
//	p2.m_B = 20;
//	
//	Person p3 = p1 + p2;
//	cout << "p3 m_A="<<p3.m_A << endl;
//	cout << "p3 m_B=" <<p3.m_B << endl;
//}
//
//void test02()
//{
//	Person p1;
//	p1.m_A = 1;
//	p1.m_B = 2;
//
//	Person p2;
//	p2.m_A = 10;
//	p2.m_B = 20;
//
//	Person p3 = p1 + p2;
//	cout << "p3 m_A=" << p3.m_A << endl;
//	cout << "p3 m_B=" << p3.m_B << endl;
//}
//
//int main()
//{
//	//test01();//��Ա��������
//	test01();//ȫ�ֺ�������+
//	system("pause");
//
//	return 0;
//}