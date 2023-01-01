#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main5() {

	/*
		常用的排序算法，升序排列，如{4,2,8,0,5,7,1,3,9}
	*/
	//int arr[] = { 4,2,8,0,5,7,1,3,9 };
	int arr[] = { 9,8,7,5,4,3,2,1,0 };
	//int arr[] = { 1,2,3,4,5,6,7,9,8 };

	cout << "排序前：";
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	int lunshu = 0;
	int cishu = 0;

	for (int j = 0; j < len-1; j++)	//外层轮数，元素个数-1
	{
		bool flag = 0;					//交换标志位

		for (int i = 0; i < len-1-j; i++)	//内层次数，元素个数-1-轮数
		{
			int tmp = 0;
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = 1;				//交换中
				cishu++;
			}
		}

		if (flag == 0)
		{
			break;
		}
		lunshu = j + 1;

	}
	cout << "交换了" << lunshu << "轮" << endl;
	cout << "交换了" << cishu << "次" << endl;

	cout << "升序后：";				//冒泡排序
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");

	return 0;
}