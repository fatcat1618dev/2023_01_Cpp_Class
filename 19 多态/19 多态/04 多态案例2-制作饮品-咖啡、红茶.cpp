//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////基类、纯虚函数
//class MakeDrink
//{
//public:
//	//煮水
//	virtual void Boil() = 0;
//	//冲泡
//	virtual void Brew() = 0;
//	//倒入杯中
//	virtual void Pour() = 0;
//	//加入辅料
//	virtual void AddSometing() = 0;
//	void makeDrink()
//	{
//		Boil();
//		Brew();
//		Pour();
//		AddSometing();
//	}
//};
//
////咖啡
//class makeCoffee :public MakeDrink
//{
//	//煮水
//	virtual void Boil()
//	{
//		cout << "煮纯净水..." << endl;
//	}
//	//冲泡
//	virtual void Brew()
//	{
//		cout << "冲泡咖啡..." << endl;
//	}
//	//倒入杯中
//	virtual void Pour()
//	{
//		cout << "倒入瓷杯..." << endl;
//	}
//	//加入辅料
//	virtual void AddSometing()
//	{
//		cout << "加糖、牛奶..." << endl;
//	}
//};
//
////红茶
//class makeBlackTea :public MakeDrink
//{
//	//煮水
//	virtual void Boil()
//	{
//		cout << "煮矿泉水..." << endl;
//	}
//	//冲泡
//	virtual void Brew()
//	{
//		cout << "冲泡红茶..." << endl;
//	}
//	//倒入杯中
//	virtual void Pour()
//	{
//		cout << "倒入茶具中..." << endl;
//	}
//	//加入辅料
//	virtual void AddSometing()
//	{
//		cout << "加入柠檬..." << endl;
//	}
//};
//
//void doWork(MakeDrink* p)
//{
//	p->makeDrink();
//}
//
//
//void test01()
//{
//	cout << "..........制作咖啡.........." << endl;
//	doWork(new makeCoffee);
//	cout << "..........制作红茶.........." << endl;
//	doWork(new makeBlackTea);
//
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}