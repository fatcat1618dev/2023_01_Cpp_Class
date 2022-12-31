#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main1() {

	//if
	//输入分数，600及以上985，否则回家养猪吧

	float score = 600.5f;
	cout << "请输入分数：";
	cin >> score;

	if (score >= 600)
	{
		cout << "恭喜考上985！" << endl;
	}
	else
	{
		cout << "回家养猪吧！" << endl;
	}

	system("pause");

	return 0;
}