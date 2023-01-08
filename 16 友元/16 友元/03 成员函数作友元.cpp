#define _crt_secure_no_warnings 1
#include<iostream>
using namespace std;

//类做友元，好基友访问客厅、卧室
class house;
class goodguy
{
public:
	goodguy();
	~goodguy();
	//访问行为
	void visit1();
	void visit2();
	//房子指针
	house* h;
};

class house
{
	//friend class goodguy;	//好朋友
	friend void goodguy::visit1();
public:
	house();
	~house();
public:
	string m_livingroom;
private:
	string m_bedroom;
};

//类外成员函数
//列表初始化构造函数
house::house() :m_livingroom("客厅"), m_bedroom("卧室") { cout << "house 构造" << endl; };
house::~house()
{
	cout << "house 析构 " << endl;
}
goodguy::goodguy()
{
	h = new house();			//无参构造
	cout << "goodguy 构造！" << endl;
}
goodguy::~goodguy()
{
	cout << "goodguy	析构	堆区的house数据" << endl;
	if (h != NULL )
	{
		delete h;
		h = NULL;
	}
}
void goodguy::visit1()
{
	cout << "好基友类 正在访问 " << h->m_livingroom << endl;
	cout << "好基友类 正在访问 " << h->m_bedroom << endl;			//可访问卧室了

}

void goodguy::visit2()
{
	cout << "好基友类 正在访问 " << h->m_livingroom << endl;
	//cout << "好基友类 正在访问 " << h->m_bedroom << endl;			//可访问卧室了

}
//测试案例
void test01()
{
	goodguy gg;
	gg.visit1();
	gg.visit2();
}
int main()
{
	test01();

	system("pause");
	return 0;
}