#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<ctime>

int main9() {

	//�������
	srand((unsigned int)time(NULL));
	//α�����
	int num = rand() % 100 + 1;//0-99	+1,�����
	cout << num << endl;

	int guess = 0;

	while (1)
	{
		cout << "�������";
		cin >> guess;

		if (guess < num)
		{
			cout << "С��" << endl;
		}
		else if(guess > num)
		{
			cout << "����" << endl;
		}
		else
		{
			cout << "����" << endl;
			break;
		}
	}

	system("pause");

	return 0;
}