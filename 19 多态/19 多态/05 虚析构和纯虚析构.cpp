//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Animal
//{
//public:
//	Animal()
//	{
//		cout << "Animal����" << endl;
//	}
//	virtual ~Animal()
//	{
//		cout << "Animal����" << endl;
//	}
//	virtual void speak() = 0;//����
//};
//
//class Cat:public Animal
//{
//public:
//	Cat(string name)
//	{
//		cout << "Cat����" << endl;
//		m_Name = new string(name);
//	}
//	~Cat()
//	{
//		cout << "Cat����" << endl;
//		delete m_Name;					//δ�߸��д���
//		m_Name = NULL;
//
//	}
//	void speak()
//	{
//		cout <<*m_Name<< "Сè��˵����" << endl;
//	}
//	string *m_Name;
//};
//
//void test01()
//{
//	Animal *p=new Cat("Tom");
//	p->speak();
//	delete p;		//�ͷŲ�����
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}