//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////������Ԫ���û��ѷ��ʿ���������
//class House;
//class Goodguy
//{
//public:
//	Goodguy();
//	~Goodguy();
//	//������Ϊ
//	void visit();
//	//����ָ��
//	House* h;
//};
//
//class House
//{
//	friend class Goodguy;	//������
//public:
//	House();
//	~House();
//public:
//	string m_Livingroom;
//private:
//	string m_Bedroom;
//};
//
////�����Ա����
////�б��ʼ�����캯��
//House::House() :m_Livingroom("����"), m_Bedroom("����") { cout << "House ����" << endl; };
//House::~House()
//{
//	cout << "House ���� " << endl;
//}
//Goodguy::Goodguy()
//{
//	h = new House();			//�޲ι���
//	cout << "Goodguy ���죡" << endl;
//}
//Goodguy::~Goodguy()
//{
//	cout << "Goodguy	����	������house����" << endl;
//	if (h != NULL)
//	{
//		delete h;
//		h = NULL;
//	}
//}
//void Goodguy::visit()
//{
//	cout << "�û����� ���ڷ��� " << h->m_Livingroom << endl;
//	cout << "�û����� ���ڷ��� " << h->m_Bedroom << endl;			//�ɷ���������
//
//}
//
////���԰���
//void test01()
//{
//	Goodguy gg;
//	gg.visit();
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}