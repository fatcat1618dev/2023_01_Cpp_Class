#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main7() {

	//����Ӱ���
	//9-10	����
	//8		����
	//6-7	һ��
	//����	��Ƭ
	cout << "���֣�";
	int score = 0;
	cin >> score;

	if (score <= 10 && score >= 1)
	{
		switch (score)
		{
		case 10:
		case 9:
			cout << "����" << endl;
			break;
		case 8:
			cout << "����" << endl;
			break;
		case 7:
		case 6:
			cout << "һ��" << endl;
			break;
		default:
			cout << "��Ƭ" << endl;
			break;
		}
	}
	else
	{
		cout << "�����Ч��" << endl;
	}

	system("pause");

	return 0;
}