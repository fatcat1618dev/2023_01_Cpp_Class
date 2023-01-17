//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////Person == !=，重载
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		m_Name = name;
//		m_Age = age;
//	}
//	//重构==
//	bool operator == (Person & p)
//	{
//		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	//重构!=
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
//	Person p1("张涛", 18);
//	Person p2("张涛", 18);
//	Person p3("新朋", 16);
//
//	p1 == p2 ? cout << "相等" <<endl: cout << "不等" << endl;
//	p2 != p3 ? cout << "不等" << endl : cout << "相等" << endl;
//
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}