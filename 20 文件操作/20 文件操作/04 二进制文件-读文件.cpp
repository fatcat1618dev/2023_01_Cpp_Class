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
	//2.����������
	ifstream ifs("Person.txt", ios::out | ios::binary);

	//3.���ļ�,�ж��Ƿ�򿪳ɹ���
	/*ifs.open("Person.txt", ios::out | ios::binary);*/
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	
	//4.������
	Person p;
	ifs.read((char*)&p, sizeof(p));

	cout << "������" << p.m_Name << " ���䣺" << p.m_Age << endl;;

	//5.�ر��ļ�
	ifs.close();
}
int main()
{
	test01();

	system("pause");
	return 0;
}