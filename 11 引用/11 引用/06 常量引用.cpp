#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//���á�const
void showvalue(const int& a)
{
	//a=10;				//���ɸ�
	cout << a << endl;
}
int main()
{

	//������ʹ�ó������ã���ֹ������޸�ʵ��
	//�����ӡ����
	int a = 10;
	showvalue(a);

	system("pause");
	return 0;
}