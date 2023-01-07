#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//Point
class Point1
{
public:
	//输入、获取
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
	//半径、圆心
	//输入、获取
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

	double m_r;		//半径
	Point1 m_Center;	//圆心
};

//点离圆心距离跟半径比，三种结果
int flag_rel(Circle1& c, Point1& p)
{
	double tmp = (c.getCenter().getx() - p.getx()) * (c.getCenter().getx() - p.getx()) + (c.getCenter().gety() - p.gety()) * (c.getCenter().gety() - p.gety()) - c.getr() * c.getr();

	if (tmp > 0)	//圆外
	{
		return 1;
	}
	else //圆上/内
	{
		return tmp == 0 ? 0 : -1;
	}
}

int main8()
{
	Circle1 c;	//半径r的圆,坐标(x,y)处
	c.setr(10);
	Point1 center;
	center.setx(0);
	center.sety(0);
	c.setCenter(center);	

	Point1 p;	//坐标(x,y)处的点
	p.setx(0);
	p.sety(0);

	int ret =flag_rel(c,p);
	if (ret == 1)
	{
		cout << "全局函数：点在圆外" << endl;
	}
	else
	{
		(ret == 0) ? (cout << "全局函数：点在圆上" << endl) : (cout << "全局函数：点在圆内" << endl);
	}
	system("pause");
	return 0;
}