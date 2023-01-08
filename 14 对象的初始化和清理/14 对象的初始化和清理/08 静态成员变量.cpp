#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//人
class Person
{
public:
	//初始化列表
	Person()
	{	
		cout << "Person构造函数" << endl;
	}
	~Person()
	{
		cout << "Person析构函数" << endl;
	}
	static string m_Name;

};
string Person::m_Name = "张涛";	//作用域初始化

void test01()
{
	Person p;
	cout << p.m_Name << endl;

	Person p2;
	p2.m_Name = "杨新朋";
	cout << p.m_Name << endl;

	//类名访问
	cout << Person::m_Name << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}