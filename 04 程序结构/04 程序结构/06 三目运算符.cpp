#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main6() {

	//max

	int num1 = 100;
	int num2 = 90;

	cout << "最大值为："<<(num1>num2 ? num1:num2)<<endl;

	//再赋值
	cout << "最大值为：" << ((num1 > num2 ? num1 : num2)=1000) << endl;

	system("pause");

	return 0;
}