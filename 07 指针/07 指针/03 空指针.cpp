#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main3()
{
	//
	int* p = NULL;

	//空指针不可访问
	//内存编号0~255为系统占用内存，不允许访问
	//*p=100;	//非法

	system("pause");

	return 0;
}