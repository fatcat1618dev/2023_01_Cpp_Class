//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Ĭ�Ϲ��캯��" << endl;
//	}
//	Person(int age,int height)
//	{
//		m_Age = age;
//		m_Height = new int(height);
//		cout << "�вι��캯��" << endl;
//	}
//	Person(const Person& p)
//	{
//		m_Age = p.m_Age;
//		//m_Height = p.m_Height;	
//
//		//���
//		m_Height = new int(*p.m_Height);	//����һ����ָ��һ��
//		cout << "COPY���캯��" << endl;
//	}
//
//	~Person()
//	{
//		//�������룬�ͷŶ������ٵ�����
//		if (m_Height != NULL)
//		{
//			delete m_Height;
//			m_Height = NULL;	//�ÿգ���Ұָ��
//		}
//		cout << "��������" << endl;
//	}
//	int m_Age;
//	int* m_Height;
//};
//
////��ϵͳ��copy����
//void test01()
//{
//	Person p1(18,160);
//	Person p2(p1);	//ϵͳcopy����			ǳcopy
//	cout << "p2���䣺" << p2.m_Age << endl;
//}
//
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}