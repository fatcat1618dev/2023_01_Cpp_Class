#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/*
	案例：封装一个函数，利用冒泡排序，实现对整形数组的升序排列，如int arr[]={4,3,6,9,1,2,10,8,7,5}

	* 函数、数组、指针
	* 冒泡排序、flag
*/
void bubblesort(int*p,int len)
{
	//轮数、次数
	int lunshu = 0;
	int cishu = 0;

	for (int i = 0; i < len-1; i++)					//外层，第几轮，元素个数-1
	{
		//flag，一轮中已经不再升序，则考虑跳出循环
		bool flag = 0;

		for (int j = 0; j < len -1- i; j++)			//内层，第几次
		{
			if (p[j]>p[j+1])
			{
				//int tmp = p[j];
				//p[j] = p[j + 1];
				//p[j + 1] = tmp;
				int tmp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = tmp;

				flag = 1;				//有继续排序
				cishu++;				//排序1次，自+
			}
		}
		if (flag == 0)
		{
			break;						//1轮中顺序已ok，跳出循环，结束
		}
		lunshu = i + 1;
	}
	cout << "合计排序" << lunshu << "轮，" << cishu << "次" << endl;
}
void myprint(int*p,int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << *p << " ";
		p++;
	}
	cout << endl;
}
int main()
{
	//int arr[] = { 4,3,6,9,1,2,10,8,7,5 };
	int arr[] = { 1,2,3,4,5,6,7,8,10,9 };

	//指针遍历，打印
	cout << "排序前：";
	int len = sizeof(arr) / sizeof(arr[0]);//元素个数
	myprint(arr, len);

	//冒泡排序
	bubblesort(arr,len);

	//指针遍历，打印
	cout << "排序后：";
	myprint(arr, len);
	system("pause");

	return 0;
}