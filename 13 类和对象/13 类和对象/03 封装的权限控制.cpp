#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//访问权限
//三种
//pulic			成员 类内可 类外可  访问
//protected		成员 类内可 类外不可		继承	儿子可以访问父亲中的保护内容
//private		成员 类内可	类外不可				儿子不可访问父亲的私有内容

class Person
{
public:
	string m_Name;
protected:
	string m_Car;
private:
	int m_Password;
public:
	void func()
	{
		m_Name = "张涛";
		m_Car = "迈巴赫";
		m_Password = 123456;
	}
};
int main3()
{
	Person p1;
	p1.m_Name = "杨新朋";
	//p1.m_car = "宝马";
	//p1.m_password = 125436;

	system("pause");
	return 0;
}