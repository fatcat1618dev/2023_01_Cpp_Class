//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////空指针调用成员函数
//class Person
//{
//public:
//	Person():m_Age(18)
//	{
//		;
//	}
//	void showClassName()
//	{
//		cout << "This is Person Class!" << endl;
//	}
//	
//	void showAge()
//	{
//		if (this == NULL)
//		{
//			return;
//		}
//		cout << "Age=" << m_Age << endl;
//	}
//	int m_Age;
//};
//
//void test01()
//{
//	Person p;
//	p.showClassName();
//	p.showAge();			//空指针 还访问里面的成员，无中生有
//
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}