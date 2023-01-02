#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//定义
struct Student
{
	string name;
	int age;
	int score;
};

int main2()
{


	//struct Student s2={...};
	//struct 结构体名 数组名[元素个数]={{},{},...{}}

	Student stuArr[3] =
	{
		{"三",15,99},
		{"四",16,88},
		{"五",18,100}
	};
	cout << "姓名：" << stuArr[0].name << "	年龄：" << stuArr[0].age << "	分数：" << stuArr[0].score << endl;	//vs2019不用引头文件？

	//遍历，指针
	Student* p= stuArr;
	for (int i = 0; i < 3; i++)
	{
		cout << "姓名：" << p->name << "	年龄：" << p->age << "	分数：" << p->score << endl;
		p++;
	}

	system("pause");
	return 0;
}