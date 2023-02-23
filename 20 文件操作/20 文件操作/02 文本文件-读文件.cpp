//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//#include<fstream>
//#include<string>
//
//void test01()
//{
//	//1.头文件
//	//2.流对象
//	ifstream ifs;
//
//	//3.打开方式，并判断是否打开成功
//	ifs.open("test01.txt", ios::in);
//
//	if (!ifs.is_open())
//	{
//		cout << "文件打开失败！" << endl;
//		return;
//	}
//	//4.读数据
//	//4种
//	////第一种
//	//char buf[1024] = { 0 };
//	//while (ifs>>buf)
//	//{
//	//	cout << buf << endl;
//	//}
//
//	////第二种
//	//char buf[1024] = { 0 };
//	//while (ifs.getline(buf,sizeof(buf)))
//	//{
//	//	cout << buf << endl;
//	//}
//
//	////第3种
//	//string buf;
//	//while (getline(ifs, buf))
//	//{
//	//	cout << buf << endl;
//	//}
//
//	//第4种
//	char c;
//	while ((c = ifs.get()) != EOF)		//endof file
//
//	{
//		cout << c;
//	}
//	
//	//5.关闭文件
//	ifs.close();
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}