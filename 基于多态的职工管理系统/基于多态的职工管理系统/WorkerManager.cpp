#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		//��ʼ��
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2 �ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		//��ʼ������
		//cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3 �ļ������Ҽ�¼������
	int num = this->get_EmpNum();
	//cout << "Ա������Ϊ��" << num << endl;
	//����
	this->m_EmpNum = num;
	
	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ����ݴ���������
	this->int_Emp();

	////���Դ���
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "��ţ�" << this->m_EmpArray[i]->m_Id
	//		<< " ����" << this->m_EmpArray[i]->m_Name
	//		<< " ����" << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

void WorkerManager::Show_Menu()
{
	cout << "*************************************" << endl;
	cout << "******* ��ӭʹ��ְ������ϵͳ��*******" << endl;
	cout << "*** 0.�˳�����ϵͳ 1.����ְ����Ϣ ***" << endl;
	cout << "*** 2.��ʾְ����Ϣ 3.ɾ����ְְ�� ***" << endl;
	cout << "*** 4.�޸�ְ����Ϣ 5.����ְ����Ϣ ***" << endl;
	cout << "*** 6.���ձ������ 7.���������Ϣ ***" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");				//��������˳�
	exit(0);
}

//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������";
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//��=ԭ+����

		//�����¿ռ�
		Worker** newSpace= new Worker* [newSize];

		//ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		int id;//ְ�����
		string name;//����
		int dSelect;//����
		//���������
		for (int i = 0; i < addNum; i++)
		{
			cout << "�������" << i + 1 << "����ְ����ţ�";
			cin >> id;

			cout << "�������" << i + 1 << "����ְ��������";
			cin >> name;

			cout << "��ѡ���ְ����λ��\n";
			cout << "1 ��ְͨ��" << endl;
			cout << "2 ����" << endl;
			cout << "3 �ϰ�" << endl;
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
			//��ְ�����浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[]this->m_EmpArray;

		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		//����ְ������
		this->m_EmpNum = newSize;

		//���²�Ϊ�ձ�־
		this->m_FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		//�������ݵ��ļ���
/*		this->save()*/;
		save();
	}
	else
	{
		cout << "��������" << endl;
	}

	//������������������ϼ�
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//�����ʽ�򿪣���д�ļ�

	//������д���ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//�ر��ļ�
	ofs.close();
}

//ͳ���ļ�������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//�򿪣���

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//����
		num++;
	}
	return num;
}

//��ʼ��Ա��
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
		//���ݲ�ͬ����id������ͬ�Ķ���
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
		//�����������
		this->m_EmpArray[index] = worker;
		index++;
	}
}

//��ʾԱ��
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "���ļ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//cout << "��ţ�" << this->m_EmpArray[i]->m_Id
			//	<< " ����" << this->m_EmpArray[i]->m_Name
			//	<< " ����" << this->m_EmpArray[i]->m_DeptId << endl;

			//�ö�̬���ýӿ�
			this->m_EmpArray[i]->showInfo();
		}


	}

	//����������������ϼ�
	system("pause");
	system("cls");
}

//ɾ��Ա��
void WorkerManager::Del_Emp()
{
	//�ļ��Ƿ����
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڣ�" << endl;
	}
	else
	{
		//�ļ�����,������Ҫɾ����Ա��name
		string name = "";
		cout << "������Ҫɾ����Ա��������";
		cin >> name;
		//�ж�Ա���Ƿ����
		int index = this->IsExist(name);

		if (index!=-1)	//����
		{
			//����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//����num
			this->m_EmpNum--;
			//
			cout << "ɾ���ɹ���" << endl;
			//�����ļ�
			this->save();
		}
		else
		{
			//������
			cout << "Ա����Ϣ�����ڣ�" << endl;
		}
	}
	//����
	system("pause");
	system("cls");
}

//�ж�Ա���Ƿ����
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

//�޸�Ա����Ϣ
void WorkerManager::Mod_Emp()
{
	//�ļ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڣ�" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�Ա��������";
		string name;
		cin >> name;

		int ret = this->IsExist(name);

		if (ret!=-1)
		{
			//�ҵ�
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int newDId = 0;

			cout << "�鵽��" << name << ",�������¹��ţ�";
			cin >> newId;

			cout << "��������������";
			cin >> newName;

			cout << "�������¸�λ��" << endl;
			cout << "1 ְԱ" << endl;
			cout << "2 ����" << endl;
			cout << "3 �ϰ�" << endl;
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

			//�������飬���浽�ļ�
			this->m_EmpArray[ret] = worker;
			this->save();
		}
		else
		{
			cout << "���޴��ˣ�" << endl;
		}
	}

	//���������
	system("pause");
	system("cls");
}

//����������
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)//���ļ�
	{
		cout << "�ļ������ڣ�" << endl;
	}
	else
	{
		cout << "������Ҫ��ѯ��Ա��������";
		string name;
		cin >> name;

		int ret = this->IsExist(name);
		if (ret != -1)//����
		{
			this->m_EmpArray[ret]->showInfo();
		}
		else
		{
			cout << "���޴��ˣ�" << endl;
		}
	}
	
	//���������
	system("pause");
	system("cls");
}


//����������
void WorkerManager::Sort_Emp_byName()
{
	if (this->m_FileIsEmpty)//��
	{
		cout << "�ļ�Ϊ�գ�" << endl;
	}
	else
	{
		if (this->m_EmpNum >= 2)
		{
			//����1������2
			cout << "��ѡ������or����" << endl;
			cout << "1 ����" << endl;
			cout << "2 ����" << endl;
			
			int select=0;
			cin >> select;

			if (select == 1)
			{
				for (int i = 0; i < this->m_EmpNum - 1; i++)	//ð��
				//1 9 2 3 4 5��1��5�κ�
				//1 2 3 4 5 9, 2��4�Σ�3��3�Σ�4��2�Σ�5��1��
				{
					for (int j = 0; j < this->m_EmpNum - 1 - i; j++)
					{
						int ret = this->flag_cmp_byname(this->m_EmpArray[j]->m_Name, this->m_EmpArray[j + 1]->m_Name);
						// -1 0 1��Ҫ��
						if (ret >= 0)
						{
							//����
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
				for (int i = 0; i < this->m_EmpNum - 1; i++)	//ð��
				//1 9 2 3 4 5��1��5�κ�
				//1 2 3 4 5 9, 2��4�Σ�3��3�Σ�4��2�Σ�5��1��
				{
					for (int j = 0; j < this->m_EmpNum - 1 - i; j++)
					{
						int ret = this->flag_cmp_byname(this->m_EmpArray[j]->m_Name, this->m_EmpArray[j + 1]->m_Name);
						// -1 0 1��Ҫ��
						if (ret < 0)
						{
							//��
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
				cout << "ѡ�����" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
		}
	}
}

//���ƱȽϣ�����flag
int WorkerManager::flag_cmp_byname(string name1,string name2)
{
		return name1.compare(name2);	//-1 0 1	//�������У������
}

//����ļ�
void WorkerManager::Clean_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�գ�" << endl;
	}
	else
	{	//����ȷ��
		cout << "ȷ����գ�" << endl;
		cout << "1 ȷ��" << endl;
		cout << "2 ����" << endl;
		
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//��ģʽ������ڣ�ɾ���ļ����´��� ios::trunc
			ifstream ofs(FILENAME, ios::trunc);
			ofs.close();

			//
			if (this->m_EmpArray != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)//ȫ���ͷ�
				{
					if (this->m_EmpArray[i] != NULL)//�ͷ�
					{
						delete this->m_EmpArray[i];
					}
				}
			}

			//������0��ָ������ɾ���ÿա���־λtrue
			this->m_EmpNum = 0;
			delete[]this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;//�ļ�Ϊ�ձ�־λ
			cout << "��ճɹ���" << endl;
		}
		else
		{
			cout << "���سɹ���" << endl;
		}
	}
	//���������
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
		for (int i = 0; i < this->m_EmpNum; i++)//ȫ���ͷ�
		{
			if (this->m_EmpArray[i] != NULL)//�ͷ�
			{
				delete this->m_EmpArray[i];
			}
		}
	}
	delete[]this->m_EmpArray;
	this->m_EmpArray = NULL;
}