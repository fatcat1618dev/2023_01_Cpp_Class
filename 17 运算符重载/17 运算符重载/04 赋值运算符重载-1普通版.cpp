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
//	Person(int a) :m_A(a){}
//	void showValue()
//	{
//		cout << "�ڲ�ֵ=" << m_A << endl;
//	}
//private:
//	int m_A;
//};
//
////����<<����
//ostream& operator<<(ostream&cout,Person&p)
//{
//	cout << p.m_A;
//	return cout;
//}
////����01
//void test01()
//{
//	Person p1(10);
//	p1.showValue();
//
//}
//void test02()	//��Ա����
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
//void test03()	//<<��=���������
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
//	cout << "1.��ͨ" << endl;
//	test01();//������ֵ����ʾ
//
//	cout << "2.��Ա����" << endl;
//	test02();
//
//	//test03
//	cout << "3.��������ء�������<<	��ֵ=����" << endl;
//	test03();
//
//	system("pause");
//	return 0;
//}