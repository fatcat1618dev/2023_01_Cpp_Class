#define _CRT_SECURE_NO_WARNINGS 1
#include"circle.h"

//Cicle
//�뾶��Բ��
//���롢��ȡ
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