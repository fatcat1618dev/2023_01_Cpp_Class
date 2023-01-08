#include<iostream>
using namespace std;

//常函数
class Person
{
public:

	//this指针的本质 指针常量 指向不可改
	//const Person* const this
	Person() :m_Age(18), m_B(22) {}

	void showPersonAge() const
	{
		//m_Age = 100;	//不可改
		//m_B = 100;
		cout << m_B << endl;
	}
	void func(){}

	int m_Age;
	mutable int m_B;
};

void test01()
{
	Person p1;
	p1.showPersonAge();
}

//常对象
void test02()
{
	const Person p2;	//变为常对象
	//p2.m_Age = 100;		
	p2.m_B = 99;		//mutable
	p2.showPersonAge();

	//常对象只能调常函数
	//p2.func();
}
int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}