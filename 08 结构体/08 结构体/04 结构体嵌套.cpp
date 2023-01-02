//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//
////学生
//struct Student
//{
//	string name;
//	int age;
//	int score;
//};
//
////老师
//struct Teacher
//{
//	int id;//编号
//	string name;//
//	int age;
//	Student stu;	//struct关键字可省
//};
//int main4()
//{
//
//	Teacher t1 =
//	{
//		10108,
//		"老王",
//		30,
//		{"涛",15,99}
//	};
//
//	//遍历，指针
//	Teacher* p = &t1;
//	cout << "id：" <<p->id  <<"	名字："<<p->name<< "	年龄：" << p->age << "	学生：" <<p->stu.name << endl;
//
//	system("pause");
//	return 0;
//}