//#include<iostream>
//using namespace std;
//
////爷、父、子继承
//class GrandFather
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//class Son:private GrandFather
//{
//public:
//	void func()
//	{
//		m_A = 100;
//		m_B = 10;
//		//m_C = 1;	//私有不可访问
//	}
//};
//
//class GrandSon:private Son
//{
//public:
//	void func()
//	{
//		//m_A = 10;		//私有化了，访问不到
//		//m_B = 11;
//	}
//};
//
//int main()
//{
//	system("pause");
//	return 0;
//}