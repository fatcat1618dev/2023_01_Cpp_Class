//#include<iostream>
//using namespace std;
//
//class Animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "Animal在说话！" << endl;
//	}
//};
//
//class Dog :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "Dog在说话！" << endl;
//	}
//};
//class Cat :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "cat在说话！" << endl;
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