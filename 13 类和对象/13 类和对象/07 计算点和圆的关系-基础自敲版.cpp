#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//Cicle
class Circle
{
public:
	//���롢��ȡ
	void setx(double x)
	{
		m_x = x;
	}
	double getx()
	{
		return m_x;
	}
	void sety(double y)
	{
		m_y = y;
	}
	double gety()
	{
		return m_y;
	}
	void setr(double r)
	{
		m_r = r;
	}
	double getr()
	{
		return m_r;
	}
private:
	double m_x;
	double m_y;
	double m_r;
};
//Point
class Point
{
public:
	//���롢��ȡ
	void setx(double x)
	{
		m_x = x;
	}
	double getx()
	{
		return m_x;
	}
	void sety(double y)
	{
		m_y = y;
	}
	double gety()
	{
		return m_y;
	}
	//����Բ�ľ�����뾶�ȣ����ֽ��
	int flag_rel(Circle& c)
	{
		double tmp = (m_x - c.getx()) * (m_x - c.getx()) + (m_y - c.gety()) * (m_y - c.gety())- c.getr() * c.getr();	
		if (tmp > 0)	//Բ��
		{
			return 1;
		}
		else //Բ��/��
		{
			return tmp == 0 ? 0 : -1;
		}
	}
private:
	double m_x;
	double m_y;
};

int main7()
{
	Circle c;	//����(x,y)���뾶r��Բ
	c.setx(0);
	c.sety(0);
	c.setr(10);

	Point p;	//����(x,y)���ĵ�
	p.setx(12);
	p.sety(0);

	int ret=p.flag_rel(c);
	if (ret == 1)
	{
		cout << "Point��Ա����������Բ��" << endl;
	}
	else
	{
		(ret == 0) ? (cout << "Point��Ա����������Բ��" << endl): (cout << "Point��Ա����������Բ��" << endl);
	}
	system("pause");
	return 0;
}