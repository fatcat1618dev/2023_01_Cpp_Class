//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////p3(30)=p2(20)=p1(10)	���ȣ���ʽ���
//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);	//��Ԫ
//
//public:
//	//�б�
//	Person(int a)
//	{
//		m_A = new int(a);		//���������
//	}
//
//	//= ��Ա����������
//	Person& operator=(Person& p)
//	{
//		if (m_A != NULL)
//		{
//			delete m_A;
//			m_A = NULL;
//		}
//		m_A = new int(*p.m_A);
//		return *this;
//	}
//	~Person()
//	{
//		if (m_A != NULL)
//		{
//			delete m_A;
//			m_A = NULL;
//		}
//	}
//
//	int *m_A;
//};
//
////����<<����
//ostream& operator<<(ostream& cout, Person& p)
//{
//	cout << *p.m_A;
//	return cout;
//}
//
//
//
////����01
//void test01()
//{
//	Person p1(10);
//	cout << p1 << endl;
//}
//
//void test02()	//<<	=���������
//{
//
//	Person p1(2);
//	Person p2(4);
//	Person p3(6);
//	p3 = p2 = p1;
//	cout << p2 << endl;
//	cout << p3 << endl;
//
//}
//int main()
//{
//	cout << "1.��ͨ" << endl;
//	test01();//������ֵ����ʾ
//
//	cout << "2.��������ء�������<<	��ֵ=����" << endl;
//	test02();
//
//	system("pause");
//	return 0;
//}