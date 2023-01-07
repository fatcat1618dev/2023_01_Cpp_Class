#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//立方体类
class Cube
{

public:
	//设置长、获取长
	void setL(double L)
	{
		m_L = L;
	}
	double getL()
	{
		return m_L;
	}
	// 设置宽、获取宽
	void setW(double W)
	{
		m_W = W;
	}
	double getW()
	{
		return m_W;
	}
	// 设置高、获取高
	void setH(double H)
	{
		m_H = H;
	}
	double getH()
	{
		return m_H;
	}
	//area
	double cal_area()							//cal_S
	{
		return (m_L * m_W +m_L* m_H+m_W*m_H)*2;	//6个面
	}
	//volume
	double cal_volume()							//cal_V
	{
		return m_L * m_W * m_H;
	}
	//成员函数
	bool isSame_class(Cube& c1)
	{
		if (c1.cal_area() ==cal_area() && c1.cal_volume() == cal_volume())	//和类内比
		{
			return true;
		}
		return false;
	}

private:
	double m_L;
	double m_W;
	double m_H;
};

//全局函数
//面积、体积都一样，返回1，一致
//否则返回false,不一样

bool isSame_global(Cube& c1, Cube &c2)
{
	if (c1.cal_area() == c2.cal_area() && c1.cal_volume() == c2.cal_volume())
	{
		return true;
	}
	return false;
}

int main6()
{
	Cube c1;
	c1.setL(2);
	c1.setW(4);
	c1.setH(8);
	cout << "面积area：" << c1.cal_area() << endl;
	cout << "体积area：" << c1.cal_volume() << endl;

	Cube c2;
	c2.setL(4);
	c2.setW(8);
	c2.setH(1);
	cout << "面积area：" << c2.cal_area() << endl;
	cout << "体积area：" << c2.cal_volume() << endl;

	//全局函数
	(isSame_global(c1, c2) == 1) ? cout << "全局函数：立方体一样！" << endl: cout << "全局函数：立方体不同！" << endl;

	//成员函数	传1个参数即可，+引用
	(c1.isSame_class(c2) == 1) ? cout << "Class成员函数：立方体一样！" << endl : cout << "Class成员函数：立方体不同！" << endl;

	system("pause");
	return 0;
}