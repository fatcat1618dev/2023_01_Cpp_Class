#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//����
class Person_
{
public:
	//����
	void setLover(string lover)
	{
		if (lover !=  "canglaoshi")
		{
			cout << "Invalid��" << endl;
			return;
		}
		m_lover = lover;
	}
	string getLover()
	{
		cout << "��Ч����ʦΪ��";
		return m_lover;
	}
private:
	string m_lover;
};
int main5()
{
	Person_ p;
	cout << "��ѡ����ʦ��";
	string lover;
	cin >> lover;
	p.setLover(lover);
	cout << p.getLover() << endl;;

	system("pause");
	return 0;
}