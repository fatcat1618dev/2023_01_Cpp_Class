#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//基本语法
int* func3()
{
	return new int(10);	//new关键字，指针
}
void test03()
{
	cout << *func3() << endl;	//地址解引用
	delete func3();
}

//开辟数组
void test04()
{
	int* arr=new int[10];	//堆区，数组

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i * i;
		cout << arr[i]<<" ";
	}
	cout << endl;
	
	//释放堆数组
	delete[] arr;
}

int main()
{
	test03();	//基本语法
	//test04();	//开辟数组

	system("pause");
	return 0;
}