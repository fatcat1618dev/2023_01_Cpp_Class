//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////���ࡢ���麯��
//class MakeDrink
//{
//public:
//	//��ˮ
//	virtual void Boil() = 0;
//	//����
//	virtual void Brew() = 0;
//	//���뱭��
//	virtual void Pour() = 0;
//	//���븨��
//	virtual void AddSometing() = 0;
//	void makeDrink()
//	{
//		Boil();
//		Brew();
//		Pour();
//		AddSometing();
//	}
//};
//
////����
//class makeCoffee :public MakeDrink
//{
//	//��ˮ
//	virtual void Boil()
//	{
//		cout << "�󴿾�ˮ..." << endl;
//	}
//	//����
//	virtual void Brew()
//	{
//		cout << "���ݿ���..." << endl;
//	}
//	//���뱭��
//	virtual void Pour()
//	{
//		cout << "����ɱ�..." << endl;
//	}
//	//���븨��
//	virtual void AddSometing()
//	{
//		cout << "���ǡ�ţ��..." << endl;
//	}
//};
//
////���
//class makeBlackTea :public MakeDrink
//{
//	//��ˮ
//	virtual void Boil()
//	{
//		cout << "���Ȫˮ..." << endl;
//	}
//	//����
//	virtual void Brew()
//	{
//		cout << "���ݺ��..." << endl;
//	}
//	//���뱭��
//	virtual void Pour()
//	{
//		cout << "��������..." << endl;
//	}
//	//���븨��
//	virtual void AddSometing()
//	{
//		cout << "��������..." << endl;
//	}
//};
//
//void doWork(MakeDrink* p)
//{
//	p->makeDrink();
//}
//
//
//void test01()
//{
//	cout << "..........��������.........." << endl;
//	doWork(new makeCoffee);
//	cout << "..........�������.........." << endl;
//	doWork(new makeBlackTea);
//
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}