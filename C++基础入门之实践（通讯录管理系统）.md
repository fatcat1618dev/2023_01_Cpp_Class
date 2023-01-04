# ==通讯录管理系统==

# 1 具体需求

通讯录，可以记录亲朋好友信息，该教程主要利用==C++==来编写一个==通讯录管理系统==。

主要功能有：

* 显示：显示通讯录中所有联系人信息
* ==添==加：添加联系人，信息包括（姓名、性别、年龄、手机、住址），最多记录1000条
* ==删==除：按姓名删除指定联系人
* ==查==找：按姓名查看联系人信息
* 修==改==：按姓名修改联系人信息
* 清空：清空通讯录所有联系人信息
* 退出：退出通讯录

# 2 创建项目

* 创建新项目>>空项目>>项目名称（如：==通讯录管理系统==，其它默认）>>创建
* 源文件>>添加>>新建项>>名称（如：==通讯录管理系统==，其它默认）>>添加

# 3 界面设计

用户选择功能的界面

==效果：==

![](E:\09_sd\vs2019\2023_01_Cpp_Class\assets\image-20230103210626010.png)

实现步骤：

* 封装一个可以显示该界面的函数，如`void Menu()`
* main函数中调用

代码：

```c++
#include<iostream>
using namespace std;

void menu()
{
	cout << "****************************" << endl;
	cout << "*****  1.添加  2.删除  *****" << endl;
	cout << "*****  3.查找  4.修改  *****" << endl;
	cout << "*****  5.显示  6.清空  *****" << endl;
	cout << "*****  0.退出          *****" << endl;
	cout << "****************************" << endl;

}
int main()
{
	menu();
	system("pause");
	return 0;
}
```

小结：

* cout屏幕打印

# 4 退出通讯录

描述：退出通讯录系统（界面）

思路：用switch分支实现，选择0，则退出程序

```c++
#include<iostream>
using namespace std;

void menu()
{
	cout << "****************************" << endl;
	cout << "*****  1.添加  2.删除  *****" << endl;
	cout << "*****  3.查找  4.修改  *****" << endl;
	cout << "*****  5.显示  6.清空  *****" << endl;
	cout << "*****  0.退出          *****" << endl;
	cout << "****************************" << endl;

}
enum select
{
	ADD=1,				//给值，从1开始
	DELETE,
	SEARCH,
	MODIFY,
	SHOW,
	CLEAR,
	EXIT=0				//0
};
int main()
{
	int select = 0;			//用户选择输入变量

	while (1)
	{
		menu();

		cout << "请选择：";
		cin >> select;		//输入
		switch (select)
		{
		case ADD:
			break;
		case DELETE:
			break;
		case SEARCH:
			break;
		case MODIFY:
			break;
		case SHOW:
			break;
		case CLEAR:
			break;
		case EXIT:
			cout << "欢迎下次继续使用！" << endl;
			//system("pause");	//方式1：按任意键继续，并退出
			//return 0;
			exit(0);			//方式2：立即退出
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			break;
		}
		system("cls");
	}


	system("pause");
	return 0;
}
```

==小结==：

* switch语句，case 0==退出功能==，退出方式1`exit(0);`，方式2`return 0;`
* switch case中，为==提升代码可读性==，用enum数据类型，枚举功能选项（ADD=1，直接给值...）
* ==清屏==`system("cls")`

# 5 添加联系人

联系人上限1000人，联系人信息包括：姓名、性别、年龄、手机、住址

实现步骤：

* 联系人结构体
* 通讯录结构体
* 封装联系人函数

## 5.1 联系人结构体

联系人信息：姓名、性别、年龄、手机、住址

```c++
//联系人结构体
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_PhoneNumber;
	string m_Addr;
};
```

注：

* 手机号用==string==，一串数字...
* sex用==int==，用户0/1选择

## 5.2 通讯录结构体

维护一个容量为1000的存放联系人的数组，并记录当前通讯录中联系人的数量

```c++
//通讯录结构体
struct ContactBooks
{
	struct Person personArray[MAX];	//通讯录数组，上限
	int m_Size;						//已有人员个数
};
```

* ==`#define MAX 1000`==，方便后期维护，上限未写死

## 5.3 实例化

**main函数中：**

* 初始化

```c++
	//通讯录变量，及初始化
	ContactBooks CBs;
	CBs.m_Size = 0;			//默认为空，没做本地存储
```

* ==函数定义==`void addPerson(ContactBooks* p)`
  * 函数调用`addPerson(&CBs)`
  * ==通讯录是否已满==
  * 年龄有效性 0-150
  * 手机号有效性 11位、纯数字（c++ strlen需要转化一下`int len = strlen(phonenumber.c_str());				//c++中的字符串长度`）

```c++
//添加联系人
void addPerson(ContactBooks* p)
{
	//通讯录是否已满
	if (p->m_Size == MAX)
	{
		cout << "通讯录已满！" << endl;
	}
	else
	{
		//准备添加
		//名字
		string name;
		cout << "请输入名字：";
		cin >> name;
		p->personArray[p->m_Size].m_Name = name;
		//性别
		int sex;
		cout << "请选择性别：";
		cout << "\t1 男    2 女" << endl;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)	//1 男  2 女
			{
				p->personArray[p->m_Size].m_Sex = sex;
				break;										//选择ok，则退出
			}
			cout << "请重新选择！" << endl;
		}
		//年龄
		int age;
		cout << "请输入年龄：";
		while (1)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				p->personArray[p->m_Size].m_Age = age;	//(0,150)之前有效
				break;
			}
			cout << "年龄无效，请重新输入！" << endl;
		}
		//手机
		string phonenumber;										//加个判断，11位、每位均为数字0-9
		cout << "请输入手机号：";
		while (1)
		{
			cin >> phonenumber;
			int len = strlen(phonenumber.c_str());				//c++中的字符串长度

			bool flag = 0;										//纯数字
			for (int i = 0; i < len; i++)
			{
				if (phonenumber[i] < '0' && phonenumber[i] > '9')
				{
					flag = 1;
					break;
				}
			}
			if (len == 11&&flag==0)
			{
				p->personArray[p->m_Size].m_PhoneNumber = phonenumber;
				break;
			}
			cout << "请检查号码长度及纯数字性..." << endl;
		}

		//地址
		string addr;
		cout << "请输入地址：";
		cin >> addr;
		p->personArray[p->m_Size].m_Addr = addr;
		
		//更新个数
		p->m_Size++;
		cout << "添加成功！" << endl;

		//清屏
		system("pause");//按任意键继续
		system("cls");
	}
}
```

# 6 显示联系人

显示通讯录中已有的联系人info

* 显示联系人函数
  * 三目运算 `(p->personArray[i].m_Sex==1?"男":"女")`

```c++
//显示联系人
void showPerson(ContactBooks*p)
{
	if (p->m_Size == 0)
	{
		cout << "没有联系人，请添加！" << endl;
	}
	else
	{
		cout << "姓名" << "\t" << "性别" << "\t" << "年龄"
			<< "\t" << "手机" << "\t\t" << "地址" << endl;
		for (int i = 0; i < p->m_Size; i++)
		{
			cout << p->personArray[i].m_Name <<"\t" << (p->personArray[i].m_Sex==1?"男":"女") << "\t" << p->personArray[i].m_Age
				 << "\t" << p->personArray[i].m_PhoneNumber << "\t" << p->personArray[i].m_Addr << endl;

		}
	}
	//清屏
	system("pause");//按任意键继续
	system("cls");
}
```

# 检测联系人

按照姓名检测联系人是否存在

思路：

删除联系人前，判断联系人是否存在，存在则下一步准备删除，不存在提示不存在

* 封装为函数，存在返回位置；不存在返回-1

```c++
//检测联系人是否存在，存在提示找到，不存在返回-1
int isExist(ContactBooks* p, string name)
{
	//遍历
	for (int i = 0; i < p->m_Size; i++)
	{
		if (p->personArray[i].m_Name == name)	//存在
		{
			cout << "找到了！" << endl;
			return i;
			break;
		}
	}
	cout << "查无此人！" << endl;
	return -1;
}
```

==注：需要break么？==

# 7 删除联系人

* 检测联系人返回 -1，则查无此人
* 检测联系人返回其它，查到然后删除

```c++
//删除联系人
void deletePerson(ContactBooks* p)
{
	string name;
	cout << "请输入要删除的联系人：";
	cin >> name;
	//是否存在
	//ret -1,查无此人
	//其它ret即具体位置
	int ret = isExist(p, name);
	if (ret == -1)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		for (int i = ret; i < p->m_Size; i++)	//遍历迁移
		{
			p->personArray[i] = p->personArray[i + 1];
		}
		//个数更新
		p->m_Size--;
		cout << "删除成功" << endl;
	}
	//任意键清屏
	system("pause");
	system("cls");
}
```

# 8 查找联系人

按照姓名查找联系人

实现方法：

* 封装1个查找联系人函数
  * 判断要查找的联系人是否存在
  * 存在则显示；不存在则查无此人

```c++
//查找联系人
void searchPerson(ContactBooks* p)
{
	cout << "请输入姓名：";
	string name;
	cin >> name;
	
	int ret = isExist(p, name);
	if(ret!=-1)
	{
		cout << "姓名" << "\t" << "性别" << "\t" << "年龄"
			<< "\t" << "手机" << "\t\t" << "地址" << endl;
		cout << p->personArray[ret].m_Name << "\t" << (p->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t" << p->personArray[ret].m_Age
			<< "\t" << p->personArray[ret].m_PhoneNumber << "\t" << p->personArray[ret].m_Addr << endl;

	}
	else
	{
		cout << "查无此人！" << endl;
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
```

# 9 修改联系人

按姓名查找，并修改联系人

实现步骤：

* 封装修改联系人函数
  * 判断联系人是否存在
  * 存在则修改，否则==提示查无此人==

```c++
//修改联系人
void modifyPerson(ContactBooks* p)
{
	cout << "请输入要修改的联系人姓名：";
	string name;
	cin >> name;

	int ret = isExist(p, name);
	if (ret != -1)
	{
		updatePerson(p,ret);			//更改ret位置联系人
		//提示信息
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
```

注：

* 结合添加联系人部分，又==摘出==共用代码块，`updatePerson(p,ret);`
* 重新封装==添加联系人==部分，如下

```c++
//添加联系人
void addPerson(ContactBooks* p)
{
	//通讯录是否已满
	if (p->m_Size == MAX)
	{
		cout << "通讯录已满！" << endl;
	}
	else
	{
		//准备添加
		//名字
		updatePerson(p,p->m_Size);			//通讯里联系人个数
		
		//更新个数
		p->m_Size++;
		cout << "添加成功！" << endl;

		//清屏
		system("pause");//按任意键继续
		system("cls");
	}
}
```

# 10 清空联系人

清空通讯中的所有信息

实现步骤：

* 封装清空联系人函数
  * 将通讯录中联系人数量==置0==，逻辑清空即可。

代码：

```c++
//清空联系人
//将通讯录记录的联系人数量置0，即可
void clearContactBooks(ContactBooks* p)
{
	p->m_Size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");
}
```

# 完整代码：

* 宏定义、枚举
* 逻辑清空（置0）
* ...

```c++
#include<iostream>
using namespace std;
#define MAX 1000
#include<string>
void menu()
{
	cout << "****************************" << endl;
	cout << "*****  1.添加  2.删除  *****" << endl;
	cout << "*****  3.查找  4.修改  *****" << endl;
	cout << "*****  5.显示  6.清空  *****" << endl;
	cout << "*****  0.退出          *****" << endl;
	cout << "****************************" << endl;

}
enum select
{
	ADD=1,				//给值，从1开始
	DELETE,
	SEARCH,
	MODIFY,
	SHOW,
	CLEAR,
	EXIT=0				//0
};
//联系人结构体
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_PhoneNumber;
	string m_Addr;
};
//通讯录结构体
struct ContactBooks
{
	struct Person personArray[MAX];	//通讯录数组，上限
	int m_Size;						//已有人员个数
};
//更新联系人
void updatePerson(ContactBooks* p,int index)	//索引哦，添加 p->m_Size; 更改则用 ret
{
	string name;
	cout << "请输入名字：";
	cin >> name;
	p->personArray[index].m_Name = name;
	//性别
	int sex;
	cout << "请选择性别：";
	cout << "\t1 男    2 女" << endl;
	while (1)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)	//1 男  2 女
		{
			p->personArray[index].m_Sex = sex;
			break;										//选择ok，则退出
		}
		cout << "请重新选择！" << endl;
	}
	//年龄
	int age;
	cout << "请输入年龄：";
	while (1)
	{
		cin >> age;
		if (age > 0 && age < 150)
		{
			p->personArray[index].m_Age = age;	//(0,150)之前有效
			break;
		}
		cout << "年龄无效，请重新输入！" << endl;
	}
	//手机
	string phonenumber;										//加个判断，11位、每位均为数字0-9
	cout << "请输入手机号：";
	while (1)
	{
		cin >> phonenumber;
		int len = strlen(phonenumber.c_str());				//c++中的字符串长度

		bool flag = 0;										//纯数字
		for (int i = 0; i < len; i++)
		{
			if (phonenumber[i] < '0' && phonenumber[i] > '9')
			{
				flag = 1;
				break;
			}
		}
		if (len == 11 && flag == 0)
		{
			p->personArray[index].m_PhoneNumber = phonenumber;
			break;
		}
		cout << "请检查号码长度及纯数字性..." << endl;
	}

	//地址
	string addr;
	cout << "请输入地址：";
	cin >> addr;
	p->personArray[index].m_Addr = addr;
}
//添加联系人
void addPerson(ContactBooks* p)
{
	//通讯录是否已满
	if (p->m_Size == MAX)
	{
		cout << "通讯录已满！" << endl;
	}
	else
	{
		//准备添加
		//名字
		updatePerson(p,p->m_Size);			//通讯里联系人个数
		
		//更新个数
		p->m_Size++;
		cout << "添加成功！" << endl;

		//清屏
		system("pause");//按任意键继续
		system("cls");
	}
}

//显示联系人
void showPerson(ContactBooks*p)
{
	if (p->m_Size == 0)
	{
		cout << "没有联系人，请添加！" << endl;
	}
	else
	{
		cout << "姓名" << "\t" << "性别" << "\t" << "年龄"
			<< "\t" << "手机" << "\t\t" << "地址" << endl;
		for (int i = 0; i < p->m_Size; i++)
		{
			cout << p->personArray[i].m_Name <<"\t" << (p->personArray[i].m_Sex==1?"男":"女") << "\t" << p->personArray[i].m_Age
				 << "\t" << p->personArray[i].m_PhoneNumber << "\t" << p->personArray[i].m_Addr << endl;

		}
	}
	//清屏
	system("pause");//按任意键继续
	system("cls");
}
//检测联系人是否存在，存在提示找到，不存在返回-1
int isExist(ContactBooks* p, string name)
{
	//遍历
	for (int i = 0; i < p->m_Size; i++)
	{
		if (p->personArray[i].m_Name == name)	//存在
		{
			cout << "找到了！" << endl;
			return i;
			break;
		}
	}
	//cout << "查无此人！" << endl;
	return -1;
}

//删除联系人
void deletePerson(ContactBooks* p)
{
	string name;
	cout << "请输入要删除的联系人：";
	cin >> name;
	//是否存在
	//ret -1,查无此人
	//其它ret即具体位置
	int ret = isExist(p, name);
	if (ret == -1)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		for (int i = ret; i < p->m_Size; i++)	//遍历迁移
		{
			p->personArray[i] = p->personArray[i + 1];
		}
		//个数更新
		p->m_Size--;
		cout << "删除成功" << endl;
	}
	//任意键清屏
	system("pause");
	system("cls");
}

//查找联系人
void searchPerson(ContactBooks* p)
{
	cout << "请输入姓名：";
	string name;
	cin >> name;
	
	int ret = isExist(p, name);
	if(ret!=-1)
	{
		cout << "姓名" << "\t" << "性别" << "\t" << "年龄"
			<< "\t" << "手机" << "\t\t" << "地址" << endl;
		cout << p->personArray[ret].m_Name << "\t" << (p->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t" << p->personArray[ret].m_Age
			<< "\t" << p->personArray[ret].m_PhoneNumber << "\t" << p->personArray[ret].m_Addr << endl;

	}
	else
	{
		cout << "查无此人！" << endl;
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(ContactBooks* p)
{
	cout << "请输入要修改的联系人姓名：";
	string name;
	cin >> name;

	int ret = isExist(p, name);
	if (ret != -1)
	{
		updatePerson(p,ret);			//更改ret位置联系人
		//提示信息
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//清空联系人
//将通讯录记录的联系人数量置0，即可
void clearContactBooks(ContactBooks* p)
{
	p->m_Size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//通讯录变量，及初始化
	ContactBooks CBs;
	CBs.m_Size = 0;			//默认为空，没做本地存储

	int select = 0;			//选择输入变量

	while (1)
	{
		menu();

		cout << "请选择：";
		cin >> select;		//输入
		switch (select)
		{
		case ADD:
			addPerson(&CBs);
			break;
		case DELETE:
			deletePerson(&CBs);	//查无此人、查到删除、数据迁移
			break;
		case SEARCH:
			searchPerson(&CBs);
			break;
		case MODIFY:
			modifyPerson(&CBs);
			break;
		case SHOW:
			showPerson(&CBs);
			break;
		case CLEAR:
			clearContactBooks(&CBs);
			break;
		case EXIT:
			cout << "欢迎下次继续使用！" << endl;
			//system("pause");	//方式1：按任意键继续，并退出
			return 0;
			//exit(0);			//方式2：立即退出
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			break;
		}
	}


	system("pause");
	return 0;
}
```

