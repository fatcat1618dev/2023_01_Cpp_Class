#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

struct Student
{
	string name;
	int age;
	int score;
};

//传值
void my_print1(Student s)
{
	cout << "姓名：" << s.name << "	年龄：" << s.age << "	分数：" << s.score << endl;
}

//传址
void my_print2(Student* p)
{
	cout << "姓名：" << p->name<< "	年龄：" << p->age << "	分数：" << p->score << endl;

}

int main5()
{
	Student s1 = { "涛",18,99 };

	//传值
	my_print1(s1);

	//传址
	my_print2(&s1);

	system("pause");
	return 0;
}