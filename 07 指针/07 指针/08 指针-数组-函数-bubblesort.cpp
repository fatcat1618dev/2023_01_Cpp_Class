#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/*
	��������װһ������������ð������ʵ�ֶ�����������������У���int arr[]={4,3,6,9,1,2,10,8,7,5}

	* ���������顢ָ��
	* ð������flag
*/
void bubblesort(int*p,int len)
{
	//����������
	int lunshu = 0;
	int cishu = 0;

	for (int i = 0; i < len-1; i++)					//��㣬�ڼ��֣�Ԫ�ظ���-1
	{
		//flag��һ�����Ѿ�����������������ѭ��
		bool flag = 0;

		for (int j = 0; j < len -1- i; j++)			//�ڲ㣬�ڼ���
		{
			if (p[j]>p[j+1])
			{
				//int tmp = p[j];
				//p[j] = p[j + 1];
				//p[j + 1] = tmp;
				int tmp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = tmp;

				flag = 1;				//�м�������
				cishu++;				//����1�Σ���+
			}
		}
		if (flag == 0)
		{
			break;						//1����˳����ok������ѭ��������
		}
		lunshu = i + 1;
	}
	cout << "�ϼ�����" << lunshu << "�֣�" << cishu << "��" << endl;
}
void myprint(int*p,int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << *p << " ";
		p++;
	}
	cout << endl;
}
int main()
{
	//int arr[] = { 4,3,6,9,1,2,10,8,7,5 };
	int arr[] = { 1,2,3,4,5,6,7,8,10,9 };

	//ָ���������ӡ
	cout << "����ǰ��";
	int len = sizeof(arr) / sizeof(arr[0]);//Ԫ�ظ���
	myprint(arr, len);

	//ð������
	bubblesort(arr,len);

	//ָ���������ӡ
	cout << "�����";
	myprint(arr, len);
	system("pause");

	return 0;
}