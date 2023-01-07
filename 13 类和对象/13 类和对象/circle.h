#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
#include "point.h"

//Cicle
class Circle2
{
public:
	//半径、圆心
	//输入、获取
	void setr(double r);

	double getr();

	void setCenter(Point2 center);

	Point2 getCenter();

private:

	double m_r;		//半径
	Point2 m_Center;	//圆心
};
