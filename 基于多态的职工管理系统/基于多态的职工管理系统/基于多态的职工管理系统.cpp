#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include "WorkerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

int main()
{
	/*Worker* worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "�", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "��ϲ", 3);
	worker->showInfo();
	delete worker;*/

	WorkerManager wm;

	int choice = 0;//ѡ��

	while (1)
	{
		wm.Show_Menu();

		cout << "��ѡ��";
		cin >> choice;

		switch (choice)
		{
		case Exit:
			wm.ExitSystem();
			break;
		case Add:
			wm.Add_Emp();
			break;
		case Show:
			wm.Show_Emp();
			break;
		case Delete:
			wm.Del_Emp();
			break;
		case Modify:
			wm.Mod_Emp();
			break;
		case Find:
			wm.Find_Emp();
			break;
		case Sort:
			//cout << wm.flag_cmp_byname("��", "��") << endl;
			wm.Sort_Emp_byName();
			break;
		case Empty:
			wm.Clean_Emp();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}