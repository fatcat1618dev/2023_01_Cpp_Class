#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void func05(int& ref)		//自动转为，int* const ref=&a;
{
	ref = 99;				//内部转，*ref=99
}
int main5()
{
	int a = 10;

	int& ref = a;		//自动转换为 int* const ref=&a;指针指向不可改，即引用不可更改
	ref = 100;			//自动内部发现是引用，自动转为*ref=100

	cout << "a=" << a << endl;
	cout << "ret=" << ref << endl;

	func05(a);
	cout << "a=" << a << endl;

	system("pause");
	return 0;
}