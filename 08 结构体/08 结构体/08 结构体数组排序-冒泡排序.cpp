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
	for (int i = 0; i < len - 1; i++)		//��㣬���֣�Ԫ��-1
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (h[j].age > h[j + 1].age)	//ǰ������ƶ�
			{
				Hero tmp = h[j];			//������Ϣ�����ƶ�
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
		{"����", 23, "��"},
		{"����", 22, "��"},
		{"�ŷ�", 20, "��"},
		{"����", 21, "��"},
		{"����", 19, "Ů"}
	};

	int len = sizeof(h) / sizeof(h[0]);

	//����ǰ
	cout << "����ǰ��" << endl;
	myprint(h, len);

	//ð�����򣬰�������������
	bubblesort_by_age(h, len);

	//��ӡ�������
	cout << "����ǰ��" << endl;
	myprint(h, len);

	system("pause");

	return 0;
}