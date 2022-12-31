#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main() {

	//1.整型
	int a = 0;
	cout << "请输入整型值：";
	cin >> a;
	cout << "整型值为：" << a << endl;

	//2.浮点型
	float f1 = 3.14f;
	cout << "请输入小数：";
	cin >> f1;
	cout << "小数为：" << f1 << endl;

	//3.字符
	char ch = 'b';
	cout << "请输入字符：";
	cin >> ch;
	cout << "字符为：" << ch << endl;

	//4.字符串
	string str = "HAOMO.AI";
	cout << "请输入字符串：";
	cin >> str;
	cout << "字符串为：" << str << endl;

	//5.布尔类型
	bool flag = true;
	cout << "请赋值flag：";
	cin >> flag;		//非零都代表真
	cout << "flag为：" << flag << endl;

	system("pause");

	return 0;
}