#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main5()
{
	/*
		1. const修饰指针——常量指针  const int * p——指向内容不可改
		2. const修饰常量——指针常量  int * const p——指针指向不可改
		3. const修饰指针、常量——const int * const p
	*/
	//常量指针
	int a = 100;
	const int* p = &a;
	//*p=		//常量指针，常量哦，不可改——不能通过*p赋值
	a = 1000;
	cout << *p << endl;

	//
	int a2 = 100;
	int* const p2 = &a2;
	//p2=		//指针常量，不能改指向

	system("pause");

	return 0;
}