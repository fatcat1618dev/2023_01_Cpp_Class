//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////ȫ�ֺ�������Ԫ
//class House
//{
//	//goodguy��house�����ѣ�Ȩ�޷ſ�
//	friend void goodguy(House* house);	//������
//public:
//	House():m_LivingRoom("����"),m_BedRoom("����") {}		//�б��ʼ��
//	//House()
//	//{
//	//	m_LivingRoom = "����";
//	//	m_BedRoom = "����";
//	//}
//public:
//	string m_LivingRoom;
//private:
//	string m_BedRoom;
//};
//
////ȫ�ֺ���
//void goodguy(House* house)			//ָ������ö���
//{
//	cout << "�û���	ȫ�ֺ���	���ڷ��ʣ�" << house->m_LivingRoom << endl;
//	cout << "�û���	ȫ�ֺ���	���ڷ��ʣ�" << house->m_BedRoom << endl;
//
//} 
//void test01()
//{
//	House h;
//	goodguy(&h);
//
//}
//int main()
//{
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}