#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//学生类
class Students
{
	//访问权限
public:

	//类中的属性和行为：统一称为 成员
	//属性	成员属性 成员变量
	//行为	成员函数 成员方法
	string m_Name;
	int m_ID;
	//行为
	void showinfo()
	{
		cout << "姓名：" << m_Name
			<< "\t学号：" << m_ID << endl;
	}
	//setName
	//setID
	void setName(string name)
	{
		m_Name = name;
	}
	void setID(int id)
	{
		m_ID = id;
	}
};

int main2()
{
	Students s1;
	s1.m_Name = "张涛";
	s1.m_ID = 10086;
	s1.showinfo();

	s1.setName("杨新朋");
	s1.setID(10010);
	s1.showinfo();

	system("pause");
	return 0;
}