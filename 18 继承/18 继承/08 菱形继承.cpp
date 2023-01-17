#include<iostream>
using namespace std;

//动物
class Animal
{
public:
	int m_Age = 10;
};
//羊
class Sheep :virtual public Animal{};
//驼
class Camel :virtual public Animal{};
//草泥马
class Alpaca:public Sheep,public Camel {};

void test01()
{
	Alpaca yt;
	//菱形继承，父类相同数据，加作用域区分
	yt.Sheep::m_Age = 6;
	yt.Camel::m_Age = 3;

	//菱形继承相同数据有两份，资源浪费
	//virtual关键字，虚继承	虚基指针
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