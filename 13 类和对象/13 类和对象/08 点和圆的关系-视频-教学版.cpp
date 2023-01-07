#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//Point
class Point1
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
private:
	double m_x;
	double m_y;
};
//Cicle
class Circle1
{
public:
	//�뾶��Բ��
	//���롢��ȡ
	void setr(double r)
	{
		m_r = r;
	}
	double getr()
	{
		return m_r;
	}
	void setCenter(Point1 center)
	{
		m_Center = center;
	}
	Point1 getCenter()
	{
		return m_Center;
	}
private:

	double m_r;		//�뾶
	Point1 m_Center;	//Բ��
};

//����Բ�ľ�����뾶�ȣ����ֽ��
int flag_rel(Circle1& c, Point1& p)
{
	double tmp = (c.getCenter().getx() - p.getx()) * (c.getCenter().getx() - p.getx()) + (c.getCenter().gety() - p.gety()) * (c.getCenter().gety() - p.gety()) - c.getr() * c.getr();

	if (tmp > 0)	//Բ��
	{
		return 1;
	}
	else //Բ��/��
	{
		return tmp == 0 ? 0 : -1;
	}
}

int main8()
{
	Circle1 c;	//�뾶r��Բ,����(x,y)��
	c.setr(10);
	Point1 center;
	center.setx(0);
	center.sety(0);
	c.setCenter(center);	

	Point1 p;	//����(x,y)���ĵ�
	p.setx(0);
	p.sety(0);

	int ret =flag_rel(c,p);
	if (ret == 1)
	{
		cout << "ȫ�ֺ���������Բ��" << endl;
	}
	else
	{
		(ret == 0) ? (cout << "ȫ�ֺ���������Բ��" << endl) : (cout << "ȫ�ֺ���������Բ��" << endl);
	}
	system("pause");
	return 0;
}