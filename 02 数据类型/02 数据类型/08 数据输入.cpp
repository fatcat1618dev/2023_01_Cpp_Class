#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main() {

	//1.����
	int a = 0;
	cout << "����������ֵ��";
	cin >> a;
	cout << "����ֵΪ��" << a << endl;

	//2.������
	float f1 = 3.14f;
	cout << "������С����";
	cin >> f1;
	cout << "С��Ϊ��" << f1 << endl;

	//3.�ַ�
	char ch = 'b';
	cout << "�������ַ���";
	cin >> ch;
	cout << "�ַ�Ϊ��" << ch << endl;

	//4.�ַ���
	string str = "HAOMO.AI";
	cout << "�������ַ�����";
	cin >> str;
	cout << "�ַ���Ϊ��" << str << endl;

	//5.��������
	bool flag = true;
	cout << "�븳ֵflag��";
	cin >> flag;		//���㶼������
	cout << "flagΪ��" << flag << endl;

	system("pause");

	return 0;
}