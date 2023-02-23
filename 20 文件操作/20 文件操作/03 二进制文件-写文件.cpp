//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//#include<fstream>
//
//class Person
//{
//public:
//	char m_Name[64];
//	int m_Age;
//
//};
//
//void test01()
//{
//	//2.创建流对象
//	ofstream ofs("Person.txt", ios::out | ios::binary);
//
//	//3.打开文件
//	/*ofs.open("Person.txt", ios::out | ios::binary);*/
//	
//	//4.写数据
//	Person p = { "张涛",18.1 };
//	ofs.write((const char*)&p, sizeof(p));
//
//	//5.关闭文件
//	ofs.close();
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}