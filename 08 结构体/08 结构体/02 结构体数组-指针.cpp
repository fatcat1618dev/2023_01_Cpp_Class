#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//����
struct Student
{
	string name;
	int age;
	int score;
};

int main2()
{


	//struct Student s2={...};
	//struct �ṹ���� ������[Ԫ�ظ���]={{},{},...{}}

	Student stuArr[3] =
	{
		{"��",15,99},
		{"��",16,88},
		{"��",18,100}
	};
	cout << "������" << stuArr[0].name << "	���䣺" << stuArr[0].age << "	������" << stuArr[0].score << endl;	//vs2019������ͷ�ļ���

	//������ָ��
	Student* p= stuArr;
	for (int i = 0; i < 3; i++)
	{
		cout << "������" << p->name << "	���䣺" << p->age << "	������" << p->score << endl;
		p++;
	}

	system("pause");
	return 0;
}