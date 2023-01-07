#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//Cicle
class Circle
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
	//点离圆心距离跟半径比，三种结果
	int flag_rel(Circle& c)
	{
		double tmp = (m_x - c.getx()) * (m_x - c.getx()) + (m_y - c.gety()) * (m_y - c.gety())- c.getr() * c.getr();	
		if (tmp > 0)	//圆外
		{
			return 1;
		}
		else //圆上/内
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
	Circle c;	//坐标(x,y)处半径r的圆
	c.setx(0);
	c.sety(0);
	c.setr(10);

	Point p;	//坐标(x,y)处的点
	p.setx(12);
	p.sety(0);

	int ret=p.flag_rel(c);
	if (ret == 1)
	{
		cout << "Point成员函数：点在圆外" << endl;
	}
	else
	{
		(ret == 0) ? (cout << "Point成员函数：点在圆上" << endl): (cout << "Point成员函数：点在圆内" << endl);
	}
	system("pause");
	return 0;
}