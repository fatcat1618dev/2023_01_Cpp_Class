#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

struct Student
{
	string name;
	int age;
	int score;
};

//��ֵ
void my_print1(Student s)
{
	cout << "������" << s.name << "	���䣺" << s.age << "	������" << s.score << endl;
}

//��ַ
void my_print2(Student* p)
{
	cout << "������" << p->name<< "	���䣺" << p->age << "	������" << p->score << endl;

}

int main5()
{
	Student s1 = { "��",18,99 };

	//��ֵ
	my_print1(s1);

	//��ַ
	my_print2(&s1);

	system("pause");
	return 0;
}