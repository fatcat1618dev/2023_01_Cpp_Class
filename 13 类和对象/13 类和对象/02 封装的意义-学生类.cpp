#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//ѧ����
class Students
{
	//����Ȩ��
public:

	//���е����Ժ���Ϊ��ͳһ��Ϊ ��Ա
	//����	��Ա���� ��Ա����
	//��Ϊ	��Ա���� ��Ա����
	string m_Name;
	int m_ID;
	//��Ϊ
	void showinfo()
	{
		cout << "������" << m_Name
			<< "\tѧ�ţ�" << m_ID << endl;
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
	s1.m_Name = "����";
	s1.m_ID = 10086;
	s1.showinfo();

	s1.setName("������");
	s1.setID(10010);
	s1.showinfo();

	system("pause");
	return 0;
}