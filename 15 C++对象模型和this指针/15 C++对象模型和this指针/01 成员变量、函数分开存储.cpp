//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////��������Ա�ֿ��洢
//class Person1
//{
//};
//class Person2
//{
//	int m_A;	//�Ǿ�̬��Ա����
//};
//class Person3
//{
//	int m_A;				//�Ǿ�̬��Ա�����������������
//	static int m_B;			//	��̬��Ա����������������
//	void func() {};		//�Ǿ�̬��Ա����������������
//	static void func2() {};	//	��̬��Ա����������������
//};
//int Person3::m_B = 10;		//���⸳ֵ
//
//void test01()
//{
//	Person1 p;
//	//�ն���ռ���ڴ�ռ䣺1
//	//c++���������ÿ���ն������һ���ֽڿռ䣬����ռ��λ�ã�
//	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
//	cout << "sizeof p= " << sizeof(p) << endl;
//}
//void test02()
//{
//	Person2 p;
//	cout << "sizeof p= " << sizeof(p) << endl;
//}
//void test03()
//{
//	Person3 p;
//	cout << "sizeof p= " << sizeof(p) << endl;
//}
//int main()
//{
//	test01();	//�ն���
//	test02();	//�Ǿ�̬��Ա����	
//	test03();	//��̬��Ա����	  ��������
//
//	system("pause");
//	return 0;
//}