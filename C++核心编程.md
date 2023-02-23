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

# 2 引用

## 2.1 基本用法

作用：给变量起==别名==，小名，外号？

语法：`数据类型 &别名=原名`



**示例：**

```c++
#include<iostream>
using namespace std;


int main()
{
	//引用的基本语法
	//数据类型 &别名=原名

	int a = 10;
	int& b = a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	b = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	cout << "原名a地址：" << (int)&a << endl;
	cout << "别名b地址：" << (int)&b << endl;

	int* p = &a;
	cout << "原名a地址：" << (int)&a << endl;
	cout << "指针p地址：" << (int)&(p) << endl;

	system("pause");
	return 0;
}
```

小结：

- 引用和普通指针不同，原名、别名地址一样



## 2.2 引用注意事项

* 初始化
* 初始化后，不可改变



**示例：**

```c++
#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	
	//引用初始化
	int& b = a;

	//初始化后不可改变
	int c = 20;
	b = c;		//赋值

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	system("pause");
	return 0;
}
```

小结：

* a/b/c全=20
* 引用本质，==常量指针==



## 2.3 传引用

**作用：**函数传参，引用可让形参修饰实参

**优点：**简化指针修改实参



**示例：**

```c++
#include<iostream>
using namespace std;

//交换函数
//传值
void myswap01(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//传址
void myswap02(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//传引用
void myswap03(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a = 10;
	int b = 20;

	//myswap01(a,b);					//传值	实参不变，形参变
	//myswap02(&a, &b);					//传址	实参变
	myswap03(a, b);

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	system("pause");
	return 0;
}
```

小结：

* 传引用和传址效果一样
* 引用语法更==简洁明了==

## 2.4 引用作为函数返回值

引用可以作为函数的返回值

注意：不要返回局部变量引用？

用法：函数调用作为左值



**示例1：**

```c++
#include<iostream>
using namespace std;

//不要返回局部变量引用
int& test04_1()
{
	int a = 10;	//存放在四区 栈区
	return a;
}
int main()
{
	int &ret = test04_1();

	cout << "ret=" << ret << endl;		//第一次ok，编译器做了保留
	cout << "ret=" << ret << endl;		//第二次不ok，a内存已经释放


	system("pause");
	return 0;
}
```

小结：

* vs2019：
  * x64/X86 Release模式下，都能输出10——<font color="red">**为啥捏**</font>
  * x64模式==两次都乱码==；x86模式第1次ok，==第2次乱码==

**示例2：**

```c++
#include<iostream>
using namespace std;

//不要返回局部变量引用
int& test04_1()
{
	int a = 10;	//存放在四区 栈区
	return a;
}

//函数调用作为左值
int& test04_2()
{
	static int a = 10;	//存放在四区 栈区
	return a;
}
int main()
{
	//int &ret = test04_1();
	//cout << "ret=" << ret << endl;		//第一次ok，编译器做了保留
	//cout << "ret=" << ret << endl;		//第二次不ok，a内存已经释放
	
	int& ret = test04_2();
	cout << "ret=" << ret << endl;		
	cout << "ret=" << ret << endl;		
	//函数作为左值赋值
	test04_2() = 1000;
	cout << "ret=" << ret << endl;		
	cout << "ret=" << ret << endl;		

	system("pause");
	return 0;
}
```

小结：

* 函数调用作为==左值==，引用

## 2.5 引用的本质

本质：C++内部通过==指针常量==实现，本质是==指针==

* 指针常量：* const，指针是常量，指向不可改，值可改
* 常量指针：const*， 常量的指针，值不可改，指向可改

```c++
#include<iostream>
using namespace std;

void func05(int& ref)		//自动转为，int* const ref=&a;
{
	ref = 99;				//内部转，*ref=99
}
int main()
{
	int a = 10;

	int& ref = a;		//自动转换为 int* const ref=&a;指针指向不可改，即引用不可更改
	ref = 100;			//自动内部发现是引用，自动转为*ref=100

	cout << "a=" << a << endl;
	cout << "ret=" << ref << endl;

	func05(a);
	cout << "a=" << a << endl;

	system("pause");
	return 0;
}
```

小结：

* 推荐使用引用，语法方便，简化版指针
* 引用本质是==指针==（指针常量），编译器帮处理指针操作

## 2.6 常量引用

```c++
#include<iostream>
using namespace std;

//引用、const
void showvalue(const int& a)
{
	//a=10;				//不可改
	cout << a << endl;
}
int main()
{

	//函数中使用常量引用，防止误操作修改实参
	//比如打印数据
	int a = 10;
	showvalue(a);

	system("pause");
	return 0;
}
```

小结：

* 形参不会影响外部实参



# 3 函数提高

<font color="pink">P95~P98</font>

## 3.1 函数的默认参数

C++中，函数的形参列表中的形参，可以有默认值

语法：`返回值类型 函数名（参数=默认值）{}`



**示例：**

```c++
#include<iostream>
using namespace std;

//函数默认参数
//传入数据则用自己的，否则用默认值
int func1(int a, int b, int c=99)
{
	return a + b + c;
}

//注意1：如果某个位置已经有了默认参数，从这个位置后从左向右都必须有默认值
//int func(int a, int b=10, int c)
//注意2：函数声明、定义中，有一个有默认参数即可
int func2(int a, int b, int c=99);

int func2(int a, int b, int c)
{
	return a * b * c;
}

int main()
{
	cout << func1(10, 20) << endl;
	cout << func2(10, 10) << endl;

	system("pause");
	return 0;
}
```

小结：

* 函数默认参数，如果某个位置已经有了默认参数，从这个位置后从左向右都必须有默认值
* 函数声明、定义两者中，只能==1个有默认参数==

## 3.2 函数占位参数

C++形参列表中可以有占位参数，用来占位，调用函数时需填补该位置

语法：`返回值类型 函数名（数据类型）{}`

现阶段存在意义不大，后面课程会用到



**示例：**

```c++
#include<iostream>
using namespace std;

//占位参数
//占位参数可以有默认参数

void func02(int a, int=10)				//没用，更没用了
{
	cout << "this is func" << endl;
}
int main()
{
	func02(10, 10);

	system("pause");
	return 0;
}
```

小结：

* 占位参数没用
* 占位参数有默认参数，更没用...

## 3.3 函数重载

### 3.3.1 概述

作用：函数名可以相同，提高复用性

条件：

* 同一个作用域下
* 函数名称相同
* 函数参数类型、个数、顺序不同

函数的返回值不可以作为函数重载的条件



**示例：**

```c++
#include<iostream>
using namespace std;

//函数重载
/*
* 同一个作用域下
* 函数名称相同
* 函数参数类型、个数、顺序不同
*/

void func()
{
	cout << "func()在调用" << endl;
}

void func(int a)
{
	cout << "func(int)在调用" << endl;
}
void func(double)
{
	cout << "func(double)在调用" << endl;
}
int main()
{
	func();
	func(3);
	func(3.14);

	system("pause");
	return 0;
}
```

### 3.3.2 注意事项

* 引用作为重载条件
* 函数重载碰到函数默认参数



**示例：**

```c++
#include<iostream>
using namespace std;

/*
* 引用作为重载条件
* 函数重载碰到函数默认参数
*/

//引用
void func04(int&a)
{
	cout << "func(int&a)调用" << endl;
}

void func04(const int& a)
{
	cout << "func(const int&a)调用" << endl;
}

//默认参数
void func04_1(int a, int b = 10)
{
	cout << "func04_1(int a,int b)" << endl;
}

void func04_1(int a)
{
	cout << "func04_1(int a)" << endl;
}

int main()
{
	int a = 10;
	func04(a);

	func04(10);			//

	//func04_1(10);		//默认参数，重载出现歧义，编译器傻了

	system("pause");
	return 0;
}
```

------

# 4 类和对象

<font color="pink">P99~P142</font>

C++面向对象的三大特性：

* 封装
* 继承
* 多态

C++认为==万物皆为对象==，对象上有其属性和行为



例如：

* 人，属性有姓名、年龄、身高、体重...，行为有走、跑、跳、唱...

* 车，属性有方向盘、车灯、仪表...,行为有开空调、放歌...

  具有相同性质的对象，可以抽象为类，人类、车类...

## 4.1 封装

<font color="pink">P99~P105</font>

### 4.1.1 意义

封装是C++面向对象的三大特性之一

**意义：**

1. 将属性、行为合体，表现生活中的事物
2. 将属性、行为加以权限控制



**意义1：**设计类时，属性、行为合为一个整体

语法：`class 类名{访问权限：属性/行为};`



**示例1：**设计一个圆类，求圆的周长

```c++
#include<iostream>
using namespace std;

//设计一个圆类，求圆的周长
//2*PI*r
const double PI = 3.141592653;

//class代表设计一个类，类后面跟着类名称
class Circle
{
	//访问权限
	//公共权限
public:

	//属性
	//半径
	double r;

	//行为
	//周长
	double cal_circumference()
	{
		return 2 * PI * r;
	}
};

int main()
{
	//实例化
	Circle c1;
	//对象赋值
	c1.r = 10;
	cout << "圆周长为：" << c1.cal_circumference() << endl;

	system("pause");
	return 0;
}
```

小结：

* public、属性、行为
* 实例化、赋值、行人调用



**示例2**：设计一个学生类，属性有姓名和学号，可以赋值、显示学生的姓名学号。

```c++
#include<iostream>
using namespace std;

//学生类
class Students
{
	//访问权限
public:

	//类中的属性和行为：统一称为 成员
	//属性	成员属性 成员变量
	//行为	成员函数 成员方法
	string m_Name;
	int m_ID;
	//行为
	void showinfo()
	{
		cout << "姓名：" << m_Name
			<< "\t学号：" << m_ID << endl;
	}
	//setName
	//setID
	void setName(string name)
	{
		m_Name = name;
	}
	void setID(int id)
	{
		m_ID = id;
	}
};

int main()
{
	Students s1;
	s1.m_Name = "张涛";
	s1.m_ID = 10086;
	s1.showinfo();

	s1.setName("杨新朋");
	s1.setID(10010);
	s1.showinfo();

	system("pause");
	return 0;
}
```

小结：

* 类中的属性、行为：成员
* 属性：成员属性、成员==变量==
* 行为：成员函数、成员==方法==



封装的意义2:

类在设计时，可以把属性和行为放在不同权限下，加以控制

* public
* protected
* private



**示例：**

```c++
#include<iostream>
using namespace std;

//访问权限
//三种
//pulic			成员 类内可 类外可  访问
//protected		成员 类内可 类外不可		继承	儿子可以访问父亲中的保护内容
//private		成员 类内可	类外不可				儿子不可访问父亲的私有内容

class Person
{
public:
	string m_Name;
protected:
	string m_Car;
private:
	int m_Password;
public:
	void func()
	{
		m_Name = "张涛";
		m_Car = "迈巴赫";
		m_Password = 123456;
	}
};
int main()
{
	Person p1;
	p1.m_Name = "杨新朋";
	//p1.m_car = "宝马";
	//p1.m_password = 125436;

	system("pause");
	return 0;
}
```

小结：

* 类外无法访问私有成员属性、方法

### 4.1.2 struct和class的区别

C++中两者唯一的区别是**默认的访问权限不同**

* struct默认公共
* ==class默认私有==

```c++
#include<iostream>
using namespace std;

class C1
{
	int m_A;	//默认private
};
struct C2
{
	int m_A;	//默认public
};
int main()
{
	//class 权限默认私有
	C1 c1;
	//c1.m_A = 10;	//无法访问

	C2 c2;
	c2.m_A = 100;	//ok

	system("pause");
	return 0;
}
```



### 4.1.3 成员属性设置为私有

==优点：==

1. 将所有成员属性设为私有，可以自己控制读写权限
2. 写权限，可以检测数据的有效性



**示例：**

```c++
#include<iostream>
using namespace std;

//人类
class Person_
{
public:
	//情人
	void setLover(string lover)
	{
		if (lover !=  "canglaoshi")
		{
			cout << "Invalid！" << endl;
			return;
		}
		m_lover = lover;
	}
	string getLover()
	{
		cout << "有效，老师为：";
		return m_lover;
	}
private:
	string m_lover;
};
int main()
{
	Person_ p;
	cout << "请选择老师：";
	string lover;
	cin >> lover;
	p.setLover(lover);
	cout << p.getLover() << endl;;

	system("pause");
	return 0;
}
```



### 4.1.4 案例练习

#### ==I 立方体类==

* 设计立方体类（Cube），求面积、体积
* 分别用全局、成员函数判断两个立方体是否相等

```c++
#include<iostream>
using namespace std;

//立方体类
class Cube
{

public:
	//设置长、获取长
	void setL(double L)
	{
		m_L = L;
	}
	double getL()
	{
		return m_L;
	}
	// 设置宽、获取宽
	void setW(double W)
	{
		m_W = W;
	}
	double getW()
	{
		return m_W;
	}
	// 设置高、获取高
	void setH(double H)
	{
		m_H = H;
	}
	double getH()
	{
		return m_H;
	}
	//area
	double cal_area()							//cal_S
	{
		return (m_L * m_W +m_L* m_H+m_W*m_H)*2;	//6个面
	}
	//volume
	double cal_volume()							//cal_V
	{
		return m_L * m_W * m_H;
	}
	//成员函数
	bool isSame_class(Cube& c1)
	{
		if (c1.cal_area() ==cal_area() && c1.cal_volume() == cal_volume())	//和类内比
		{
			return true;
		}
		return false;
	}

private:
	double m_L;
	double m_W;
	double m_H;
};

//全局函数
//面积、体积都一样，返回1，一致
//否则返回false,不一样

bool isSame_global(Cube& c1, Cube &c2)
{
	if (c1.cal_area() == c2.cal_area() && c1.cal_volume() == c2.cal_volume())
	{
		return true;
	}
	return false;
}

int main()
{
	Cube c1;
	c1.setL(2);
	c1.setW(4);
	c1.setH(8);
	cout << "面积area：" << c1.cal_area() << endl;
	cout << "体积area：" << c1.cal_volume() << endl;

	Cube c2;
	c2.setL(4);
	c2.setW(8);
	c2.setH(1);
	cout << "面积area：" << c2.cal_area() << endl;
	cout << "体积area：" << c2.cal_volume() << endl;

	//全局函数
	(isSame_global(c1, c2) == 1) ? cout << "全局函数：立方体一样！" << endl: cout << "全局函数：立方体不同！" << endl;

	//成员函数	传1个参数即可，+引用
	(c1.isSame_class(c2) == 1) ? cout << "Class成员函数：立方体一样！" << endl : cout << "Class成员函数：立方体不同！" << endl;

	system("pause");
	return 0;
}
```

小结：

* 全局函数：引用、==传入2个==cube
* 成员函数：引用、==传入1个==cube即可



#### ==II 点和圆的关系==

* 设计一个圆类、点类 Circle Point
* 计算点和圆的关系

```c++
#include<iostream>
using namespace std;

//Point
class Point1
{
public:
	//输入、获取
	void setx(double x)
	{
		m_x = x;
	}
	double getx()
	{
		return m_x;
	}
	void sety(double y)
	{
		m_y = y;
	}
	double gety()
	{
		return m_y;
	}
private:
	double m_x;
	double m_y;
};
//Cicle
class Circle1
{
public:
	//半径、圆心
	//输入、获取
	void setr(double r)
	{
		m_r = r;
	}
	double getr()
	{
		return m_r;
	}
	void setCenter(Point1 center)
	{
		m_Center = center;
	}
	Point1 getCenter()
	{
		return m_Center;
	}
private:

	double m_r;		//半径
	Point1 m_Center;	//圆心
};

//点离圆心距离跟半径比，三种结果
int flag_rel(Circle1& c, Point1& p)
{
	double tmp = (c.getCenter().getx() - p.getx()) * (c.getCenter().getx() - p.getx()) + (c.getCenter().gety() - p.gety()) * (c.getCenter().gety() - p.gety()) - c.getr() * c.getr();

	if (tmp > 0)	//圆外
	{
		return 1;
	}
	else //圆上/内
	{
		return tmp == 0 ? 0 : -1;
	}
}

int main()
{
	Circle1 c;	//半径r的圆,坐标(x,y)处
	c.setr(10);
	Point1 center;
	center.setx(0);
	center.sety(0);
	c.setCenter(center);	

	Point1 p;	//坐标(x,y)处的点
	p.setx(0);
	p.sety(0);

	int ret =flag_rel(c,p);
	if (ret == 1)
	{
		cout << "全局函数：点在圆外" << endl;
	}
	else
	{
		(ret == 0) ? (cout << "全局函数：点在圆上" << endl) : (cout << "全局函数：点在圆内" << endl);
	}
	system("pause");
	return 0;
}
```

**==小结：==**

* circle类中嵌套point类
* 点与圆心的距离，与半径比较，三种情况（圆内、上、外）

### 4.1.5 点和圆的关系-头文件、cpp文件拆分

#### I *point文件*

* .h文件

  * ```c++
     #pragma once
     #include<iostream>
     using namespace std;
    ```

 ```c++
  #define _CRT_SECURE_NO_WARNINGS 1
  #pragma once
  #include<iostream>
  using namespace std;
  
  //Point
  class Point2
  {
  public:
  	//输入、获取
  	void setx(double x);
  
  	double getx();
  
  	void sety(double y);
  
  	double gety();
  
  private:
  	double m_x;
  	double m_y;
  };
 ```

  * .cpp文件
    * 作用域：`Point2::`
    * 只保留方法部分


```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include"point.h"
//Point
void Point2::setx(double x)
{
	m_x = x;
}
double Point2::getx()
{
	return m_x;
}
void Point2::sety(double y)
{
	m_y = y;
}
double Point2::gety()
{
	return m_y;
}
```

#### II Circle文件

* .h文件

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
#include "point.h"

//Cicle
class Circle2
{
public:
	//半径、圆心
	//输入、获取
	void setr(double r);

	double getr();

	void setCenter(Point2 center);

	Point2 getCenter();

private:

	double m_r;		//半径
	Point2 m_Center;	//圆心
};

```

* .cpp文件
  * 作用域：`Circle2::`

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include"circle.h"

//Cicle
//半径、圆心
//输入、获取
void Circle2::setr(double r)
{
	m_r = r;
}
double Circle2::getr()
{
	return m_r;
}
void Circle2::setCenter(Point2 center)
{
	m_Center = center;
}
Point2 Circle2::getCenter()
{
	return m_Center;
}
```

#### III 主文件

* 引用

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include "circle.h"
////Point
//class Point1
//{
//public:
//	//输入、获取
//	void setx(double x)
//	{
//		m_x = x;
//	}
//	double getx()
//	{
//		return m_x;
//	}
//	void sety(double y)
//	{
//		m_y = y;
//	}
//	double gety()
//	{
//		return m_y;
//	}
//private:
//	double m_x;
//	double m_y;
//};
////Cicle
//class Circle1
//{
//public:
//	//半径、圆心
//	//输入、获取
//	void setr(double r)
//	{
//		m_r = r;
//	}
//	double getr()
//	{
//		return m_r;
//	}
//	void setCenter(Point1 center)
//	{
//		m_Center = center;
//	}
//	Point1 getCenter()
//	{
//		return m_Center;
//	}
//private:
//
//	double m_r;		//半径
//	Point1 m_Center;	//圆心
//};

//点离圆心距离跟半径比，三种结果
int flag_rel(Circle2& c, Point2& p)
{
	double tmp = (c.getCenter().getx() - p.getx()) * (c.getCenter().getx() - p.getx()) + (c.getCenter().gety() - p.gety()) * (c.getCenter().gety() - p.gety()) - c.getr() * c.getr();

	if (tmp > 0)	//圆外
	{
		return 1;
	}
	else //圆上/内
	{
		return tmp == 0 ? 0 : -1;
	}
}

int main()
{
	Circle2 c;	//半径r的圆,坐标(x,y)处
	c.setr(10);
	Point2 center;
	center.setx(0);
	center.sety(0);
	c.setCenter(center);

	Point2 p;	//坐标(x,y)处的点
	p.setx(0);
	p.sety(0);

	int ret = flag_rel(c, p);
	if (ret == 1)
	{
		cout << "全局函数：点在圆外" << endl;
	}
	else
	{
		(ret == 0) ? (cout << "全局函数：点在圆上" << endl) : (cout << "全局函数：点在圆内" << endl);
	}
	system("pause");
	return 0;
}
```

## 4.2 对象的初始化和清理

<font color="pink">P106~P113</font>

* 生活中电子产品，如手机有出厂设置
* C++中的面向对象来源于生活，高于生活，每个对象也都有初始设置以及销毁前的数据清理



### 4.2.1 构造函数和析构函数

对象的**初始化**和清理是2个非常重要的安全问题

​	一个对象或者变量没有初始状态，对其使用后果未知

​	同样的，使用完一个对象或变量，没有及时清理也会造成一定的安全问题



C++利用构造函数、析构函数解决上述问题，这两个函数会被编译器自动调用，完成初始化和清理。对象的初始化和清理工作是编译器强制我们要做的事情，因此如果我们不提供构造、析构，编译器会提供构造、析构是空实现的。

* 构造函数：创建对象时为对象成员属性赋值，编译器会自动调用
* 析构函数：清理，对象销毁前系统自动调用



**构造函数语法**：`类名(){}`

1. 没有返回值也不写void
2. 函数名称和类名相同
3. 构造函数可以有参数，因此可以发生重载
4. 程序在调用对象时会自动调用构造，无须手动调用，而且只调用1次



**析构函数语法：**`~类名(){}`

1. 没有返回值，也不写void
2. 函数名称和类名相同，名称前加~
3. 无参数，不可以发生重载
4. 程序在对象销毁前自动调用析构，无须手动调用，而且只调用1次



```c++
#include<iostream>
using namespace std;

//对象的初始化和清理
//构造函数 进行初始化操作
class Person
{
public:
	Person()
	{
		cout << "Person构造函数的调用" << endl;
	}
	~Person()
	{
		cout << "Person析构函数的调用" << endl;
	}
};

//构造和析构都是必有的实现，如果我们不提供，编译器会提供一个空实现的构造和析构，，，即没有上述cout语句的空实现
void test01()
{
	Person p;	//栈上的数据，创建和销毁
}
int main()
{
	test01();	//构造、析构

	Person p1;	//程序结束，才调用析构

	system("pause");
	return 0;
}
```

小结：

* 构造和析构：若我们不提供编译器则提供一个空实现的构造和析构



### 4.2.2 构造函数的分类及调用

两类：

* 参数：有参、无参构造
* 类型：普通、拷贝构造

三种调用方式

* 括号法
* 显示法
* 隐式转换法



**示例：**

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//对象的初始化和清理
//构造函数 进行初始化操作
class Person
{
public:
	Person()
	{
		cout << "Person的无参构造函数的调用" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "Person的有参构造函数的调用" << endl;
	}

	//拷贝构造函数
	Person(const Person &p)
	{
		//将传入人的属性全部拿到
		age = p.age;
		cout << "Person的拷贝构造函数的调用" << endl;
	}
	~Person()
	{
		cout << "Person析构函数的调用" << endl;
	}
	int age;
};

//构造和析构都是必有的实现，如果我们不提供，编译器会提供一个空实现的构造和析构，，，即没有上述cout语句的空实现
void test01()
{
	////1.括号法
	//Person p;	//栈上的数据，创建和销毁，默认调用法
	//Person p2(10);	//有参构造
	//Person p3(p2);	//拷贝构造

	//cout << "p2的年龄：" << p2.age << endl;
	//cout << "p3的年龄：" << p3.age << endl;		//和p2一样，直接拷贝的p2的

	////注意1：调用默认构造函数时，不要加()
	////编译器会认为是一个函数声明，不创建对象
	////Person p4();

	////2.显式法
	//Person p1;
	//Person p2 = Person(10);	//有参构造
	//Person p3 = Person(p2);	//拷贝构造

	//Person(10);	//匿名对象 当前执行结束后，立即回收			生存周期短
	//cout << "aaa" << endl;
	////注意2：
	////不要利用拷贝构造函数 初始化匿名对象 编译器会认为Person(p3)=Person p3,重定义

	//3.隐式转换法
	Person p4 = 10;	//相当于Person p4=Person(10);	
	Person p5 = p4;//
}


int main()
{
	test01();	//构造、析构

	system("pause");
	return 0;
}
```



### 4.2.3 拷贝构造函数调用时机

C++中调用时机通常有三种情况：

* 使用一个已经创建完毕的对象来初始化一个新对象
* 值传递的方式给函数传值
* 以值方式返回局部对象

示例：

```c++
#include<iostream>
using namespace std;

//拷贝构造函数的调用时机
/*
* 使用一个已经创建完毕的对象来初始化一个新对象
* 值传递的方式给函数传值
* 以值方式返回局部对象
*/
class Person
{
public:
	Person()
	{
		cout << "无参构造函数" << endl;
	}
	Person(int age)
	{
		m_Age = age;
		cout << "有参构造函数" << endl;
	}
	Person(const Person& p)
	{
		m_Age = p.m_Age;
		cout << "COPY构造函数" << endl;

	}
	~Person()
	{
		cout << "析构函数" << endl;
	}
	int m_Age;
};

//1.使用1个已经创建完毕的对象来初始化
void test01()
{
	Person p2(10);
	Person p3(p2);
	cout << "p3的年龄：" << p3.m_Age << endl;
}

//2.使用值传递方式给函数传值
void doWork(Person p)
{

}
void test02()
{
	Person p;
	doWork(p);
}

//3.以值方式返回局部对象
Person doWork2()
{
	Person p1;
	cout << (int)&p1 << endl;
	return p1;
}
void test03()
{
	Person p = doWork2();
	cout << (int)&p << endl;
}
int main()
{
	//test01();			
	//test02();
	test03();

	system("pause");
	return 0;
}
```



### 4.2.4 构造函数调用规则

默认情况下，C++编译器至少给一个类添加3个函数

1. 默认==构造==函数（无参、函数体为空）
2. 默认==析构==函数（无参、函数体为空）
3. 默认==拷贝构造==函数，对属性进行值拷贝



调用规则：

* 如用户定义有参构造函数，c++不再提供默认无参构造函数，但会提供默认拷贝构造
* 如果用户定义了拷贝构造函数，c++不再提供其它构造函数

​	<font color="pink">默认——》有参——》拷贝构造</font>，提供了后面的，编译器就不提供前面的了

示例：

```c++
#include<iostream>
using namespace std;

/*
1. 默认==构造==函数（无参、函数体为空）
2. 默认==析构==函数（无参、函数体为空）
3. 默认==拷贝构造==函数，对属性进行值拷贝
*/
class Person
{
public:
	Person()
	{
		cout << "默认构造函数" << endl;
	}
	Person(int age)
	{
		m_Age = age;
		cout << "有参构造函数" << endl;
	}
	Person(const Person& p)
	{
		m_Age = p.m_Age;
		cout << "COPY构造函数" << endl;

	}
	~Person()
	{
		cout << "析构函数" << endl;
	}
	int m_Age;
};

void test01()		//默认情况下，C++编译器至少给一个类添加3个函数
{
	Person p;
	p.m_Age = 18;

	Person p2(p);
	cout << "p2的年龄：" <<p2.m_Age<< endl;
}

//提供有参
void test02()
{
	Person p;
}
int main()
{
	//test01();	//3个函数
	test02();

	system("pause");
	return 0;
}
```



### 4.2.5 深拷贝与浅拷贝

深拷贝与浅拷贝，经典问题

* 浅拷贝：简单的赋值拷贝操作
* 深拷贝：在堆区重新申请空间，拷贝操作



示例：

```c++
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "默认构造函数" << endl;
	}
	Person(int age,int height)
	{
		m_Age = age;
		m_Height = new int(height);
		cout << "有参构造函数" << endl;
	}
	Person(const Person& p)
	{
		m_Age = p.m_Age;
		//m_Height = p.m_Height;	

		//深拷贝
		m_Height = new int(*p.m_Height);	//内容一样，指向不一样
		cout << "COPY构造函数" << endl;
	}

	~Person()
	{
		//析构代码，释放堆区开辟的数据
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;	//置空，防野指针
		}
		cout << "析构函数" << endl;
	}
	int m_Age;
	int* m_Height;
};

//用系统的copy构造
void test01()
{
	Person p1(18,160);
	Person p2(p1);	//系统copy函数			浅copy
	cout << "p2年龄：" << p2.m_Age << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
```

* ==用堆区，析构重复释放，栈区先进后出，p2释放了、p1再释放就崩了==
* ==深copy，堆区重新开辟空间，解决该问题==



### 4.2.6 初始化列表

作用：

C++提供了初始化列表语法，初始化属性

语法：`构造函数():属性1(值1)，属性2(值2)...{}`



示例：

```c++
#include<iostream>
using namespace std;

class Person
{
public:
	
	////传统初始化
	//Person(int a,int b,int c)
	//{
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//	cout << "有参构造函数" << endl;
	//}

	////初始化列表，固化版
	////传统赋值初始化相当于，先声明类，再赋值
	////初始化列表，直接声明一个有初值的类型，大型项目中，class类中成员变量极多情况下，初始化列表更高效
	//Person() :m_A(10), m_B(20), m_C(30)
	//{
	//}
	Person(int a,int b,int c):m_A(a),m_B(b),m_C(c)
	{

	}
	int m_A;
	int m_B;
	int m_C;
};

//用系统的copy构造
void test01()
{
	/*Person p1(1, 2, 3);*/

	Person p1(1,2,3);
	cout << "m_A=" << p1.m_A << endl;
	cout << "m_B=" << p1.m_B << endl;
	cout << "m_C=" << p1.m_C << endl;

}

int main()
{
	test01();

	system("pause");
	return 0;
}
```

* 构造函数，==初始化列表==

  ```c++
  Person(int a,int b,int c):m_A(a),m_B(b),m_C(c)
  	{
  
  	}
  ```

  

### 4.2.7 类对象作为类成员

C++类中的成员可以是另一个类的对象，称对象成员



例如：

```c++
class A{}
class B
{
    A a;
}
```

* 之前的点和圆的关系，类似？

```c++
#include<iostream>
using namespace std;

//手机
class Phone
{
public:
	//初始化列表
	Phone(string phonetype):m_PhoneType(phonetype)
	{
		cout << "Phone构造函数" << endl;
	}
	~Phone()
	{
		cout << "Phone析构函数" << endl;
	}
	string m_PhoneType;
};
//人
class Person
{
public:
	//初始化列表
	Person(string name,string phone):m_Name(name),m_Phone(phone)
	{
		cout << "Person构造函数" << endl;

	}
	~Person()
	{
		cout << "Person析构函数" << endl;
	}
	string m_Name;
	Phone m_Phone;
};


void test01()
{
	Person p("张涛","苹果13");
	cout << p.m_Name << "拿着"<< p.m_Phone.m_PhoneType << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
```

![](assets\张涛-拿着手机.png)

* ==构造手机——》构造人——》人拿着手机——》人析构——》手机析构==

### 4.2.8 静态成员

静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员



静态成员：

* 变量
  * 所有对象共享同1份数据
  * 编译阶段分配内存
  * 类内声明、类外初始化

```c++
#include<iostream>
using namespace std;

//人
class Person
{
public:
	//初始化列表
	Person()
	{	
		cout << "Person构造函数" << endl;
	}
	~Person()
	{
		cout << "Person析构函数" << endl;
	}
	static string m_Name;

};
string Person::m_Name = "张涛";	//作用域初始化

void test01()
{
	Person p;
	cout << p.m_Name << endl;

	Person p2;
	p2.m_Name = "杨新朋";
	cout << p.m_Name << endl;

	//类名访问
	cout << Person::m_Name << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
```

* 类名访问：
  * `Person::m_Name`

* 函数
  * 所有对象共享同1函数
  * 静态成员函数只能访问静态成员变量

## 4.3 C++对象模型和this指针

<font color="pink">P114~P117</font>

### 4.3.1 成员变量、函数分开存储

C++中，类内的成员变量、函数分开存储

只有==非静态成员变量==才属于类的对象上

```c++
#include<iostream>
using namespace std;

//变量、成员分开存储
class Person1
{
};
class Person2
{
	int m_A;	//非静态成员变量
};
class Person3
{
	int m_A;				//非静态成员变量，属于类对象上
	static int m_B;			//	静态成员变量，不属于类上
	void func() {};		//非静态成员函数，不属于类上
	static void func2() {};	//	静态成员函数，不属于类上
};
int Person3::m_B = 10;		//类外赋值

void test01()
{
	Person1 p;
	//空对象占用内存空间：1
	//c++编译器会给每个空对象分配一个字节空间，区分占的位置，
	//每个空对象也应该有一个独一无二的内存地址
	cout << "sizeof p= " << sizeof(p) << endl;
}
void test02()
{
	Person2 p;
	cout << "sizeof p= " << sizeof(p) << endl;
}
void test03()
{
	Person3 p;
	cout << "sizeof p= " << sizeof(p) << endl;
}
int main()
{
	test01();	//空对象
	test02();	//非静态成员变量	
	test03();	//静态成员变量	  不在类上

	system("pause");
	return 0;
}
```

小结：

* 空对象占1个字节
* 只有==非静态变量==占对象空间



### 4.3.2 this指针

C++通过提供特殊的对象指针，this指针，解决上述问题，==this指向被调用的成员函数所属的对象==

* this指针隐含在每一个非静态成员函数内
* this指针不需定义，直接使用

用途：

* 形参和成员变量同名时，可用this指针区分c——==解决名称冲突==（编程要规范哦）
* 在类的非静态成员函数中返回对象本身，可用return *this——返回对象本身（==链式编程==）



```c++
#include<iostream>
using namespace std;

//
class Person
{
public:
	Person(int age)
	{
		//this指向被调用的成员函数所属的对象,成员函数p1
		this->age = age;
	}

	//引用 链式编程
	Person& PersonAddAge(Person& p)
	{
		this->age += p.age;
		return *this;	//返回本身
	}

	//值返回——拷贝构造 副本
	Person PersonAddAge1(Person& p)
	{
		this->age += p.age;
		return *this;	//返回本身
	}
	int age;
};

//1.解决名称冲突
//方法1：编码规范 m_age
//方法2：this指针
void test01()
{
	Person p1(18);	//有参构造
	cout << "年龄为：" << p1.age << endl;
}

//2.返回对象本身*this

void test02()
{
	Person p2(20);
	Person p3(10);
	p2.PersonAddAge(p3).PersonAddAge(p2);	//20+10+30
	cout << "p3年龄：" << p2.age << endl;
}

void test03()
{
	Person p2(20);
	Person p3(10);
	p2.PersonAddAge1(p3).PersonAddAge1(p2);	//拷贝构造,1次后就copy副本
	cout << "p3年龄：" << p2.age << endl;
}

int main()
{
	test01();	//
	test02();	//链式访问
	test03();

	system("pause");
	return 0;
}
```



### 4.3.3 空指针访问成员函数

C++中空指针==也可调用成员函数==，用到this指针时，需要保证代码的健壮性，判断return

示例：

```c++
#include<iostream>
using namespace std;

//空指针调用成员函数
class Person
{
public:
	Person():m_Age(18)
	{
		;
	}
	void showClassName()
	{
		cout << "This is Person Class!" << endl;
	}
	
	void showAge()
	{
		if (this == NULL)
		{
			return;
		}
		cout << "Age=" << m_Age << endl;
	}
	int m_Age;
};

void test01()
{
	Person p;
	p.showClassName();
	p.showAge();			//空指针 还访问里面的成员，无中生有

}
int main()
{
	test01();

	system("pause");
	return 0;
}
```



### 4.3.4 const修饰成员函数

**常函数：**

* 成员函数==后==加const，称为常函数
* 常函数内不可修改成员属性
* 成员属性声明时加关键字mutable，在常函数中可改

**常对象：**

* 声明对象前加const，称为常对象
* 常对象只能调用常函数



示例：

```c++
#include<iostream>
using namespace std;

//常函数
class Person
{
public:

	//this指针的本质 指针常量 指向不可改
	//const Person* const this
	Person() :m_Age(18), m_B(22) {}

	void showPersonAge() const
	{
		//m_Age = 100;	//不可改
		//m_B = 100;
		cout << m_B << endl;
	}
	void func(){}

	int m_Age;
	mutable int m_B;
};

void test01()
{
	Person p1;
	p1.showPersonAge();
}

//常对象
void test02()
{
	const Person p2;	//变为常对象
	//p2.m_Age = 100;		
	p2.m_B = 99;		//mutable
	p2.showPersonAge();

	//常对象只能调常函数
	//p2.func();
}
int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}
```



## 4.4 友元

<font color="pink">P118~P120</font>

生活中你的家有客厅public、卧室private，客厅会客一般都可以进去，你的卧室则只有你、你的闺蜜、基友...能进去



程序中，有些私有属性让类外特殊的一些函数或者类访问，就需要用去友元



友元的目的就是让一个函数或者类 访问另一个类中的私有成员，关键字friend



友元的3种实现：

* ==全局函数==做友元
* ==类==作友元
* ==成员函数==作友元

### 4.4.1 全局函数做友元

```c++
#include<iostream>
using namespace std;

//全局函数作友元
class House
{
	//goodguy是house好朋友，权限放开
	friend void goodguy(House* house);	//声明？
public:
	House():m_LivingRoom("客厅"),m_BedRoom("卧室") {}		//列表初始化
	//House()
	//{
	//	m_LivingRoom = "客厅";
	//	m_BedRoom = "卧室";
	//}
public:
	string m_LivingRoom;
private:
	string m_BedRoom;
};

//全局函数
void goodguy(House* house)			//指针或引用都可
{
	cout << "好基友	全局函数	正在访问：" << house->m_LivingRoom << endl;
	cout << "好基友	全局函数	正在访问：" << house->m_BedRoom << endl;

} 
void test01()
{
	House h;
	goodguy(&h);

}
int main()
{

	test01();

	system("pause");

	return 0;
}
```



* 友元声明？

  ```c++
  	//goodguy是house好朋友，权限放开
  	friend void goodguy(House* house);	//声明？
  ```

### 4.4.2 类作友元

代码：

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//类做友元，好基友访问客厅、卧室
class House;
class Goodguy
{
public:
	Goodguy();
	~Goodguy();
	//访问行为
	void visit();
	//房子指针
	House* h;
};

class House
{
	friend class Goodguy;	//好朋友
public:
	House();
	~House();
public:
	string m_Livingroom;
private:
	string m_Bedroom;
};

//类外成员函数
//列表初始化构造函数
House::House() :m_Livingroom("客厅"), m_Bedroom("卧室") { cout << "House 构造" << endl; };
House::~House()
{
	cout << "House 析构 " << endl;
}
Goodguy::Goodguy()
{
	h = new House();			//无参构造
	cout << "Goodguy 构造！" << endl;
}
Goodguy::~Goodguy()
{
	cout << "Goodguy	析构	堆区的house数据" << endl;
	if (h != NULL)
	{
		delete h;
		h = NULL;
	}
}
void Goodguy::visit()
{
	cout << "好基友类 正在访问 " << h->m_Livingroom << endl;
	cout << "好基友类 正在访问 " << h->m_Bedroom << endl;			//可访问卧室了

}

//测试案例
void test01()
{
	Goodguy gg;
	gg.visit();
}
int main()
{
	test01();

	system("pause");
	return 0;
}
```

* 堆上数据释放（判断是否为NULL），自己写的不一定对...

* 核心代码

* ==house构造——》goodguy构造——》访问客厅、卧室——》goodguy析构——》house析构==

  ```c++
  	friend class Goodguy;	//好朋友
  ```

  

### 4.4.3 成员函数作友元

和类类似，几个点：

* ```c++
  	//friend class goodguy;	//好朋友
  	friend void goodguy::visit1();
  ```

* 类外定义实现函数方法，**==作用域==**

```c++
#define _crt_secure_no_warnings 1
#include<iostream>
using namespace std;

//类做友元，好基友访问客厅、卧室
class house;
class goodguy
{
public:
	goodguy();
	~goodguy();
	//访问行为
	void visit1();
	void visit2();
	//房子指针
	house* h;
};

class house
{
	//friend class goodguy;	//好朋友
	friend void goodguy::visit1();
public:
	house();
	~house();
public:
	string m_livingroom;
private:
	string m_bedroom;
};

//类外成员函数
//列表初始化构造函数
house::house() :m_livingroom("客厅"), m_bedroom("卧室") { cout << "house 构造" << endl; };
house::~house()
{
	cout << "house 析构 " << endl;
}
goodguy::goodguy()
{
	h = new house();			//无参构造
	cout << "goodguy 构造！" << endl;
}
goodguy::~goodguy()
{
	cout << "goodguy	析构	堆区的house数据" << endl;
	if (h != NULL )
	{
		delete h;
		h = NULL;
	}
}
void goodguy::visit1()
{
	cout << "好基友类 正在访问 " << h->m_livingroom << endl;
	cout << "好基友类 正在访问 " << h->m_bedroom << endl;			//可访问卧室了

}

void goodguy::visit2()
{
	cout << "好基友类 正在访问 " << h->m_livingroom << endl;
	//cout << "好基友类 正在访问 " << h->m_bedroom << endl;			//可访问卧室了

}
//测试案例
void test01()
{
	goodguy gg;
	gg.visit1();
	gg.visit2();
}
int main()
{
	test01();

	system("pause");
	return 0;
}
```



## 4.5 运算符重载

<font color="pink">P121~P126</font>

对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型



### 4.5.1 加号



实现两个自定义数据类型相加的运算

* 成员函数重载+
* 全局函数重载+

```c++
#include<iostream>
using namespace std;

//加号运算符重载
//自定义类型，如两个person属性的加法运算

class Person
{
public:
	//Person operator+(Person& p);
	int m_A;
	int m_B;
};


////1 成员函数重载+，全局类似，不过要传入两个参数
//Person Person::operator+(Person& p)
//{
//	Person tmp;
//	tmp.m_A = this->m_A + p.m_A;
//	tmp.m_B = this->m_B + p.m_B;
//	return tmp;
//}

//全局函数重载+
Person operator+(Person& p1, Person& p2)
{
	Person tmp;
	tmp.m_A = p1.m_A + p2.m_A;
	tmp.m_B = p1.m_A + p2.m_B;
	return tmp;
}

void test01()
{
	Person p1;
	p1.m_A = 1;
	p1.m_B = 2;

	Person p2;
	p2.m_A = 10;
	p2.m_B = 20;
	
	Person p3 = p1 + p2;
	cout << "p3 m_A="<<p3.m_A << endl;
	cout << "p3 m_B=" <<p3.m_B << endl;
}

void test02()
{
	Person p1;
	p1.m_A = 1;
	p1.m_B = 2;

	Person p2;
	p2.m_A = 10;
	p2.m_B = 20;

	Person p3 = p1 + p2;
	cout << "p3 m_A=" << p3.m_A << endl;
	cout << "p3 m_B=" << p3.m_B << endl;
}

int main()
{
	//test01();//成员函数重载
	test01();//全局函数重载+
	system("pause");

	return 0;
}
```

* 成员函数重载+，==operator+==
* 全局函数重载+，==operator+==



### 4.5.2 左移

可以输出自定义的类型

```c++
#include<iostream>
using namespace std;

//左移运算符重载
class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);//友元
public:
	//列表初始化
	Person(int a,int b):m_A(a),m_B(b){}
private:
	int m_A;
	int m_B;
};

//全局函数 重载 左移<<运算符
ostream& operator<<(ostream& cout, Person& p)
{
	cout << "a:" << p.m_A << " b:" << p.m_B << endl;
	return cout;
}
void test01()
{
	Person p1(6, 9);			//有参构造

	cout << p1 << endl;			//链式编程

}
int main()
{
	test01();

	system("pause");
	return 0;
}
```

* 左移运算符<<，只能全局函数重载，cout 是==ostream==类型！
* 友元访问类内部数据，类内最顶部 `friend ostream& operator<<(ostream& cout, Person& p);//友元`



### 4.5.3 递增



重载递增运算符，实现自己的整形数据

* 递增运算符重载，前置++、后置++
* 递减运算符重载，前置--、后置--



前置++、后置++

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//递增运算符重载
//前置++、后置++

class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger i);

public:
	MyInteger() :m_Num(0){}	//列表初始化，构造函数

	//重载前置++	++a
	MyInteger& operator++()
	{
		m_Num++;
		return *this;
	}
	//重载后置++	a++
	MyInteger operator++(int)	//占位符
	{
		//副本
		MyInteger tmp=*this;			//用指针
		m_Num++;
		return tmp;
	}
private:
	int m_Num;
};

ostream& operator<<(ostream& cout, MyInteger i)
{
	cout << i.m_Num;
	return cout;
}
void test01()	//常规使用
{
	int i=0;
	cout << i << endl;
}

void test02()
{
	MyInteger j;
	cout << j << endl;
}

void test03()
{
	MyInteger a;
	cout << ++a << endl;
	cout << a << endl;

	MyInteger b;
	cout << b++ << endl;
	cout << b << endl;
}
int main()
{
	test01();//常规使用
	test02();//重载MyInteger运算符
	test03();

	system("pause");
	return 0;
}
```

* MyInteger的列表初始化
* 传引用、传值`ostream& operator<<(ostream& cout, MyInteger i)`
  * 考虑到前置++返回值传引用、后置传值，上面左移重载输入==第二个参数 用 MyInteger i，不用引用==！

前置--、后置--

```c++
#include<iostream>
using namespace std;

//递-运算符重载		
//前置--、后置--
//5 --5 4 4
//5 5-- 5 4
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger i);

public:
	MyInteger() :m_Num(5) {}	//列表初始化，构造函数

	//重载前置--	--a
	MyInteger& operator--()
	{
		m_Num--;
		return *this;
	}
	//重载后置--	a--
	MyInteger operator--(int)	//占位符
	{
		//副本
		MyInteger tmp = *this;			//用指针
		m_Num--;
		return tmp;
	}
private:
	int m_Num;
};

ostream& operator<<(ostream& cout, MyInteger i)
{
	cout << i.m_Num;
	return cout;
}
void test01()	//常规使用
{
	int i = 0;
	cout << i << endl;
}

void test02()
{
	MyInteger j;
	cout << j << endl;
}

void test03()
{
	MyInteger a;
	cout << --a << endl;
	cout << a << endl;

	MyInteger b;
	cout << b-- << endl;
	cout << b << endl;
}
int main()
{
	test01();//常规使用
	test02();//重载MyInteger运算符
	test03();

	system("pause");
	return 0;
}
```

* 和前置、后置++一致



### 4.5.4 赋值

C++编译器至少给一个类添加4个函数：

1. 默认构造函数（无参，函数体为空）
2. 默认析构参数（无参，函数体为空）
3. 默认拷贝构造函数，对属性进行值拷贝
4. 赋值运算符operator=，对属性进行值拷贝



如果类中有属性指向堆区，做赋值操作时也会出现==深浅拷贝==问题，**要重写析构函数，避免重复释放内存**



示例：

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//p3(30)=p2(20)=p1(10)	连等，链式编程
class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);	//友元

public:
	//列表
	Person(int a)
	{
		m_A = new int(a);		//堆区，深拷贝
	}

	//= 成员函数，重载
	Person& operator=(Person& p)
	{
		if (m_A != NULL)
		{
			delete m_A;
			m_A = NULL;
		}
		m_A = new int(*p.m_A);
		return *this;
	}
	~Person()
	{
		if (m_A != NULL)
		{
			delete m_A;
			m_A = NULL;
		}
	}

	int *m_A;
};

//左移<<重载
ostream& operator<<(ostream& cout, Person& p)
{
	cout << *p.m_A;
	return cout;
}



//测试01
void test01()
{
	Person p1(10);
	cout << p1 << endl;
}

void test02()	//<<	=运算符重载
{

	Person p1(2);
	Person p2(4);
	Person p3(6);
	p3 = p2 = p1;
	cout << p2 << endl;
	cout << p3 << endl;

}
int main()
{
	cout << "1.普通" << endl;
	test01();//正常赋值、显示

	cout << "2.运算符重载——左移<<	赋值=——" << endl;
	test02();

	system("pause");
	return 0;
}
```

* 左移<<	运算符重载
* 赋值=      运算符重载
  * 堆区、==深拷贝== ——new，避免内存重复释放



### 4.5.5 关系

重载关系运算符，让两个==自定义类型对象==进行对比操作



示例：

```c++
#include<iostream>
using namespace std;

//Person == !=，重载
class Person
{
public:
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	//重构==
	bool operator == (Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}

	//重构!=
	bool operator != (Person& p)
	{
		if (this->m_Name != p.m_Name || this->m_Age != p.m_Age)
		{
			return true;
		}
		return false;
	}

	string m_Name;
	int m_Age;
};

void test01()
{
	Person p1("张涛", 18);
	Person p2("张涛", 18);
	Person p3("新朋", 16);

	p1 == p2 ? cout << "相等" <<endl: cout << "不等" << endl;
	p2 != p3 ? cout << "不等" << endl : cout << "相等" << endl;

}
int main()
{
	test01();

	system("pause");
	return 0;
}
```

* ==    重载，可返回bool类型，后续根据这个判断
* !=     重载



### 4.5.6 函数调用

* 函数调用运算符（）也可重载
* 重载后使用方式很像函数的调用，也称为==仿函数==
* 仿函数无固定写法，非常灵活



示例：

```c++
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
	//仿函数、重载()、匿名对象

	cout << "a+b=" << MyAdd()(1,9)<< endl;

	system("pause");
	return 0;
}
```

* 仿函数——重载小括号()
* ==匿名对象==——类型+小括号，执行完当前行立即释放



## 4.6 继承

<font color="pink">P127~P134</font>



**继承是面向对象三大特性之一**



定义某些类时，下级别成员除了拥有上一级的==共性==，还有自己的特性，这时==可以用继承，减少重复代码==！



### 4.6.1 基本语法

class A: public B;

* A类称为==子==类	==派生==类
  * 一类基类继承的，表现共性
  * 一类自己新增的，表现个性
* B类称为==父==类    ==基==类

代码：

```c++
#include<iostream>
using namespace std;

//基类
//class A:public B{}

class BaseInfo
{
public:
	void header()
	{
		cout << "首页、登录、注册..." << endl;
	}
	void footer()
	{
		cout << "帮助、交流、站内..." << endl;
	}
	void lefter()
	{
		cout << "Java、Python、C++..." << endl;
	}
};

class CPP :public BaseInfo
{
public :
	void content()
	{
		cout << "CPP..." << endl;
	}
};
class Python :public BaseInfo
{
public:
	void content()
	{
		cout << "Python..." << endl;
	}
};
//
void case01()
{
	cout << "------------------------" << endl;
	CPP().header();		//匿名对象
	CPP().footer();
	CPP().lefter();
	CPP().content();
	cout << "------------------------" << endl;
	Python().header();
	Python().footer();
	Python().lefter();
	Python().content();
	cout << "------------------------" << endl;

}
int main()
{
	case01();//

	system("pause");
	return 0;
}
```



### 4.6.2 继承方式

语法：`class 子类 ：继承方式 父类`

其中继承方式有3种：

* 公共继承
  * 父类中公共权限成员，公共权限
  * 父类中保护权限成员，保护权限，类外访问不到
  * 父类中私有权限访问不到
* 保护继承
  * 父类中公共权限成员，==变为==保护权限，类外访问不到
  * 父类中保护权限成员，        保护权限，类外访问不到
  * 父类中私有权限成员，访问不到
* 私有继承
  * 父类中公共权限成员，==变为==私有权限
  * 父类中保护权限成员，==变为==私有权限
  * 父类中私有权限成员，访问不到

```c++
#include<iostream>
using namespace std;

//爷、父、子继承
class GrandFather
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son:private GrandFather
{
public:
	void func()
	{
		m_A = 100;
		m_B = 10;
		//m_C = 1;	//私有不可访问
	}
};

class GrandSon:private Son
{
public:
	void func()
	{
		//m_A = 10;		//私有化了，访问不到
		//m_B = 11;
	}
};

int main()
{
	system("pause");
	return 0;
}
```



### 4.6.3 继承中的对象模型

从父类继承过来的成员，哪些属于子类对象中？



示例：

```c++
#include<iostream>
using namespace std;

//爷、父、子继承
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son:private Base
{
public:
	int m_D;
};

void case01()
{
	Son s1;
	cout << sizeof(s1) << endl;
}


int main()
{
	case01();	//16 bytes

	system("pause");
	return 0;
}
```

* ==开发人员命令提示工具==查看对象模型	Visual Studio 2019 Developer Command ==Prompt== v16.11.11
  * 跳转盘符 如F:
  * cd具体路径下
  * cl /d1 reportSingleClassLayout类名 文件名，如`cl /d1 reportSingleClassLayoutSon "03 继承中的对象模型.cpp"`
    * cl，==l小写的L==
    * 文件名，03然后tab自动补齐

<img src="assets\image-20230111234026688.png" alt="image-20230111234026688" style="zoom:67%;" />

<img src="assets\image-20230111234621202.png" alt="image-20230111234621202" style="zoom: 67%;" />

* 父类中的私有成员也被子类继承了，限制访问了



### 4.6.4 继承中构造和析构顺序

子类继承父类后，当创建子对象时，也用调用父类构造函数，那父类和子类的构造、析构顺序是？



示例：

```c++
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base构造" << endl;
	}
	~Base()
	{
		cout << "Base析构" << endl;
	}
};

class Son:public Base
{
public:
	Son()
	{
		cout << "Son构造" << endl;
	}
	~Son()
	{
		cout << "Son析构" << endl;
	}
};

//
void case01()
{
	Son s;
}
int main()
{
	case01();

	system("pause");
	return 0;
}
```

* 构造父类、子类
* 析构           子类、父类，==和构造相反==



### 4.6.5 继承同名成员处理方式



当子类与父类出现同名成员，如何通过子类对象，访问到子类或父类中的同名数据？

* 访问子类同名成员	直接访问即可
* 访问父类同名成员    加作用域



示例：

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//继承中的同名成员
//成员属性
//函数
class Base
{
public:
	Base()
	{
		m_A = 100;
	}
	void func()
	{
		cout << "Base 成员函数" << endl;
	}
	int m_A;
};
class Son:public Base
{
public:
	Son()
	{
		m_A = 200;
	}
	void func()
	{
		cout << "Son 成员函数" << endl;
	}
	int m_A;
};

void case01()
{
	Son s;
	cout << "Son m_A	" << s.m_A << endl;
	cout << "Base m_A	" << s.Base::m_A << endl;

}
int main()
{

	case01();
	system("pause");
	return 0;
}
```

* 子类对象可直接访问子类中的同名成员，加作用域可访问到父类同名成员
* 同名成员函数类似



### 4.6.6 继承同名静态成员处理方式



问题：继承中同名的静态成员在子类对象上如何进行访问？

静态成员、非静态成员出现同名，处理方式一致：

* 访问子类同名成员	直接访问
* 访问父类同名成员    ==加作用域==

```c++
#include<iostream>
using namespace std;

//同名静态成员

class Base
{
public:
	static int m_A;
	static void func()
	{
		cout << "Base 下 func()" << endl;
	}
	static void func(int)
	{
		cout << "Base 下 func(int)" << endl;
	}
};
//类外初始化

int Base::m_A = 45;

class Son:public Base
{
public:
	static int m_A;
	static void func()
	{
		cout << "Son 下 func()" << endl;
	}
};
int Son::m_A = 20;

void case01()
{
	//通过对象访问
	cout << "通过对象访问： "<<endl;
	Son s;
	cout << "Son 下 m_A " << s.m_A << endl;
	cout << "Base 下 m_A " << s.Base::m_A << endl;

	//2.通过类名访问
	cout << "通过类名访问" << endl;
	cout << "Son 下 m_A " << Son::m_A << endl;
	//通过类名、父类作用域下
	cout << "Base 下 m_A " <<Son::Base::m_A<< endl;
}

void case02()
{
	//通过对象访问
	cout << "通过对象访问： " << endl;
	Son s;
	s.func();
	s.Base::func();

	//2.通过类名访问
	cout << "通过类名访问" << endl;
	Son::func();
	//通过类名、父类作用域下
	Son::Base::func();
}
int main()
{
	case01();
	cout << "---------------------------" << endl;
	case02();
	system("pause");
	return 0;
}
```



### 4.6.7 多继承语法

> C++允许一个类继承多个类
>
> 语法：`class 子类：继承方式 父类1，继承方式 父类2...`
>
> 多继承可能会引发父类中有同名成员出现，需要==加作用域==区分，实际开发中==不建议用==



示例：

```c++
#include<iostream>
using namespace std;

//多继承，多个父类
class Base1
{
public:
	Base1()
	{
		m_A = 1;
		m_B = 0;
	}
	int m_A;
	int m_B;
};

class Base2
{
public:
	Base2()
	{
		m_B = 2;
	}
	int m_B;
};

class Son :public Base1, public Base2
{
public:
	Son()
	{
		m_C = 3;
	}
	int m_C;
};

void test01()
{
	Son	s;
	cout << s.m_A << endl;
	cout << s.Base1::m_B << endl;
	cout << s.Base2::m_B << endl;
	cout << s.m_C << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
```

* 多继承中若父类中出现了同名，子类使用时，==加上作用域==



### 4.6.8 菱形继承



菱形继承（钻石继承）：

* 两个派生类继承同一个基类
* 某个类同时继承两个派生类



典型案例：

* 动物
* 羊、驼
* 羊驼（草泥马）

问题：

* 羊、驼都继承了动物数据
* 草泥马分别继承羊、驼，动物数据继承了两份，使用数据时，就会产生二义性（动物数据1份即可）



```c++
#include<iostream>
using namespace std;

//动物
class Animal
{
public:
	int m_Age = 10;
};
//羊
class Sheep :virtual public Animal{};
//驼
class Camel :virtual public Animal{};
//草泥马
class Alpaca:public Sheep,public Camel {};

void test01()
{
	Alpaca yt;
	//菱形继承，父类相同数据，加作用域区分
	yt.Sheep::m_Age = 6;
	yt.Camel::m_Age = 3;

	//菱形继承相同数据有两份，资源浪费
	//virtual关键字，虚继承	虚基指针
	cout << "Animal "<<yt.m_Age << endl;
	cout << "Sheep " << yt.m_Age << endl;
	cout << "Camel " << yt.m_Age << endl;

}
int main()
{
	test01();

	system("pause");
	return 0;
}
```

* 菱形继承问题是，子类继承了两份相同数据，导致资源浪费
* 利用虚继承可解决菱形继承问题（虚基指针 vbptr）

> ==开发人员命令提示工具==查看对象模型	Visual Studio 2019 Developer Command ==Prompt== v16.11.11
>
> * 跳转盘符 如F:
> * cd具体路径下
> * cl /d1 reportSingleClassLayout类名 文件名，如`cl /d1 reportSingleClassLayoutAlpaca 08`，tab键，自动补齐:
>   * cl，==l小写的L==
>   * 文件名，03然后tab自动补齐
>
> <img src="assets\image-20230112231300641.png" alt="image-20230112231300641" style="zoom: 67%;" />



## 4.7 多态

<font color="pink">P135~P142</font>

###  4.7.1 多态的基本概念



多态是C++面向对象的三大特性之一

多态分两类：

* 静态多态：函数重载和运算符重载都属于静态多态，复用函数名
* 动态多态：==派生类==和==虚函数==，实现运行时多态

区别：

* 静态多态的函数地址==早==绑定——==编译阶段==确定函数地址
* 动态多态的函数地址==晚==绑定——==运行阶段==确定函数地址



示例：

```c++
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()
	{
		cout << "Animal在说话！" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "Dog在说话！" << endl;
	}
};
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Cat在说话！" << endl;
	}
};

void doSpeak(Animal& p)
{
	p.speak();
}

void test01()
{
	Dog d;
	doSpeak(d);

	Cat c;
	doSpeak(c);
}
int main()
{
	test01();

	system("pause");
	return 0;
}
```

* 基类中有virtual关键字，==虚函数==！
* ==C++规定，当一个类中的成员函数被声明为虚函数后，派生类中的同名函数都自动成为虚函数，因此，子类重新声明该函数时，可加、可不加virtual关键字！==



**小结：**

多态满足条件：

*  有继承关系
* 子类==重写父类中的虚函数==

多态使用条件：

* 父类引用（指针）指向子类对象

重写：

* 函数返回类型	函数名	参数列表，3者完全一致，称为重写



#### **原理剖析：**

```c++
class Animal
{
public:
	virtual void speak()
	{
		cout << "Animal在说话！" << endl;
	}
};
```

* 虚函数，sizeof(Animal)，4，==虚函数指针==vfptr，virtual function pointer，结构发生了改变！
  * 虚函数指针，虚函数表
* 若无virtual关键字，sizeof(Animal)，1，空类大小为1

<img src="assets\image-20230113000838606.png" alt="image-20230113000838606" style="zoom:67%;" /><img src="assets\image-20230113001010579.png" alt="image-20230113001010579" style="zoom:67%;" />

* 左图cat子类未重写父类中虚函数，注释掉了；右图重写了父类中虚函数
* 可见vftable虚函数表内容不一样，vfptr虚函数指针根据==不同函数地址==入口，执行不同函数



### 4.7.2 案例1 计算器类

需求：

* 普通写法，设计实现两个操作数进行运算的计算器类
* 多态技术，设计实现两个操作数进行运算的计算器类



多态的优点：

* 代码组织结构清晰
* 可读性强
* 利于前期、后期的扩展及维护



示例：

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//普通实现
class Calc
{
public:
	Calc(int a, int b)	//构造函数
	{
		m_Num1 = a;
		m_Num2 = b;
	}
	//计算
	int getResult(string oper)
	{
		if (oper == "+")
			return m_Num1 + m_Num2;
		else if (oper == "-")
			return m_Num1 - m_Num2;
		else if (oper == "*")
			return m_Num1 * m_Num2;
		else if (oper == "/")
			return m_Num1 / m_Num2;

		//扩展，需要修改源码
		//开闭原则，扩展开放、修改关闭
	}
	int m_Num1;
	int m_Num2;
};

void test01()
{
	Calc c(5, 10);
	cout << c.m_Num1<<" + "<<c.m_Num2<<" = "<<c.getResult("+") << endl;
	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
	cout << c.m_Num1 << " / " << c.m_Num2 << " = " << c.getResult("/") << endl;

}

//多态实现计算器类
//计算器抽象类
class AbstractCalc
{
public:
	virtual int getResult()
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//加法
class AddCalc :public AbstractCalc
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};
//减法
class SubCalc :public AbstractCalc
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
//乘法
class MulCalc :public AbstractCalc
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

//除法
class DivCalc :public AbstractCalc
{
public:
	int getResult()
	{
		return m_Num1 / m_Num2;
	}
};

//多态条件
//父类引用（指针）指向子类对象
//虚函数

void test02()
{
	//乘法
	AbstractCalc* p = new MulCalc;
	p->m_Num1 = 5;
	p->m_Num2 = 10;
	cout << p->getResult() << endl;
	//销毁
	delete p;

	//减法
	p = new SubCalc;
	p->m_Num1 = 5;
	p->m_Num2 = 10;
	cout << p->getResult() << endl;
	//销毁
	delete p;
}
int main()
{
	//test01();

	test02();
	system("pause");
	return 0;
}
```

小结：

* C++提倡利用多态设计==程序架构==，多态优点很多



### 4.7.3 纯虚函数和抽象类

在多态中，通常父类中虚函数的实现是无意义的，主要都是调用子类重写的内容，因此可以将虚函数改为==纯虚函数==！

语法：`virtual 返回值类型 函数名（参数列表）=0;`

当类中有了纯虚函数，这个类也称为抽象类！

特点：

* 无法实例化对象
* 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
class Base
{
public:
	virtual void func() = 0;
};

class Son :public Base
{
public:
	void func() 
	{
		cout << "子类调用" << endl;
	};
};
//不重写，无法创建对象
void test01()
{
	/*Son s;
	s.func();*/

	Base* p = new Son;
	p->func();
}
int main()
{
	test01();

	system("pause");
	return 0;
}
```



### 4.7.4 案例2 制作饮品

描述：制作饮品大致分为煮水、冲泡、倒入杯中、加入辅料4步

利用多态，尝试制作饮品：

* 咖啡——纯净水、糖&牛奶
* 红茶——矿泉水、柠檬

```c++
#include<iostream>
using namespace std;

//基类、纯虚函数
class MakeDrink
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void Pour() = 0;
	//加入辅料
	virtual void AddSometing() = 0;
	void makeDrink()
	{
		Boil();
		Brew();
		Pour();
		AddSometing();
	}
};

//咖啡
class makeCoffee :public MakeDrink
{
	//煮水
	virtual void Boil()
	{
		cout << "煮纯净水..." << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡..." << endl;
	}
	//倒入杯中
	virtual void Pour()
	{
		cout << "倒入瓷杯..." << endl;
	}
	//加入辅料
	virtual void AddSometing()
	{
		cout << "加糖、牛奶..." << endl;
	}
};

//红茶
class makeBlackTea :public MakeDrink
{
	//煮水
	virtual void Boil()
	{
		cout << "煮矿泉水..." << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡红茶..." << endl;
	}
	//倒入杯中
	virtual void Pour()
	{
		cout << "倒入茶具中..." << endl;
	}
	//加入辅料
	virtual void AddSometing()
	{
		cout << "加入柠檬..." << endl;
	}
};

void doWork(MakeDrink* p)
{
	p->makeDrink();
}


void test01()
{
	cout << "..........制作咖啡.........." << endl;
	doWork(new makeCoffee);
	cout << "..........制作红茶.........." << endl;
	doWork(new makeBlackTea);

}
int main()
{
	test01();

	system("pause");
	return 0;
}
```

* 用指针，父类指向子类



### 4.7.5 虚析构和纯虚析构

多态使用中，如子类中有属性开辟到堆区，那么==父类指针==在释放时<u>无法调用到子类的析构代码</u>

解决办法：

* 将父类中的析构函数改为==虚析构==或==纯虚析构==



虚、纯析构共性：

* 可解决父类指针释放子类对象
* 都==需要具体的函数实现==

区别：

* 纯虚析构属于抽象类，无法实例化对象



虚析构语法：

`virtual ~类名（）{}`

纯虚析构语法：

`virtual ~类名（）=0;`

`类名::~类名(){}`



```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal构造" << endl;
	}
	virtual ~Animal()
	{
		cout << "Animal析构" << endl;
	}
	virtual void speak() = 0;//纯虚
};

class Cat:public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat构造" << endl;
		m_Name = new string(name);
	}
	~Cat()
	{
		cout << "Cat析构" << endl;
		delete m_Name;					//未走该行代码
		m_Name = NULL;

	}
	void speak()
	{
		cout <<*m_Name<< "小猫在说话！" << endl;
	}
	string *m_Name;
};

void test01()
{
	Animal *p=new Cat("Tom");
	p->speak();
	delete p;		//释放才析构
}
int main()
{
	test01();

	system("pause");
	return 0;
}
```

* 利用==虚析构==、纯虚析构，通过父类指针释放子类对象		解决父类指针释放子类对象不干净的问题   ==如子类在堆区开辟的内存==
* 如子类中没有堆区数据，可不写虚析构、或纯虚析构
* 拥有纯虚析构函数的类也属于抽象类，不能实例化对象。。。。

```c++
	virtual ~Animal()
	{
		cout << "Animal析构" << endl;
	}
```



### 4.7.6 案例3 电脑组装

案例描述：

电脑主要组成部件：CPU、GPU、内存，将每个零件封装出==抽象基类==并提供不同的厂商生产不同的零件，如Intel、Lenovo

创建电脑类提供让电脑工作的函数，并调用每个零件工作的接口

组装3台不同的电脑进行工作

```c++
#include<iostream>
using namespace std;

class Cpu
{
public:
	virtual void calculate() = 0;
};

class Gpu
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

//厂商，Intel/Lenovo
class IntelCpu:public Cpu
{
public:
	void calculate()
	{
		cout << "Intel的CPU运行ing" << endl;
	}
};
class LenovoCpu :public Cpu
{
public:
	void calculate()
	{
		cout << "Lenovo的CPU运行ing" << endl;
	}
};

//GPU
class IntelGpu :public Gpu
{
public:
	void display()
	{
		cout << "Intel的GPU运行ing" << endl;
	}
};
class LenovoGpu :public Gpu
{
public:
	void display()
	{
		cout << "Lenovo的GPU运行ing" << endl;
	}
};
//内存
class IntelMemory :public Memory
{
public:
	void storage()
	{
		cout << "Intel的DDR运行ing" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	void storage()
	{
		cout << "Lenovo的DDR运行ing" << endl;
	}
};

//电脑类
class PC
{
public:
	PC(Cpu* cpu,Gpu* gpu,Memory* mem)
	{
		m_Cpu = cpu;
		m_Gpu = gpu;
		m_Memory = mem;
	}
	void pcRun()
	{
		m_Cpu->calculate();
		m_Gpu->display();
		m_Memory->storage();
	}
	~PC()
	{
		cout << "析构指针" << endl;
		if (m_Cpu != NULL)
		{
			delete m_Cpu;
			m_Cpu = NULL;
		}
		if (m_Gpu != NULL)
		{
			delete m_Gpu;
			m_Gpu = NULL;
		}
		if (m_Memory != NULL)
		{
			delete m_Memory;
			m_Memory = NULL;
		}
	}
private:
	Cpu* m_Cpu;
	Gpu* m_Gpu;
	Memory* m_Memory;
};

void test01()
{
	//组装第1台电脑
	cout << "..................第1台................." << endl;
	Cpu* intelcpu = new IntelCpu;
	Gpu* intelgpu = new IntelGpu;		//IntelGpu是抽象类？
	Memory* intelmem = new IntelMemory;	//抽象类？

	PC* computer1 = new PC(intelcpu, intelgpu, intelmem);
	computer1->pcRun();
	delete computer1;

	//第2台
	cout << "..................第2台................." << endl;
	PC* computer2 = new PC(new LenovoCpu, new LenovoGpu, new LenovoMemory);
	computer2->pcRun();
	delete computer2;
	
}
int main()
{
	test01();

	system("pause");
	return 0;
}
```



# 5 文件操作

程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放

通过文件可以将数据持久化，C++中对文件操作需要包含头文件<fstream>



文件类型2种：

* 文件文件——文件以文本的ASCII码形式存储在计算机中
* 二进制文件——文件以文本的二进制形式存储在计算机中，用户一般不易直接读懂



操作文件的三大类：

1. fstream:读写操作
2. ifstream:读操作       input
3. ofstream:写操作     output



## 5.1 文本文件

### 5.1.1 写

写文件步骤：

1. 包含头文件

   #include<fstream>	

2. 创建流对象

   ofstream ofs;

3. 打开文件

   ofs.open("路径",打开方式);

4. 写数据

   ofs<<“写入的数据";

5. 关闭文件

   ofs.close();

文件打开方式：

| 打开方式    | 说明                       |
| ----------- | -------------------------- |
| ios::in     | 为读文件而打开文件         |
| ios::out    | 为写文件而打开文件         |
| ios::ate    | 初始位置：文件尾           |
| ios::app    | 追加方式写文件             |
| ios::trunc  | 如果文件存在，先删除再创建 |
| ios::binary | 二进制方式                 |

注意：文件打开方式可配合使用，利用|操作符，如：用二进制方式写文件 `ios::binary | ios::out`

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>


void test01()
{
	//1.头文件
	//2.流对象
	ofstream ofs;

	//3.打开方式
	ofs.open("test01.txt", ios::out);
	//4.写数据
	ofs << "姓名：张涛" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;
	ofs.close();

}
int main()
{
	test01();
	system("pause");
	return 0;
}
```



### 5.1.2 读

与写文件步骤类似，但读取方式比较多：

读文件步骤如下：

1. 包含头文件

   #include<fstream>	

2. 创建流对象

   ifstream ifs;

3. 打开文件，==并判断文件是否打开成功==

   ifs.open("路径",打开方式);

4. 读数据

   4种方式

5. 关闭文件

   ifs.close();

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>
#include<string>

void test01()
{
	//1.头文件
	//2.流对象
	ifstream ifs;

	//3.打开方式，并判断是否打开成功
	ifs.open("test01.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	//4.读数据
	//4种
	////第一种
	//char buf[1024] = { 0 };
	//while (ifs>>buf)
	//{
	//	cout << buf << endl;
	//}

	////第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	////第3种
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	//第4种
	char c;
	while ((c = ifs.get()) != EOF)		//endof file

	{
		cout << c;
	}
	
	//5.关闭文件
	ifs.close();

}
int main()
{
	test01();
	system("pause");
	return 0;
}
```

总结：

* 读文件用fstream/ifstream类
* 用is_open函数可判断文件是否打开成功
* close关闭文件



## 5.2 二进制文件

以二进制方式对文件进行读写操作，打开方式指定为`ios::binary`

### 5.2.1 写

二进制方式写文件，主要利用流对象调用成员函数write

函数原型：`ostream&write(const char* buffer,int len);`

参数解释：字符指针buffer指向内存中的一段存储空间，len是读写的字节数



```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>

class Person
{
public:
	char m_Name[64];
	int m_Age;

};

void test01()
{
	//2.创建流对象
	ofstream ofs("Person.txt", ios::out | ios::binary);

	//3.打开文件
	/*ofs.open("Person.txt", ios::out | ios::binary);*/
	
	//4.写数据
	Person p = { "张涛",18.1 };
	ofs.write((const char*)&p, sizeof(p));

	//5.关闭文件
	ofs.close();
}
int main()
{
	test01();

	system("pause");
	return 0;
}
```

总结：

* 二进制方式写文件，主要利用流对象调用成员函数write

### 5.2.2 读

二进制方式读文件，主要利用流对象调用成员函数read

函数原型：`istream&read(char* buffer,int len);`

参数解释：字符指针buffer指向内存中的一段存储空间，len是读写的字节数



```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>

class Person
{
public:
	char m_Name[64];
	int m_Age;

};

void test01()
{
	//2.创建流对象
	ifstream ifs("Person.txt", ios::out | ios::binary);

	//3.打开文件,判断是否打开成功！
	/*ifs.open("Person.txt", ios::out | ios::binary);*/
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	
	//4.读数据
	Person p;
	ifs.read((char*)&p, sizeof(p));

	cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;;

	//5.关闭文件
	ifs.close();
}
int main()
{
	test01();

	system("pause");
	return 0;
}
```

总结：

* 二进制方式读文件，主要利用流对象调用成员函数read





# <font color="blue"> 模板：</font>

<font color="pink">Pxx~Pxx</font>

```c++
#include<iostream>
using namespace std;

int main()
{
	

	system("pause");
	return 0;
}
```