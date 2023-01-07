#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//设计一个圆类，求圆的周长
//2*PI*r
const double PI = 3.141592653;

//class代表设计一个类，类后面跟着类名称
class Circle
{
	//访问权限
	//公共权限
public:

	//属性
	//半径
	double r;

	//行为
	//周长
	double cal_circumference()
	{
		return 2 * PI * r;
	}
};

int main1()
{
	//实例化
	Circle c1;
	//对象赋值
	c1.r = 10;
	cout << "圆周长为：" << c1.cal_circumference() << endl;

	system("pause");
	return 0;
}