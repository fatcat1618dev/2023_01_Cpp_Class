#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		//初始化
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2 文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		//初始化属性
		//cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3 文件存在且记录有数据
	int num = this->get_EmpNum();
	//cout << "员工人数为：" << num << endl;
	//更新
	this->m_EmpNum = num;
	
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件数据存入数组中
	this->int_Emp();

	////测试代码
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "编号：" << this->m_EmpArray[i]->m_Id
	//		<< " 姓名" << this->m_EmpArray[i]->m_Name
	//		<< " 部门" << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

void WorkerManager::Show_Menu()
{
	cout << "*************************************" << endl;
	cout << "******* 欢迎使用职工管理系统！*******" << endl;
	cout << "*** 0.退出管理系统 1.增加职工信息 ***" << endl;
	cout << "*** 2.显示职工信息 3.删除离职职工 ***" << endl;
	cout << "*** 4.修改职工信息 5.查找职工信息 ***" << endl;
	cout << "*** 6.按照编号排序 7.清空所有信息 ***" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");				//按任意键退出
	exit(0);
}

//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量：";
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;//新=原+新增

		//开辟新空间
		Worker** newSpace= new Worker* [newSize];

		//原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		int id;//职工编号
		string name;//姓名
		int dSelect;//部门
		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			cout << "请输入第" << i + 1 << "个新职工编号：";
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名：";
			cin >> name;

			cout << "请选择该职工岗位：\n";
			cout << "1 普通职工" << endl;
			cout << "2 经理" << endl;
			cout << "3 老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			//将职工保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[]this->m_EmpArray;

		//更改新空间指向
		this->m_EmpArray = newSpace;

		//更新职工人数
		this->m_EmpNum = newSize;

		//更新不为空标志
		this->m_FileIsEmpty = false;

		//提示添加成功
		cout << "成功添加" << addNum << "名新职工" << endl;

		//保存数据到文件中
/*		this->save()*/;
		save();
	}
	else
	{
		cout << "数据有误！" << endl;
	}

	//按任意键，清屏返回上级
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//输出方式打开，即写文件

	//将数据写入文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//关闭文件
	ofs.close();
}

//统计文件中人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开，读

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//人数
		num++;
	}
	return num;
}

//初始化员工
void WorkerManager::int_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index=0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		//根据不同部门id创建不同的对象
		switch (dId)
		{
		case 1:
			worker = new Employee(id, name, dId);
			break;
		case 2:
			worker = new Manager(id, name, dId);
			break;
		case 3:
			worker = new Boss(id, name, dId);
			break;
		default:
			break;
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
}

//显示员工
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "空文件" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//cout << "编号：" << this->m_EmpArray[i]->m_Id
			//	<< " 姓名" << this->m_EmpArray[i]->m_Name
			//	<< " 部门" << this->m_EmpArray[i]->m_DeptId << endl;

			//用多态调用接口
			this->m_EmpArray[i]->showInfo();
		}


	}

	//按任意键，清屏回上级
	system("pause");
	system("cls");
}

//删除员工
void WorkerManager::Del_Emp()
{
	//文件是否存在
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在！" << endl;
	}
	else
	{
		//文件存在,请输入要删除的员工name
		string name = "";
		cout << "请输入要删除的员工姓名：";
		cin >> name;
		//判断员工是否存在
		int index = this->IsExist(name);

		if (index!=-1)	//存在
		{
			//遍历前移
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新num
			this->m_EmpNum--;
			//
			cout << "删除成功！" << endl;
			//保存文件
			this->save();
		}
		else
		{
			//不存在
			cout << "员工信息不存在！" << endl;
		}
	}
	//清屏
	system("pause");
	system("cls");
}

//判断员工是否存在
int WorkerManager::IsExist(string name)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Name == name)
		{
			index = i;
			break;
		}
	}
	return index;
}

//修改员工信息
void WorkerManager::Mod_Emp()
{
	//文件为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在！" << endl;
	}
	else
	{
		cout << "请输入要修改的员工姓名：";
		string name;
		cin >> name;

		int ret = this->IsExist(name);

		if (ret!=-1)
		{
			//找到
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int newDId = 0;

			cout << "查到：" << name << ",请输入新工号：";
			cin >> newId;

			cout << "请输入新姓名：";
			cin >> newName;

			cout << "请输入新岗位：" << endl;
			cout << "1 职员" << endl;
			cout << "2 经理" << endl;
			cout << "3 老板" << endl;
			cin >> newDId;

			Worker* worker = NULL;
			switch (newDId)
			{
			case 1:
				worker = new Employee(newId, newName, newDId);
				break;
			case 2:
				worker = new Manager(newId, newName, newDId);
				break;
			case 3:
				worker = new Boss(newId, newName, newDId);
				break;
			default:
				break;
			}

			//放入数组，保存到文件
			this->m_EmpArray[ret] = worker;
			this->save();
		}
		else
		{
			cout << "查无此人！" << endl;
		}
	}

	//任意键清屏
	system("pause");
	system("cls");
}

//按姓名查找
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)//空文件
	{
		cout << "文件不存在！" << endl;
	}
	else
	{
		cout << "请输入要查询的员工姓名：";
		string name;
		cin >> name;

		int ret = this->IsExist(name);
		if (ret != -1)//存在
		{
			this->m_EmpArray[ret]->showInfo();
		}
		else
		{
			cout << "查无此人！" << endl;
		}
	}
	
	//任意键清屏
	system("pause");
	system("cls");
}


//按姓名排序
void WorkerManager::Sort_Emp_byName()
{
	if (this->m_FileIsEmpty)//空
	{
		cout << "文件为空！" << endl;
	}
	else
	{
		if (this->m_EmpNum >= 2)
		{
			//升序1、降序2
			cout << "请选择升序or降序：" << endl;
			cout << "1 升序" << endl;
			cout << "2 降序" << endl;
			
			int select=0;
			cin >> select;

			if (select == 1)
			{
				for (int i = 0; i < this->m_EmpNum - 1; i++)	//冒泡
				//1 9 2 3 4 5，1轮5次后
				//1 2 3 4 5 9, 2轮4次，3轮3次，4轮2次，5轮1次
				{
					for (int j = 0; j < this->m_EmpNum - 1 - i; j++)
					{
						int ret = this->flag_cmp_byname(this->m_EmpArray[j]->m_Name, this->m_EmpArray[j + 1]->m_Name);
						// -1 0 1需要排
						if (ret >= 0)
						{
							//升序
							Worker* worker = NULL;
							worker = this->m_EmpArray[j + 1];
							this->m_EmpArray[j + 1] = this->m_EmpArray[j];
							this->m_EmpArray[j] = worker;
						}
					}
				}
				this->Show_Emp();
				this->save();
			}
			else if(select==2)
			{
				for (int i = 0; i < this->m_EmpNum - 1; i++)	//冒泡
				//1 9 2 3 4 5，1轮5次后
				//1 2 3 4 5 9, 2轮4次，3轮3次，4轮2次，5轮1次
				{
					for (int j = 0; j < this->m_EmpNum - 1 - i; j++)
					{
						int ret = this->flag_cmp_byname(this->m_EmpArray[j]->m_Name, this->m_EmpArray[j + 1]->m_Name);
						// -1 0 1需要排
						if (ret < 0)
						{
							//降
							Worker* worker = NULL;
							worker = this->m_EmpArray[j + 1];
							this->m_EmpArray[j + 1] = this->m_EmpArray[j];
							this->m_EmpArray[j] = worker;
						}
					}
				}
				this->Show_Emp();
				this->save();
			}
			else
			{
				cout << "选择错误！" << endl;
			}
		}
		else
		{
			cout << "无需排序" << endl;
		}
	}
}

//名称比较，返回flag
int WorkerManager::flag_cmp_byname(string name1,string name2)
{
		return name1.compare(name2);	//-1 0 1	//≥升序列，往后调
}

//清空文件
void WorkerManager::Clean_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空！" << endl;
	}
	else
	{	//二次确认
		cout << "确认清空：" << endl;
		cout << "1 确认" << endl;
		cout << "2 返回" << endl;
		
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//打开模式，如存在，删除文件重新创建 ios::trunc
			ifstream ofs(FILENAME, ios::trunc);
			ofs.close();

			//
			if (this->m_EmpArray != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)//全部释放
				{
					if (this->m_EmpArray[i] != NULL)//释放
					{
						delete this->m_EmpArray[i];
					}
				}
			}

			//数量置0、指针数组删除置空、标志位true
			this->m_EmpNum = 0;
			delete[]this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;//文件为空标志位
			cout << "清空成功！" << endl;
		}
		else
		{
			cout << "返回成功！" << endl;
		}
	}
	//任意键清屏
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	//if (this->m_EmpArray != NULL)
	//{
	//	delete[]this->m_EmpArray;
	//	this->m_EmpArray = NULL;
	//}
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)//全部释放
		{
			if (this->m_EmpArray[i] != NULL)//释放
			{
				delete this->m_EmpArray[i];
			}
		}
	}
	delete[]this->m_EmpArray;
	this->m_EmpArray = NULL;
}