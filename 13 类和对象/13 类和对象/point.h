#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;

//Point
class Point2
{
public:
	// ‰»Î°¢ªÒ»°
	void setx(double x);

	double getx();

	void sety(double y);

	double gety();

private:
	double m_x;
	double m_y;
};