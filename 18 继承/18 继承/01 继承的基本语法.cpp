//#include<iostream>
//using namespace std;
//
////基类
////class A:public B{}
//
//class BaseInfo
//{
//public:
//	void header()
//	{
//		cout << "首页、登录、注册..." << endl;
//	}
//	void footer()
//	{
//		cout << "帮助、交流、站内..." << endl;
//	}
//	void lefter()
//	{
//		cout << "Java、Python、C++..." << endl;
//	}
//};
//
//class CPP :public BaseInfo
//{
//public :
//	void content()
//	{
//		cout << "CPP..." << endl;
//	}
//};
//class Python :public BaseInfo
//{
//public:
//	void content()
//	{
//		cout << "Python..." << endl;
//	}
//};
////
//void case01()
//{
//	cout << "------------------------" << endl;
//	CPP().header();		//匿名对象
//	CPP().footer();
//	CPP().lefter();
//	CPP().content();
//	cout << "------------------------" << endl;
//	Python().header();
//	Python().footer();
//	Python().lefter();
//	Python().content();
//	cout << "------------------------" << endl;
//
//}
//int main()
//{
//	case01();//
//
//	system("pause");
//	return 0;
//}