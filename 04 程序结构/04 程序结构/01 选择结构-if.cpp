#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main1() {

	//if
	//���������600������985������ؼ������

	float score = 600.5f;
	cout << "�����������";
	cin >> score;

	if (score >= 600)
	{
		cout << "��ϲ����985��" << endl;
	}
	else
	{
		cout << "�ؼ�����ɣ�" << endl;
	}

	system("pause");

	return 0;
}