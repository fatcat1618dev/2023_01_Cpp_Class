#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>
#define FILENAME "empFile.txt"

typedef enum
{
	Exit,
	Add,
	Show,
	Delete,
	Modify,
	Find,
	Sort,
	Empty
};

class WorkerManager
{
public:
	WorkerManager();

	void Show_Menu();
	void ExitSystem();

	//ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void int_Emp();

	//��ʾԱ��
	void Show_Emp();

	//ɾ��Ա��
	void Del_Emp();

	//�ж�Ա���Ƿ����
	int IsExist(string name);

	//�޸�Ա����Ϣ
	void Mod_Emp();

	//����������
	void Find_Emp();

	//���򣬰�����
	void Sort_Emp_byName();

	//���ƱȽϣ�����flag
	int flag_cmp_byname(string,string);

	//����ļ�
	void Clean_Emp();

	~WorkerManager();
};