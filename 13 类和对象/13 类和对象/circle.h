#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
#include "point.h"

//Cicle
class Circle2
{
public:
	//�뾶��Բ��
	//���롢��ȡ
	void setr(double r);

	double getr();

	void setCenter(Point2 center);

	Point2 getCenter();

private:

	double m_r;		//�뾶
	Point2 m_Center;	//Բ��
};
