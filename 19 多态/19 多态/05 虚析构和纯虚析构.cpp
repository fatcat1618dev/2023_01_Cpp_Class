//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Animal
//{
//public:
//	Animal()
//	{
//		cout << "Animal构造" << endl;
//	}
//	virtual ~Animal()
//	{
//		cout << "Animal析构" << endl;
//	}
//	virtual void speak() = 0;//纯虚
//};
//
//class Cat:public Animal
//{
//public:
//	Cat(string name)
//	{
//		cout << "Cat构造" << endl;
//		m_Name = new string(name);
//	}
//	~Cat()
//	{
//		cout << "Cat析构" << endl;
//		delete m_Name;					//未走该行代码
//		m_Name = NULL;
//
//	}
//	void speak()
//	{
//		cout <<*m_Name<< "小猫在说话！" << endl;
//	}
//	string *m_Name;
//};
//
//void test01()
//{
//	Animal *p=new Cat("Tom");
//	p->speak();
//	delete p;		//释放才析构
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}