#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<ctime>

int main9() {

	//随机种子
	srand((unsigned int)time(NULL));
	//伪随机数
	int num = rand() % 100 + 1;//0-99	+1,随机数
	cout << num << endl;

	int guess = 0;

	while (1)
	{
		cout << "请猜数字";
		cin >> guess;

		if (guess < num)
		{
			cout << "小了" << endl;
		}
		else if(guess > num)
		{
			cout << "大了" << endl;
		}
		else
		{
			cout << "对了" << endl;
			break;
		}
	}

	system("pause");

	return 0;
}