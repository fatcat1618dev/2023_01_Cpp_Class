#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//�����﷨
int* func3()
{
	return new int(10);	//new�ؼ��֣�ָ��
}
void test03()
{
	cout << *func3() << endl;	//��ַ������
	delete func3();
}

//��������
void test04()
{
	int* arr=new int[10];	//����������

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i * i;
		cout << arr[i]<<" ";
	}
	cout << endl;
	
	//�ͷŶ�����
	delete[] arr;
}

int main()
{
	test03();	//�����﷨
	//test04();	//��������

	system("pause");
	return 0;
}