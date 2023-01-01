#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main6() {

	/*
		数据类型 数组名[行数][列数];
		数据类型 数组名[行数][列数]={{a,b},{c,d}};
		数据类型 数组名[行数][列数]={a,b,c,d};
		数据类型 数组名[][列数]={a,b,c,d};
	*/
	int arr[2][3] =
	{
		{1,3,5},
		{2,4,6}
	};

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");

	return 0;
}