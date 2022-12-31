#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main7() {

	//给电影打分
	//9-10	经典
	//8		优秀
	//6-7	一般
	//其它	烂片
	cout << "请打分：";
	int score = 0;
	cin >> score;

	if (score <= 10 && score >= 1)
	{
		switch (score)
		{
		case 10:
		case 9:
			cout << "经典" << endl;
			break;
		case 8:
			cout << "优秀" << endl;
			break;
		case 7:
		case 6:
			cout << "一般" << endl;
			break;
		default:
			cout << "烂片" << endl;
			break;
		}
	}
	else
	{
		cout << "打分无效！" << endl;
	}

	system("pause");

	return 0;
}