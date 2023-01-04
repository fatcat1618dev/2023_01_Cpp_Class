#include<iostream>
using namespace std;
#define MAX 1000
#include<string>
void menu()
{
	cout << "****************************" << endl;
	cout << "*****  1.���  2.ɾ��  *****" << endl;
	cout << "*****  3.����  4.�޸�  *****" << endl;
	cout << "*****  5.��ʾ  6.���  *****" << endl;
	cout << "*****  0.�˳�          *****" << endl;
	cout << "****************************" << endl;

}
enum select
{
	ADD=1,				//��ֵ����1��ʼ
	DELETE,
	SEARCH,
	MODIFY,
	SHOW,
	CLEAR,
	EXIT=0				//0
};
//��ϵ�˽ṹ��
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_PhoneNumber;
	string m_Addr;
};
//ͨѶ¼�ṹ��
struct ContactBooks
{
	struct Person personArray[MAX];	//ͨѶ¼���飬����
	int m_Size;						//������Ա����
};
//������ϵ��
void updatePerson(ContactBooks* p,int index)	//����Ŷ����� p->m_Size; �������� ret
{
	string name;
	cout << "���������֣�";
	cin >> name;
	p->personArray[index].m_Name = name;
	//�Ա�
	int sex;
	cout << "��ѡ���Ա�";
	cout << "\t1 ��    2 Ů" << endl;
	while (1)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)	//1 ��  2 Ů
		{
			p->personArray[index].m_Sex = sex;
			break;										//ѡ��ok�����˳�
		}
		cout << "������ѡ��" << endl;
	}
	//����
	int age;
	cout << "���������䣺";
	while (1)
	{
		cin >> age;
		if (age > 0 && age < 150)
		{
			p->personArray[index].m_Age = age;	//(0,150)֮ǰ��Ч
			break;
		}
		cout << "������Ч�����������룡" << endl;
	}
	//�ֻ�
	string phonenumber;										//�Ӹ��жϣ�11λ��ÿλ��Ϊ����0-9
	cout << "�������ֻ��ţ�";
	while (1)
	{
		cin >> phonenumber;
		int len = strlen(phonenumber.c_str());				//c++�е��ַ�������

		bool flag = 0;										//������
		for (int i = 0; i < len; i++)
		{
			if (phonenumber[i] < '0' && phonenumber[i] > '9')
			{
				flag = 1;
				break;
			}
		}
		if (len == 11 && flag == 0)
		{
			p->personArray[index].m_PhoneNumber = phonenumber;
			break;
		}
		cout << "������볤�ȼ���������..." << endl;
	}

	//��ַ
	string addr;
	cout << "�������ַ��";
	cin >> addr;
	p->personArray[index].m_Addr = addr;
}
//�����ϵ��
void addPerson(ContactBooks* p)
{
	//ͨѶ¼�Ƿ�����
	if (p->m_Size == MAX)
	{
		cout << "ͨѶ¼������" << endl;
	}
	else
	{
		//׼�����
		//����
		updatePerson(p,p->m_Size);			//ͨѶ����ϵ�˸���
		
		//���¸���
		p->m_Size++;
		cout << "��ӳɹ���" << endl;

		//����
		system("pause");//�����������
		system("cls");
	}
}

//��ʾ��ϵ��
void showPerson(ContactBooks*p)
{
	if (p->m_Size == 0)
	{
		cout << "û����ϵ�ˣ�����ӣ�" << endl;
	}
	else
	{
		cout << "����" << "\t" << "�Ա�" << "\t" << "����"
			<< "\t" << "�ֻ�" << "\t\t" << "��ַ" << endl;
		for (int i = 0; i < p->m_Size; i++)
		{
			cout << p->personArray[i].m_Name <<"\t" << (p->personArray[i].m_Sex==1?"��":"Ů") << "\t" << p->personArray[i].m_Age
				 << "\t" << p->personArray[i].m_PhoneNumber << "\t" << p->personArray[i].m_Addr << endl;

		}
	}
	//����
	system("pause");//�����������
	system("cls");
}
//�����ϵ���Ƿ���ڣ�������ʾ�ҵ��������ڷ���-1
int isExist(ContactBooks* p, string name)
{
	//����
	for (int i = 0; i < p->m_Size; i++)
	{
		if (p->personArray[i].m_Name == name)	//����
		{
			cout << "�ҵ��ˣ�" << endl;
			return i;
			break;
		}
	}
	//cout << "���޴��ˣ�" << endl;
	return -1;
}

//ɾ����ϵ��
void deletePerson(ContactBooks* p)
{
	string name;
	cout << "������Ҫɾ������ϵ�ˣ�";
	cin >> name;
	//�Ƿ����
	//ret -1,���޴���
	//����ret������λ��
	int ret = isExist(p, name);
	if (ret == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else
	{
		for (int i = ret; i < p->m_Size; i++)	//����Ǩ��
		{
			p->personArray[i] = p->personArray[i + 1];
		}
		//��������
		p->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	//���������
	system("pause");
	system("cls");
}

//������ϵ��
void searchPerson(ContactBooks* p)
{
	cout << "������������";
	string name;
	cin >> name;
	
	int ret = isExist(p, name);
	if(ret!=-1)
	{
		cout << "����" << "\t" << "�Ա�" << "\t" << "����"
			<< "\t" << "�ֻ�" << "\t\t" << "��ַ" << endl;
		cout << p->personArray[ret].m_Name << "\t" << (p->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t" << p->personArray[ret].m_Age
			<< "\t" << p->personArray[ret].m_PhoneNumber << "\t" << p->personArray[ret].m_Addr << endl;

	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	//�����������
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(ContactBooks* p)
{
	cout << "������Ҫ�޸ĵ���ϵ��������";
	string name;
	cin >> name;

	int ret = isExist(p, name);
	if (ret != -1)
	{
		updatePerson(p,ret);			//����retλ����ϵ��
		//��ʾ��Ϣ
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	//�����������
	system("pause");
	system("cls");
}

//�����ϵ��
//��ͨѶ¼��¼����ϵ��������0������
void clearContactBooks(ContactBooks* p)
{
	p->m_Size = 0;
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//ͨѶ¼����������ʼ��
	ContactBooks CBs;
	CBs.m_Size = 0;			//Ĭ��Ϊ�գ�û�����ش洢

	int select = 0;			//ѡ���������

	while (1)
	{
		menu();

		cout << "��ѡ��";
		cin >> select;		//����
		switch (select)
		{
		case ADD:
			addPerson(&CBs);
			break;
		case DELETE:
			deletePerson(&CBs);	//���޴��ˡ��鵽ɾ��������Ǩ��
			break;
		case SEARCH:
			searchPerson(&CBs);
			break;
		case MODIFY:
			modifyPerson(&CBs);
			break;
		case SHOW:
			showPerson(&CBs);
			break;
		case CLEAR:
			clearContactBooks(&CBs);
			break;
		case EXIT:
			cout << "��ӭ�´μ���ʹ�ã�" << endl;
			//system("pause");	//��ʽ1������������������˳�
			return 0;
			//exit(0);			//��ʽ2�������˳�
			break;
		default:
			cout << "�����������������룡" << endl;
			break;
		}
	}


	system("pause");
	return 0;
}