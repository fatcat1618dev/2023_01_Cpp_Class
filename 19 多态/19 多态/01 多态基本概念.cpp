//#include<iostream>
//using namespace std;
//
//class Animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "Animal��˵����" << endl;
//	}
//};
//
//class Dog :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "Dog��˵����" << endl;
//	}
//};
//class Cat :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "cat��˵����" << endl;
//	}
//};
//
//void doSpeak(Animal& p)
//{
//	p.speak();
//}
//
//void test01()
//{
//	Dog d;
//	doSpeak(d);
//
//	Cat c;
//	doSpeak(c);
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}