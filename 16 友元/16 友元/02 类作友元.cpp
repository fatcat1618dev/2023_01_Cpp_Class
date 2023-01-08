//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////类做友元，好基友访问客厅、卧室
//class House;
//class Goodguy
//{
//public:
//	Goodguy();
//	~Goodguy();
//	//访问行为
//	void visit();
//	//房子指针
//	House* h;
//};
//
//class House
//{
//	friend class Goodguy;	//好朋友
//public:
//	House();
//	~House();
//public:
//	string m_Livingroom;
//private:
//	string m_Bedroom;
//};
//
////类外成员函数
////列表初始化构造函数
//House::House() :m_Livingroom("客厅"), m_Bedroom("卧室") { cout << "House 构造" << endl; };
//House::~House()
//{
//	cout << "House 析构 " << endl;
//}
//Goodguy::Goodguy()
//{
//	h = new House();			//无参构造
//	cout << "Goodguy 构造！" << endl;
//}
//Goodguy::~Goodguy()
//{
//	cout << "Goodguy	析构	堆区的house数据" << endl;
//	if (h != NULL)
//	{
//		delete h;
//		h = NULL;
//	}
//}
//void Goodguy::visit()
//{
//	cout << "好基友类 正在访问 " << h->m_Livingroom << endl;
//	cout << "好基友类 正在访问 " << h->m_Bedroom << endl;			//可访问卧室了
//
//}
//
////测试案例
//void test01()
//{
//	Goodguy gg;
//	gg.visit();
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}