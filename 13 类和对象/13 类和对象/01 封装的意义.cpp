#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//���һ��Բ�࣬��Բ���ܳ�
//2*PI*r
const double PI = 3.141592653;

//class�������һ���࣬��������������
class Circle
{
	//����Ȩ��
	//����Ȩ��
public:

	//����
	//�뾶
	double r;

	//��Ϊ
	//�ܳ�
	double cal_circumference()
	{
		return 2 * PI * r;
	}
};

int main1()
{
	//ʵ����
	Circle c1;
	//����ֵ
	c1.r = 10;
	cout << "Բ�ܳ�Ϊ��" << c1.cal_circumference() << endl;

	system("pause");
	return 0;
}