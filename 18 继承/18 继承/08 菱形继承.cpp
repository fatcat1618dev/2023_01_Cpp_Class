#include<iostream>
using namespace std;

//����
class Animal
{
public:
	int m_Age = 10;
};
//��
class Sheep :virtual public Animal{};
//��
class Camel :virtual public Animal{};
//������
class Alpaca:public Sheep,public Camel {};

void test01()
{
	Alpaca yt;
	//���μ̳У�������ͬ���ݣ�������������
	yt.Sheep::m_Age = 6;
	yt.Camel::m_Age = 3;

	//���μ̳���ͬ���������ݣ���Դ�˷�
	//virtual�ؼ��֣���̳�	���ָ��
	cout << "Animal "<<yt.m_Age << endl;
	cout << "Sheep " << yt.m_Age << endl;
	cout << "Camel " << yt.m_Age << endl;

}
int main()
{
	test01();

	system("pause");
	return 0;
}