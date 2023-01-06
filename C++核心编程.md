==C++核心编程==

本阶段主要介绍C++面向对向编程，核心、精髓！

# 1 内存四区

C++程序在执行时，将内存分为4个区域：

* 代码区：存放函数体的二进制代码
* 全局区：存放全局变量、静态变量、常量
* 栈区：系统自动分配释放，存放函数的参数值、局部变量等
* 堆区：程序员分配释放，若程序员不释放，程序结束时，操作系统回收



**内存四区意义：**

不同区域存放的数据，赋予不同的生命周期，可以更灵活编程

## 1.1 程序执行前

程序编译后，生成了exe，未执行该程序前分为两个区域

**代码区：**

​	存放CPU执行的机器指令

​	**共享**的，对于频繁被执行的程序，只需要在内存中有一份代码

​	**只读**的，防止程序意外修改了它的指令？

**全局区：**

​	全局变量、静态变量

​	常量区，字符串常量和其他常量也存放在此

​	==该区域数据在程序结束后由操作系统释放==

```c++
#include<iostream>
using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;

//const修饰的全局变量，全局常量 
const int c_g_a = 10;
const int c_g_b = 10;

int main()
{
	//局部变量
	int a = 10;
	int b = 10;
	cout << "局部变量a的地址：" << (int)&a << endl;
	cout << "局部变量a的地址：" << (int)&a << endl;

	//全局变量
	cout << "全局变量a的地址：" << (int)&g_a << endl;
	cout << "全局变量a的地址：" << (int)&g_b << endl;

	//静态变量
	static int s_a = 10;
	static int s_b = 10;
	cout << "静态变量s_a的地址为：" << (int)&s_a << endl;
	cout << "静态变量s_b的地址为：" << (int)&s_b << endl;

	//常量
	//字符串常量
	cout << "字符串常量的地址：" << (int)&"hello world" << endl;

	//const修饰的变量
	//全局变量、局部变量
	cout << "const修饰的全局变量c_g_a：" << (int)&c_g_a << endl;
	cout << "const修饰的全局变量c_g_b：" << (int)&c_g_b << endl;

	//局部常量
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "const修饰的局部变量c_l_a：" << (int)&c_l_a << endl;
	cout << "const修饰的局部变量c_l_a：" << (int)&c_l_b << endl;

	system("pause");
	return 0;
}
```

总结：

* C++在程序运行前分为全局区和代码区
* 代码区特点是共享和只读
* 全局区中存放全局变量、静态变量、常量
* 常量区存放const修饰的全局常量、字符串常量

## 1.2 程序运行后

**栈区：**

​	操作系统内存管理分配释放，存放函数的参数、局部变量等

​	==注意事项==：不要返回局部变量的地址，栈区开辟的数据由系统自动释放

示例：

```c++
#include<iostream>
using namespace std;

int* func()
{
	int a = 10;		//局部变量，存放在栈区
	return &a;		//返回局部变量地址
}

int main()
{
	//接收返回值
	int* p = func();
	cout << *p << endl;//第一次可以打印，编译器做了保留？
	cout << *p << endl;//第二次，不再保留了


	system("pause");
	return 0;
}
```

总结：

* 不要返回局部变量地址，==非法操作==

**堆区：**

​	程序员分配释放，若程序员不释放，程序结束时，操作系统回收

​	C++中主要使用==new==在堆区开辟数据！

示例：

```c++
#include<iostream>
using namespace std;

int* func()
{
	//new 创建数据到堆区
	return new int(10);		//返回的指针
}

int main()
{
	//堆区开辟数据
	int* p = func();

	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	system("pause");
	return 0;
}
```

总结：

​	堆区数据由程序员管理开辟和释放

​	利用new关键字开辟内存

## 1.3 new操作符

C++用new操作符在堆区开辟数据

堆区开辟的数据，由程序员手动开辟、释放，释放用delete操作符

语法：`new 数据类型`

利用new创建的数据，会返回该数据对应类型的指针

**示例1：基本语法**

**示例2：堆区开辟数组**

```c++
#include<iostream>
using namespace std;

//基本语法
int* func3()
{
	return new int(10);	//new关键字，指针
}
void test03()
{
	cout << *func3() << endl;	//地址解引用
	delete func3();
}

//开辟数组
void test04()
{
	int* arr=new int[10];	//堆区，数组

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i * i;
		cout << arr[i]<<" ";
	}
	cout << endl;
	
	//释放堆数组
	delete[] arr;
}

int main()
{
	test03();	//基本语法
	//test04();	//开辟数组

	system("pause");
	return 0;
}
```

**总结：**

* 开辟数组，`new int[10]`
* 释放数组，`delete[] arr`

------

# <font color="blue"> C++模板：</font>

```c++
#include<iostream>
using namespace std;


int main()
{
	

	system("pause");
	return 0;
}
```