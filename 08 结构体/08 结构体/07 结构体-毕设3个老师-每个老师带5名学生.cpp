#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//ѧ������
struct Student
{
	string sName;
	int score;
};

//��ʦ����
struct Teacher
{
	string tName;
	Student sArray[5];
};


//��ֵ����ַ
void SetInfo(Teacher tArray[], int len)
{
	string nameseed = "ABCDEFG";	//����
	for (int i = 0; i < len; i++)
	{
		tArray[i].tName = "Teacher_";
		tArray[i].tName += nameseed[i];
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].sName = "Student_";
			tArray[i].sArray[j].sName += nameseed[j];

			int rand_score = rand() % 41 + 60;//0-40 60-100
			tArray[i].sArray[j].score = rand_score;
		}
	}
}

//��ӡ
void MyPrint(Teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << tArray[i].tName << endl;
		for (int j = 0; j < 5; j++)
		{
			cout <<"\t" << tArray[i].sArray[j].sName << "\t" <<tArray[i].sArray[j].score << endl;
		}
	}
}
int main7()
{
	srand((unsigned int)time(NULL));	//����ʱ�������
	//��ʦ�ṹ������
	Teacher tArray[3];

	//��ֵ
	int len = sizeof(tArray) / sizeof(tArray[0]);//Ԫ�ظ���	3����ʦ����
	SetInfo(tArray, len);		//

	//��ӡ
	MyPrint(tArray, len);

	system("pause");
	return 0;
}