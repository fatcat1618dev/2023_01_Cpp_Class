#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

struct Student
{
	string name;
	int age;
	int score;
};

//��ַ
void my_print2(const Student* p)
{
	//p->age = 150;				//const���Σ����ɸ�ֵ����ֹ�����
	cout << "������" << p->name << "	���䣺" << p->age << "	������" << p->score << endl;

}

int main6()
{
	Student s1 = { "��",18,99 };

	//��ַ
	my_print2(&s1);

	system("pause");
	return 0;
}