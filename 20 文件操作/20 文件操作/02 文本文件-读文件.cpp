//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//#include<fstream>
//#include<string>
//
//void test01()
//{
//	//1.ͷ�ļ�
//	//2.������
//	ifstream ifs;
//
//	//3.�򿪷�ʽ�����ж��Ƿ�򿪳ɹ�
//	ifs.open("test01.txt", ios::in);
//
//	if (!ifs.is_open())
//	{
//		cout << "�ļ���ʧ�ܣ�" << endl;
//		return;
//	}
//	//4.������
//	//4��
//	////��һ��
//	//char buf[1024] = { 0 };
//	//while (ifs>>buf)
//	//{
//	//	cout << buf << endl;
//	//}
//
//	////�ڶ���
//	//char buf[1024] = { 0 };
//	//while (ifs.getline(buf,sizeof(buf)))
//	//{
//	//	cout << buf << endl;
//	//}
//
//	////��3��
//	//string buf;
//	//while (getline(ifs, buf))
//	//{
//	//	cout << buf << endl;
//	//}
//
//	//��4��
//	char c;
//	while ((c = ifs.get()) != EOF)		//endof file
//
//	{
//		cout << c;
//	}
//	
//	//5.�ر��ļ�
//	ifs.close();
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}