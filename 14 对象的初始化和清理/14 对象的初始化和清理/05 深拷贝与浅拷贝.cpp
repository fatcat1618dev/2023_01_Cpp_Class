//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person()
//	{
//		cout << "默认构造函数" << endl;
//	}
//	Person(int age,int height)
//	{
//		m_Age = age;
//		m_Height = new int(height);
//		cout << "有参构造函数" << endl;
//	}
//	Person(const Person& p)
//	{
//		m_Age = p.m_Age;
//		//m_Height = p.m_Height;	
//
//		//深拷贝
//		m_Height = new int(*p.m_Height);	//内容一样，指向不一样
//		cout << "COPY构造函数" << endl;
//	}
//
//	~Person()
//	{
//		//析构代码，释放堆区开辟的数据
//		if (m_Height != NULL)
//		{
//			delete m_Height;
//			m_Height = NULL;	//置空，防野指针
//		}
//		cout << "析构函数" << endl;
//	}
//	int m_Age;
//	int* m_Height;
//};
//
////用系统的copy构造
//void test01()
//{
//	Person p1(18,160);
//	Person p2(p1);	//系统copy函数			浅copy
//	cout << "p2年龄：" << p2.m_Age << endl;
//}
//
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}