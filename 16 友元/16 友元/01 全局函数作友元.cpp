//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////全局函数作友元
//class House
//{
//	//goodguy是house好朋友，权限放开
//	friend void goodguy(House* house);	//声明？
//public:
//	House():m_LivingRoom("客厅"),m_BedRoom("卧室") {}		//列表初始化
//	//House()
//	//{
//	//	m_LivingRoom = "客厅";
//	//	m_BedRoom = "卧室";
//	//}
//public:
//	string m_LivingRoom;
//private:
//	string m_BedRoom;
//};
//
////全局函数
//void goodguy(House* house)			//指针或引用都可
//{
//	cout << "好基友	全局函数	正在访问：" << house->m_LivingRoom << endl;
//	cout << "好基友	全局函数	正在访问：" << house->m_BedRoom << endl;
//
//} 
//void test01()
//{
//	House h;
//	goodguy(&h);
//
//}
//int main()
//{
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}