#include<iostream>
using namespace std;

class MyAdd
{
public:
	int operator()(int a,int b)
	{
		return a + b;
	}
};
int main()
{
	//�º���������()����������

	cout << "a+b=" << MyAdd()(1,9)<< endl;

	system("pause");
	return 0;
}