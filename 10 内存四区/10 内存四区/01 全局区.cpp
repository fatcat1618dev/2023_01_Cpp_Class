#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;

//const修饰的全局变量，全局常量 
const int c_g_a = 10;
const int c_g_b = 10;

int main1()
{
	//局部变量
	int a = 10;
	int b = 10;
	cout << "局部变量a的地址：" << (int)&a << endl;
	cout << "局部变量a的地址：" << (int)&a << endl;

	//全局变量
	cout << "全局变量a的地址：" << (int)&g_a << endl;
	cout << "全局变量a的地址：" << (int)&g_b << endl;

	//静态变量
	static int s_a = 10;
	static int s_b = 10;
	cout << "静态变量s_a的地址为：" << (int)&s_a << endl;
	cout << "静态变量s_b的地址为：" << (int)&s_b << endl;

	//常量
	//字符串常量
	cout << "字符串常量的地址：" << (int)&"hello world" << endl;

	//const修饰的变量
	//全局变量、局部变量
	cout << "const修饰的全局变量c_g_a：" << (int)&c_g_a << endl;
	cout << "const修饰的全局变量c_g_b：" << (int)&c_g_b << endl;

	//局部常量
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "const修饰的局部变量c_l_a：" << (int)&c_l_a << endl;
	cout << "const修饰的局部变量c_l_a：" << (int)&c_l_b << endl;

	system("pause");
	return 0;
}