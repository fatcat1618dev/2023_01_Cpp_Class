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

<font color="pink">P106~P111</font>

## 4.3 C++对象模型和this指针

<font color="pink">P112~P117</font>

## 4.4 友元

<font color="pink">P118~P120</font>

## 4.5 运算符重载

<font color="pink">P121~P126</font>

## 4.6 继承

<font color="pink">P127~P134</font>

## 4.7 多态

<font color="pink">P135~P142</font>







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