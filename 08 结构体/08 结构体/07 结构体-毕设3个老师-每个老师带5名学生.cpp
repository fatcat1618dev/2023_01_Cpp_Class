#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//学生定义
struct Student
{
	string sName;
	int score;
};

//老师定义
struct Teacher
{
	string tName;
	Student sArray[5];
};


//赋值，传址
void SetInfo(Teacher tArray[], int len)
{
	string nameseed = "ABCDEFG";	//种子
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

//打印
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
	srand((unsigned int)time(NULL));	//基于时间的种子
	//老师结构体数组
	Teacher tArray[3];

	//赋值
	int len = sizeof(tArray) / sizeof(tArray[0]);//元素个数	3个老师打团
	SetInfo(tArray, len);		//

	//打印
	MyPrint(tArray, len);

	system("pause");
	return 0;
}