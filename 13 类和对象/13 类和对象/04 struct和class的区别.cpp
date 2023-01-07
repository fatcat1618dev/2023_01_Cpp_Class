#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class C1
{
	int m_A;	//默认private
};
struct C2
{
	int m_A;	//默认public
};
int main4()
{
	//class 权限默认私有
	C1 c1;
	//c1.m_A = 10;	//无法访问

	C2 c2;
	c2.m_A = 100;	//ok

	system("pause");
	return 0;
}