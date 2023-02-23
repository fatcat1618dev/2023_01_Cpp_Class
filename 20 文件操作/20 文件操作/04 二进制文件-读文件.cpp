#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>

class Person
{
public:
	char m_Name[64];
	int m_Age;

};

void test01()
{
	//2.创建流对象
	ifstream ifs("Person.txt", ios::out | ios::binary);

	//3.打开文件,判断是否打开成功！
	/*ifs.open("Person.txt", ios::out | ios::binary);*/
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	
	//4.读数据
	Person p;
	ifs.read((char*)&p, sizeof(p));

	cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;;

	//5.关闭文件
	ifs.close();
}
int main()
{
	test01();

	system("pause");
	return 0;
}