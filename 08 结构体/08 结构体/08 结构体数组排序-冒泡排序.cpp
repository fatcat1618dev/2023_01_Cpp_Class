#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

struct Hero
{
	string name;
	int age;
	string sex;
};

//bubblesort
void bubblesort_by_age(Hero h[], int len)
{
	for (int i = 0; i < len - 1; i++)		//外层，几轮，元素-1
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (h[j].age > h[j + 1].age)	//前大，则后移动
			{
				Hero tmp = h[j];			//个人信息整体移动
				h[j]= h[j + 1];
				h[j + 1] = tmp;
			}
		}
	}
}

void myprint(Hero h[], int len)
{
	for (int i = 0; i < len; i++,h++)
	{
		cout << "\t" << h->name << " " << h->age << " " << h->sex << endl;
	}
}
int main()
{
	Hero h[]=
	{
		{"刘备", 23, "男"},
		{"关羽", 22, "男"},
		{"张飞", 20, "男"},
		{"赵云", 21, "男"},
		{"貂蝉", 19, "女"}
	};

	int len = sizeof(h) / sizeof(h[0]);

	//排序前
	cout << "排序前：" << endl;
	myprint(h, len);

	//冒泡排序，按年龄升序排列
	bubblesort_by_age(h, len);

	//打印排序后结果
	cout << "排序前：" << endl;
	myprint(h, len);

	system("pause");

	return 0;
}