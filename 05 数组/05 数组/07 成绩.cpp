#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main() {

	/*
		考试成绩统计：分别输出3名同学的总成绩
	*/
	int arr[][3] =
	{
		{100,100,100},
		{90,50,100},
		{60,70,80}
	};
	
	string names[] = { "张三","李四","王五" };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	//总成绩
	int sum[3] = { 0,0,0 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum[i]+=arr[i][j];
		}
		cout << names[i]<<"的总分为："<<sum[i] << endl;
	}

	system("pause");

	return 0;
}