//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////����ĳ�ʼ��������
////���캯�� ���г�ʼ������
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person���޲ι��캯���ĵ���" << endl;
//	}
//	Person(int a)
//	{
//		age = a;
//		cout << "Person���вι��캯���ĵ���" << endl;
//	}
//
//	//�������캯��
//	Person(const Person &p)
//	{
//		//�������˵�����ȫ���õ�
//		age = p.age;
//		cout << "Person�Ŀ������캯���ĵ���" << endl;
//	}
//	~Person()
//	{
//		cout << "Person���������ĵ���" << endl;
//	}
//	int age;
//};
//
////������������Ǳ��е�ʵ�֣�������ǲ��ṩ�����������ṩһ����ʵ�ֵĹ����������������û������cout���Ŀ�ʵ��
//void test01()
//{
//	////1.���ŷ�
//	//Person p;	//ջ�ϵ����ݣ����������٣�Ĭ�ϵ��÷�
//	//Person p2(10);	//�вι���
//	//Person p3(p2);	//��������
//
//	//cout << "p2�����䣺" << p2.age << endl;
//	//cout << "p3�����䣺" << p3.age << endl;		//��p2һ����ֱ�ӿ�����p2��
//
//	////ע��1������Ĭ�Ϲ��캯��ʱ����Ҫ��()
//	////����������Ϊ��һ����������������������
//	////Person p4();
//
//	////2.��ʽ��
//	//Person p1;
//	//Person p2 = Person(10);	//�вι���
//	//Person p3 = Person(p2);	//��������
//
//	//Person(10);	//�������� ��ǰִ�н�������������			�������ڶ�
//	//cout << "aaa" << endl;
//	////ע��2��
//	////��Ҫ���ÿ������캯�� ��ʼ���������� ����������ΪPerson(p3)=Person p3,�ض���
//
//	//3.��ʽת����
//	Person p4 = 10;	//�൱��Person p4=Person(10);	
//	Person p5 = p4;//
//}
//
//
//int main()
//{
//	test01();	//���졢����
//
//	system("pause");
//	return 0;
//}