#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//人类
class Person_
{
public:
	//情人
	void setLover(string lover)
	{
		if (lover !=  "canglaoshi")
		{
			cout << "Invalid！" << endl;
			return;
		}
		m_lover = lover;
	}
	string getLover()
	{
		cout << "有效，老师为：";
		return m_lover;
	}
private:
	string m_lover;
};
int main5()
{
	Person_ p;
	cout << "请选择老师：";
	string lover;
	cin >> lover;
	p.setLover(lover);
	cout << p.getLover() << endl;;

	system("pause");
	return 0;
}