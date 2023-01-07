#define _CRT_SECURE_NO_WARNINGS 1
#include"circle.h"

//Cicle
//半径、圆心
//输入、获取
void Circle2::setr(double r)
{
	m_r = r;
}
double Circle2::getr()
{
	return m_r;
}
void Circle2::setCenter(Point2 center)
{
	m_Center = center;
}
Point2 Circle2::getCenter()
{
	return m_Center;
}