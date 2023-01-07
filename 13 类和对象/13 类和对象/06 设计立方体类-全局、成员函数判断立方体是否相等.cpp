#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��������
class Cube
{

public:
	//���ó�����ȡ��
	void setL(double L)
	{
		m_L = L;
	}
	double getL()
	{
		return m_L;
	}
	// ���ÿ���ȡ��
	void setW(double W)
	{
		m_W = W;
	}
	double getW()
	{
		return m_W;
	}
	// ���øߡ���ȡ��
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
		return (m_L * m_W +m_L* m_H+m_W*m_H)*2;	//6����
	}
	//volume
	double cal_volume()							//cal_V
	{
		return m_L * m_W * m_H;
	}
	//��Ա����
	bool isSame_class(Cube& c1)
	{
		if (c1.cal_area() ==cal_area() && c1.cal_volume() == cal_volume())	//�����ڱ�
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

//ȫ�ֺ���
//����������һ��������1��һ��
//���򷵻�false,��һ��

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
	cout << "���area��" << c1.cal_area() << endl;
	cout << "���area��" << c1.cal_volume() << endl;

	Cube c2;
	c2.setL(4);
	c2.setW(8);
	c2.setH(1);
	cout << "���area��" << c2.cal_area() << endl;
	cout << "���area��" << c2.cal_volume() << endl;

	//ȫ�ֺ���
	(isSame_global(c1, c2) == 1) ? cout << "ȫ�ֺ�����������һ����" << endl: cout << "ȫ�ֺ����������岻ͬ��" << endl;

	//��Ա����	��1���������ɣ�+����
	(c1.isSame_class(c2) == 1) ? cout << "Class��Ա������������һ����" << endl : cout << "Class��Ա�����������岻ͬ��" << endl;

	system("pause");
	return 0;
}