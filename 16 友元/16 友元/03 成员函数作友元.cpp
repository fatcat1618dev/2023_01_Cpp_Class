#define _crt_secure_no_warnings 1
#include<iostream>
using namespace std;

//������Ԫ���û��ѷ��ʿ���������
class house;
class goodguy
{
public:
	goodguy();
	~goodguy();
	//������Ϊ
	void visit1();
	void visit2();
	//����ָ��
	house* h;
};

class house
{
	//friend class goodguy;	//������
	friend void goodguy::visit1();
public:
	house();
	~house();
public:
	string m_livingroom;
private:
	string m_bedroom;
};

//�����Ա����
//�б��ʼ�����캯��
house::house() :m_livingroom("����"), m_bedroom("����") { cout << "house ����" << endl; };
house::~house()
{
	cout << "house ���� " << endl;
}
goodguy::goodguy()
{
	h = new house();			//�޲ι���
	cout << "goodguy ���죡" << endl;
}
goodguy::~goodguy()
{
	cout << "goodguy	����	������house����" << endl;
	if (h != NULL )
	{
		delete h;
		h = NULL;
	}
}
void goodguy::visit1()
{
	cout << "�û����� ���ڷ��� " << h->m_livingroom << endl;
	cout << "�û����� ���ڷ��� " << h->m_bedroom << endl;			//�ɷ���������

}

void goodguy::visit2()
{
	cout << "�û����� ���ڷ��� " << h->m_livingroom << endl;
	//cout << "�û����� ���ڷ��� " << h->m_bedroom << endl;			//�ɷ���������

}
//���԰���
void test01()
{
	goodguy gg;
	gg.visit1();
	gg.visit2();
}
int main()
{
	test01();

	system("pause");
	return 0;
}