//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////Person == !=������
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		m_Name = name;
//		m_Age = age;
//	}
//	//�ع�==
//	bool operator == (Person & p)
//	{
//		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	//�ع�!=
//	bool operator != (Person& p)
//	{
//		if (this->m_Name != p.m_Name || this->m_Age != p.m_Age)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	string m_Name;
//	int m_Age;
//};
//
//void test01()
//{
//	Person p1("����", 18);
//	Person p2("����", 18);
//	Person p3("����", 16);
//
//	p1 == p2 ? cout << "���" <<endl: cout << "����" << endl;
//	p2 != p3 ? cout << "����" << endl : cout << "���" << endl;
//
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}