#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void show()
{
	cout << "*************************************" << endl;
	cout << "******* 欢迎使用职工管理系统！*******" << endl;
	cout << "*** 0.退出管理系统 1.增加职工信息 ***" << endl;
	cout << "*** 2.显示职工信息 3.删除离职职工 ***" << endl;
	cout << "*** 4.修改职工信息 5.查找职工信息 ***" << endl;
	cout << "*** 6.按照编号排序 7.清空所有信息 ***" << endl;
	cout << "*************************************" << endl;

}

int main()
{
	int a=1;

	while (a)
	{
		show();
		cout << "选择：" << endl;
		cin >> a;

		switch (a)
		{
		case 0:
			cout << "欢迎下次使用" << endl;
			break;
		case 1:
			cout << "增加职工信息" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "显示职工信息" << endl;
			system("pause");
			system("cls");
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}