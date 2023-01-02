#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

struct Student
{
	string name;
	int age;
	int score;
};

//传址
void my_print2(const Student* p)
{
	//p->age = 150;				//const修饰，不可赋值，防止误操作
	cout << "姓名：" << p->name << "	年龄：" << p->age << "	分数：" << p->score << endl;

}

int main6()
{
	Student s1 = { "涛",18,99 };

	//传址
	my_print2(&s1);

	system("pause");
	return 0;
}