#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//不要返回局部变量引用
int& test04_1()
{
	int a = 10;	//存放在四区 栈区
	return a;
}

//函数调用作为左值
int& test04_2()
{
	static int a = 10;	//存放在四区 栈区
	return a;
}
int main4()
{
	//int &ret = test04_1();
	//cout << "ret=" << ret << endl;		//第一次ok，编译器做了保留
	//cout << "ret=" << ret << endl;		//第二次不ok，a内存已经释放
	
	int& ret = test04_2();
	cout << "ret=" << ret << endl;		
	cout << "ret=" << ret << endl;		
	//函数作为左值赋值
	test04_2() = 1000;
	cout << "ret=" << ret << endl;		
	cout << "ret=" << ret << endl;		

	system("pause");
	return 0;
}