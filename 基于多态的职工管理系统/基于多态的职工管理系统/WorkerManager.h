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

	//职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	//标志文件是否为空
	bool m_FileIsEmpty;

	//统计文件中人数
	int get_EmpNum();

	//初始化员工
	void int_Emp();

	//显示员工
	void Show_Emp();

	//删除员工
	void Del_Emp();

	//判断员工是否存在
	int IsExist(string name);

	//修改员工信息
	void Mod_Emp();

	//按姓名查找
	void Find_Emp();

	//排序，按姓名
	void Sort_Emp_byName();

	//名称比较，返回flag
	int flag_cmp_byname(string,string);

	//清空文件
	void Clean_Emp();

	~WorkerManager();
};