//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////
//class Person
//{
//public:
//	Person(int age)
//	{
//		//this指向被调用的成员函数所属的对象,成员函数p1
//		this->age = age;
//	}
//
//	//引用 链式编程
//	Person& PersonAddAge(Person& p)
//	{
//		this->age += p.age;
//		return *this;	//返回本身
//	}
//
//	//值返回——拷贝构造 副本
//	Person PersonAddAge1(Person& p)
//	{
//		this->age += p.age;
//		return *this;	//返回本身
//	}
//	int age;
//};
//
////1.解决名称冲突
////方法1：编码规范 m_age
////方法2：this指针
//void test01()
//{
//	Person p1(18);	//有参构造
//	cout << "年龄为：" << p1.age << endl;
//}
//
////2.返回对象本身*this
//
//void test02()
//{
//	Person p2(20);
//	Person p3(10);
//	p2.PersonAddAge(p3).PersonAddAge(p2);	//20+10+30
//	cout << "p3年龄：" << p2.age << endl;
//}
//
//void test03()
//{
//	Person p2(20);
//	Person p3(10);
//	p2.PersonAddAge1(p3).PersonAddAge1(p2);	//拷贝构造,1次后就copy副本
//	cout << "p3年龄：" << p2.age << endl;
//}
//
//int main()
//{
//	test01();	//
//	test02();	//链式访问
//	test03();
//
//	system("pause");
//	return 0;
//}