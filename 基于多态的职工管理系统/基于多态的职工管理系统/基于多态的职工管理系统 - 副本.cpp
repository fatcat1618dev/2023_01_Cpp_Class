#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void show()
{
	cout << "*************************************" << endl;
	cout << "******* ��ӭʹ��ְ������ϵͳ��*******" << endl;
	cout << "*** 0.�˳�����ϵͳ 1.����ְ����Ϣ ***" << endl;
	cout << "*** 2.��ʾְ����Ϣ 3.ɾ����ְְ�� ***" << endl;
	cout << "*** 4.�޸�ְ����Ϣ 5.����ְ����Ϣ ***" << endl;
	cout << "*** 6.���ձ������ 7.���������Ϣ ***" << endl;
	cout << "*************************************" << endl;

}

int main()
{
	int a=1;

	while (a)
	{
		show();
		cout << "ѡ��" << endl;
		cin >> a;

		switch (a)
		{
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			break;
		case 1:
			cout << "����ְ����Ϣ" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "��ʾְ����Ϣ" << endl;
			system("pause");
			system("cls");
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}