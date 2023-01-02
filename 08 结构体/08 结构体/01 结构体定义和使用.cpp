//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////自定义数据类型，类型集合
//struct Student
//{
//	string name;
//	int age;
//	int score;
//}s3;		//定义时，顺便创建！
//int main1()
//{
//	//1.struct Student s1;
//	Student s1;				//创建变量时，struct可省略
//	s1.name = "张涛";
//	s1.age = 16;
//	s1.score = 100;
//	cout << "姓名：" << s1.name << "	年龄：" << s1.age << "	分数：" << s1.score << endl;	//vs2019不用引头文件？
//
//	//2.struct Student s2={...};
//	Student s2 = { "李四",20,99 };
//	cout << "姓名：" << s2.name << "	年龄：" << s2.age << "	分数：" << s2.score << endl;	//vs2019不用引头文件？
//
//	//3.定义时，顺便创建
//	s3= { "王五",20,99 };
//	cout << "姓名：" << s3.name << "	年龄：" << s3.age << "	分数：" << s3.score << endl;	//vs2019不用引头文件？
//
//	system("pause");
//	return 0;
//}