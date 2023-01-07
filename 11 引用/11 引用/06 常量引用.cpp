#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//引用、const
void showvalue(const int& a)
{
	//a=10;				//不可改
	cout << a << endl;
}
int main()
{

	//函数中使用常量引用，防止误操作修改实参
	//比如打印数据
	int a = 10;
	showvalue(a);

	system("pause");
	return 0;
}