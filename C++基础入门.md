---



---

# 1 C++初识

## 1.1 第1个C++程序

几个步骤

* 创建项目
* 创建文件
* 编写代码
* 运行程序

vs2019产品密钥

> Visual Studio 2019 Professional
> NYWVH-HT4XC-R2WYW-9Y3CM-X4V3Y
>
> Visual Studio 2019 Enterprise
> BF8Y8-GN2QH-T84XB-QVY3B-RC4DF
>
> 转载：https://www.cnblogs.com/yechangzhong-826217795/p/11669699.html

### 1.1.1 创建项目

​	软件IDE：vs2019

* 创建新项目——空项目——项目名称——项目路径

![](assets\Dingtalk_20221231160107.jpg)

![](assets\Dingtalk_20221231160503.jpg)

### 1.1.2 创建文件

右击（源文件）——添加——新建项——文件名（01 C++书写HelloWorld）——添加

![](assets\Dingtalk_20221231161440.jpg)

### 1.1.3 编写代码


```c++
#include<iostream>
using namespace std;

int main() {

	cout << "hello world, hello Cpp" << endl;

	system("pause");

	return 0;
}
```

### 1.1.4 运行程序

<img src="assets\Dingtalk_20221231163229.jpg"  />

## 1.2 注释

说明、解释，提升代码可读性

两种格式：

1.单行注释	`//`

2.多行注释	`/**/`

```c++
#include<iostream>
using namespace std;

/*
	main是1个程序的入口
	每个程序都必须有这么个函数
	有且仅有一个
*/
int main2() {

	cout << "hello cpp，注释" << endl;s

	system("pause");

	return 0;
}
```

## 1.3 变量

作用：给指定的内存空间起名，方便操作这段内存

说法：`数据类型 变量名=初始值`

示例：

```c++
#include<iostream>
using namespace std;

int main() {

	/*
		变量的定义
		数据类型 变量名	=	初始值
	*/
	int a = 10;

	cout << "a="<<a << endl;

	system("pause");

	return 0;
}
```

✔源文件中只允许1个main函数，前面的可以顺次命名为main1...mainN，程序会找main入口进入

## 1.4 常量

```c++
#include<iostream>
using namespace std;
#define DAY 7
/*
	常量
	1.#define宏常量
	2.const修饰的变量
*/

int main() {

	cout << "一周共有" << DAY << "天" << endl;

	const int month = 12;

	cout << "一年共有" <<month<<"个月" << endl;

	system("pause");

	return 0;
}
```

## 1.5 关键字

作用：C++中预留的单词（标识符）

C++关键字：

| asm        | do           | if               | return      | typedef  |
| ---------- | ------------ | ---------------- | ----------- | -------- |
| auto       | double       | inline           | short       | typeid   |
| bool       | dynamic_cast | int              | signed      | typename |
| break      | else         | long             | sizeof      | union    |
| case       | enum         | mutable          | static      | unsigned |
| catch      | explicit     | namespace        | static_cast | using    |
| char       | export       | new              | struct      | virtual  |
| class      | extern       | operator         | switch      | void     |
| const      | false        | private          | template    | volatile |
| const_cast | float        | protected        | this        | wchar_t  |
| continue   | for          | public           | throw       | while    |
| default    | friend       | register         | true        |          |
| delete     | goto         | reinterpret_cast | try         |          |

## 1.6 变量、常量命名规则

* 不能是关键字
* 只能由字母、数字、下划线组成
* 字母、下划线开头
* 字母区分大小写

`注：见名知意`

# 2 数据类型

创建一个变量或常量时，必须指定数据类型，以分配内存

## 2.1 整型

C++中的几种整型

| 类型      | 空间                                    | 取值         |
| --------- | --------------------------------------- | ------------ |
| short     | 2字节                                   | -2^15~2^15-1 |
| int       | 4                                       | -2^31~2^31-1 |
| long      | win 4；32位linux 4字节、64位linux 8字节 | -2^31~2^31-1 |
| long long | 8                                       | -2^63~2^63-1 |

## 2.2 sizeof关键字

```c++
#include<iostream>
using namespace std;

int main() {

	/*
		sizeof
		语法：sizeof(类型/变量)
	*/

	cout << "short占用内存空间：" << sizeof(short) << endl;
	cout << "int占用内存空间：" << sizeof(int) << endl;
	cout << "long占用内存空间：" << sizeof(long) << endl;
	cout << "long long占用内存空间：" << sizeof(long long) << endl;

	system("pause");

	return 0;
}
```

`注：2 4 4 8`

## 2.3 实型（浮点型）

两种类型：

1.单精度float

2.双精度double

| 类型   | 空间 | 有效数字范围 |
| ------ | ---- | ------------ |
| float  | 4    | 7位          |
| double | 8    | 15~16位      |

```c++
#include<iostream>
using namespace std;

int main() {

	/*
		单精度	float
		双精度	double
		默认情况，显示6位有效数字
	*/

	float f1 = 3.1415926f;
	double d1 = 3.1415926;

	cout << "f1=" << f1 << endl;
	cout << "d1=" << d1 << endl;

	cout << "float占用" << sizeof(float) << "字节"<<endl;		//4字节
	cout << "double占用" << sizeof(double) << "字节" << endl;	//8字节

	//科学计数法
	float f2 = 9e-2;
	cout << "f2=" << f2 << endl;

	system("pause");

	return 0;
}
```

`注：显示6位有效数字；科学计数法`

## 2.4 字符型(ASCII码表)

语法：`char ch='a'`

* C/C++中字符型变量占1个字节

* 将对应的ASCII码存入

  ```c++
  #include<iostream>
  using namespace std;
  
  int main() {
  
  	//1.字符型变量
  	char ch = 'a';
  	cout << ch << endl;
  
  	cout << "char占用" << sizeof(char) << "字节" << endl;		
  
  	//ascii码
  	//a-97
  	//A-65
  	cout << (int)'a' << endl;
  	cout << (int)'A' << endl;
  
  	system("pause");
  
  	return 0;
  }
  ```

  `看ascii码值，强转为int`

  ![img](https://www.runoob.com/wp-content/uploads/2022/03/ascii-1-1.png)

## 2.5 转义字符

常用的：`\n \\ \t`

```c++
#include<iostream>
using namespace std;

int main() {

	//换行符	\n
	cout << "Hello World\n";	//c语言写法

	//反斜杠 \\

	cout << "\\" << endl;	//c语言写法

	// 水平制表符 \t 8个空格，对齐
	cout << "\tHello HAOMO.AI" << endl;	
	cout << "\tHello GWM" << endl;
	cout << "aa\tHello GWM" << endl;

	system("pause");

	return 0;
}
```

## 2.6 字符串型

* C	 ：`char 变量名[]="字符串"`
* C++ ：`string 变量名="字符串"`

```c++
#include<iostream>
using namespace std;
#include<string>

int main() {

	//1.C风格
	//中括号、双引号
	char str[] = "Hello World!";
	cout << str << endl;

	//2.C++风格
	//包含头文件 #include<string>
	string str1 = "Hello World!";
	cout << str1 << endl;

	system("pause");

	return 0;
}
```

## 2.7 布尔类型

bool类型，两个值：true/false，占1个字节

```c++
#include<iostream>
using namespace std;

int main() {

	//bool类型定义
	bool flag = true;
	cout << flag << endl;

	flag = false;
	cout << flag << endl;

	cout << "size of bool = " << sizeof(bool) << endl;

	system("pause");

	return 0;
}
```

## 2.8 数据输入

`语法：cin>>变量`

```c++
#include<iostream>
using namespace std;

int main() {

	//1.整型
	int a = 0;
	cout << "请输入整型值：";
	cin >> a;
	cout << "整型值为：" << a << endl;

	//2.浮点型
	float f1 = 3.14f;
	cout << "请输入小数：";
	cin >> f1;
	cout << "小数为：" << f1 << endl;

	//3.字符
	char ch = 'b';
	cout << "请输入字符：";
	cin >> ch;
	cout << "字符为：" << ch << endl;

	//4.字符串
	string str = "HAOMO.AI";
	cout << "请输入字符串：";
	cin >> str;
	cout << "字符串为：" << str << endl;

	//5.布尔类型
	bool flag = true;
	cout << "请赋值flag：";
	cin >> flag;		//非零都代表真
	cout << "flag为：" << flag << endl;

	system("pause");

	return 0;
}
```

`布尔类型：非0都为真`

# 3 运算符

| 类型       | 作用                     |
| ---------- | ------------------------ |
| 算术运算符 | 四则运算                 |
| 赋值运算符 | 将表达式值赋给变量       |
| 比较运算符 | 表达式的比较，返回真、假 |
| 逻辑运算符 | 根据表达式值返回真、假   |

## 3.1 算术运算符

| 运算符 | 术语         | 示例           | 结果    |
| ------ | ------------ | -------------- | ------- |
| +      | 正号         | +3             | 3       |
| -      | 负号         | -3             | -3      |
| +      | 加           | 10+5           | 15      |
| -      | 减           | 10-5           | 5       |
| *      | 乘           | 10*5           | 50      |
| /      | 除           | 10/5           | 2       |
| %      | 取模（取余） | 10%3           | 1       |
| ++     | 前置递增     | a=2;b=**++**a; | a=3;b=3 |
| ++     | 后置递增     | a=2;b=**a**++; | a=3;b=2 |
| --     | 前置递减     | a=2;b=**--**a; | a=1;b=1 |
| --     | 后置递减     | a=2;b=**a--**; | a=1;b=2 |

`只有整型变量，可以取模运算`

```c++
#include<iostream>
using namespace std;

int main() {

	//除
	int a = 10;
	int b = 3;
	cout << a / b << endl;//两个整数相除，结果仍为整数	——失真

	cout << a % b << endl;
	system("pause");

	return 0;
}
```

## 3.2 赋值运算

| 运算符 | 术语 | 示例      | 结果 |
| :----- | :--- | :-------- | :--- |
| =      | 赋值 | a=2       | a=2  |
| +=     | 加等 | a=0;a+=2  | a=2  |
| -=     | 减等 | a=5;a-=3; | a=2  |
| *=     | 乘等 | a=2;a*=2  | a=4  |
| /=     | 除等 | a=4;a/=2  | a=2  |
| %=     | 模等 | a=3;a%2   | a=1  |

## 3.3 比较运算符

| 运算符 | 术语     | 示例 | 结果 |
| ------ | -------- | ---- | ---- |
| ==     | 相等     | 4==3 | 0    |
| !=     | 不等     | 4!=3 | 1    |
| <      | 小于     |      |      |
| >      | 大于     |      |      |
| <=     | 小于等于 |      |      |
| >=     | 大于等于 |      |      |

## 3.4 逻辑运算符

| 运算符 | 术语 | 示例   | 结果                            |
| ------ | ---- | ------ | ------------------------------- |
| ！     | 非   | !a     |                                 |
| &&     | 与   | a&&b   | 都为真时，为真；否则为假        |
| \|\|   | 或   | a\|\|b | 1个为真，则为真；都为假，才为假 |

`||：同假为假，其余为真`

# 4 流程结构

C/C++支持基本的3种程序运行结构，顺序、选择、循环

* 顺序结构：程序顺序执行，不发生跳转
* 选择结构：按条件是否满足，有条件执行相应功能
* 循环结构：按条件是否满足，循环多次执行某段代码

## 4.1 选择结构

### 4.1.1 if语句

* 单行if
* 多行if
* 多条件if

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main() {

	//单行if
	//输入分数，600及以上985，否则回家养猪吧

	float score = 600.5f;
	cout << "请输入分数：";
	cin >> score;

	if (score >= 600)
	{
		cout << "恭喜考上985！" << endl;
	}
	else
	{
		cout << "回家养猪吧！" << endl;
	}

	system("pause");

	return 0;
}
```

### 4.1.2 三目运算符

* 语法：`表达式1？表达式2：表达式3`
* 三目运算符，返回变量；
* 返回的变量可以继续赋值

`c=(a>b?a:b)`

`(a>b?a:b)=100`

```c++
#include<iostream>
using namespace std;

int main() {

	//max

	int num1 = 100;
	int num2 = 90;

	cout << "最大值为："<<(num1>num2 ? num1:num2)<<endl;

	//再赋值
	cout << "最大值为：" << ((num1 > num2 ? num1 : num2)=1000) << endl;

	system("pause");

	return 0;
}
```

### 4.1.3 swith语句

```c++
#include<iostream>
using namespace std;

int main() {

	//给电影打分
	//9-10	经典
	//8		优秀
	//6-7	一般
	//其它	烂片
	cout << "请打分：";
	int score = 0;
	cin >> score;

	if (score <= 10 && score >= 1)
	{
		switch (score)
		{
		case 10:
		case 9:
			cout << "经典" << endl;
			break;
		case 8:
			cout << "优秀" << endl;
			break;
		case 7:
		case 6:
			cout << "一般" << endl;
			break;
		default:
			cout << "烂片" << endl;
			break;
		}
	}
	else
	{
		cout << "打分无效！" << endl;
	}

	system("pause");

	return 0;
}
```

tip1:switch语句中，表达式类型只能是整型或字符型

tip2:case中要有break，否则会一直向下执行

总结：与if语句比，switch结构清晰，执行效率高，但不能判断区间

## 4.2 循环结构

### 4.2.1 while循环

语法：`while(条件语句){循环语句}`

```c++
#include<iostream>
using namespace std;

int main() {

	int num = 0;
	while (num < 10)
	{
		cout << num << endl;
		num++;
	}

	system("pause");

	return 0;
}
```

* 猜数字
  * 随机生成1-100间数字
  * 提示玩家过大或过小，猜对恭喜玩家，退出

```c++
#include<iostream>
using namespace std;
#include<ctime>

int main() {

	//随机种子
	srand((unsigned int)time(NULL));
	//伪随机数
	int num = rand() % 100 + 1;//0-99	+1,随机数
	cout << num << endl;

	int guess = 0;

	while (1)
	{
		cout << "请猜数字";
		cin >> guess;

		if (guess < num)
		{
			cout << "小了" << endl;
		}
		else if(guess > num)
		{
			cout << "大了" << endl;
		}
		else
		{
			cout << "对了" << endl;
			break;
		}
	}

	system("pause");

	return 0;
}
```

### 4.2.2 do...while循环

语法：`do{循环语句}while(循环条件);`

注：与while区别，先执行一次

```c++
#include<iostream>
using namespace std;

int main() {

	int num = 0;
	do
	{
		cout << num << endl;
		num++;
	} while (num<10);
	
	system("pause");

	return 0;
}
```

* 水仙花数
  * 指一个3位数，每个位上的数字的3次幂之和等于它本身，如1^3+5^3+3^3=153
  * 用do...while，求出所有3位数中的水仙花数

```c++
#include<iostream>
using namespace std;
#include<cmath>

int main() {

	//水仙花数
	//153=1^3+5^3+3^3

	int num = 152;
	do
	{
		int temp = num;
		if (pow(temp%10,3) + pow(temp/10 % 10,3) + pow(temp / 100,3) == num)
		{
			cout << num << endl;
		}

		num++;
	} while (num < 1000);

	system("pause");

	return 0;
}
```

`#include<cmath>`

`pow(x,y)`

### 4.2.3 for循环

语法：`for(起始表达式;条件表达式;末尾循环体){循环语句}`

```c++
#include<iostream>
using namespace std;

int main() {

	for (int i = 0; i < 10; i++) 
	{
		cout << i << endl;
	}

	system("pause");

	return 0;
}
```

* 敲桌子
  * 1-100，数字个位、十位含有7，或该数字为7的倍数，打印敲桌子，其余直接输出

```c++
#include<iostream>
using namespace std;

int main() {

	for (int i = 1; i <=100; i++) 
	{
		if (i % 10 == 7 || i / 10 % 10 == 7 || i % 7 == 0)
		{
			cout << "敲桌子" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}

	system("pause");

	return 0;
}
```

### 4.2.4 嵌套循环

```c++
#include<iostream>
using namespace std;

int main() {

	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "* ";
		}
		cout << endl;
	}


	system("pause");

	return 0;
}
```

* 乘法表

```c++
#include<iostream>
using namespace std;

int main() {

	for (int j = 1; j < 10; j++)
	{
		for (int i = 1; i <= j; i++)
		{
			cout << i << "x" << j << "=" << i * j<<'\t';
		}
		cout << endl;
	}

	system("pause");

	return 0;
}
```

## 4.3 跳转语句

### 4.3.1 break语句

* switch语句中
* 循环语句中
* 嵌套语句中

### 4.3.2 continue语句

跳过本次中尚未执行的语句，继续下次循环

### 4.3.3 goto语句

```c++
#include<iostream>
using namespace std;

int main() {

	cout << "1.xxxx" << endl;
	goto FLAG;

	cout << "2.xxxx" << endl;
	cout << "3.xxxx" << endl;
	cout << "4.xxxx" << endl;

	FLAG:
	cout << "5.xxxx" << endl;

	system("pause");

	return 0;
}
```

# 5 数组

## 5.1 概述

数组，一个集合，存放了相同类型的数据元素

特点1：数组中的每个元素都是相同的数据类型

特点2：连续的内存位置组成

## 5.2 一维数组

### 5.2.1 定义

三种定义方式：

1.`数据类型 数组名[数组长度]`

2.`数据类型 数组名[数组长度]={值1,值2,...}`

3.`数据类型 数组名[]={值1,值2,...}`

```c++
#include<iostream>
using namespace std;

int main() {

	/*
		1.`数据类型 数组名[数组长度]`

		2.`数据类型 数组名[数组长度]={值1,值2,...}`

		3.`数据类型 数组名[]={值1,值2,...}`
	*/

	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = 10 * (i+1);
		cout << arr[i] << " ";
	}
	cout << endl;

	int arr2[5] = {1,3,5,7};	//未给值，填充0
	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;


	system("pause");

	return 0;
}
```

### 5.2.2 数组名

1. 统计数组在内存中的长度
2. 数组在内存中的首地址

**示例：**

```c++
#include<iostream>
using namespace std;

int main() {

	int arr[5] = {2,4,6,8,10};

	//内存大小
	cout << "数组占用的内存空间" << sizeof(arr) << endl;

	//数组首地址
	cout <<arr<< endl;
	//首元素地址
	cout << &arr[0] << endl;
	//第二个元素地址
	cout << &arr[1] << endl;	//连续的线性空间
	//
	cout << *(arr) << endl;		//指针

	system("pause");

	return 0;
}
```

**练习1：**5只小猪称体重

数组中记录了五只小猪体重，如：int arr[5]={100,200,300,150,250},找出并打印最重的值。

```c++
#include<iostream>
using namespace std;

int main() {

	/*
		练习1：**5只小猪称体重**
		数组中记录了五只小猪体重，如：int arr[5]={100,200,300,150,250},找出并打印最重的值。
	*/
	int arr[5] = { 100,200,300,150,250 };

	int max = 0;
	for (int i = 0; i < 5; i++) {

		max = (arr[i] > max ? arr[i] : max);
	}
	cout << max << endl;

	system("pause");

	return 0;
}
```

* for循环遍历
* 三目运算符

**练习2：**数组元素逆序

声明一个5元素数组，将元素逆序，如1，2，3，4，5，逆序后为5，4，3，2，1。

```c++
#include<iostream>
using namespace std;

int main() {

	/*
		声明一个5元素数组，将元素逆序，如1，2，3，4，5，逆序后为5，4，3，2，1。
	*/
	int arr[] = { 100,200,300,150,250,1000};

	int len = sizeof(arr)/sizeof(arr[0]);
	int left = 0;
	int right = len-1;
	int temp = 0;
	for (left = 0; left<right;left++,right--) 
	{
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}
	for (int i = 0; i < len; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;

	system("pause");

	return 0;
}
```

* 下标访问，left/right  sizeof(arr)/sizeof(arr[0])元素个数
* for循环遍历，也可以用`while(left<right)`

### 5.2.3 冒泡排序

常用的排序算法，升序排列，如{4,2,8,0,5,7,1,3,9}

```c++
#include<iostream>
using namespace std;

int main() {

	/*
		常用的排序算法，升序排列，如{4,2,8,0,5,7,1,3,9}
	*/
	//int arr[] = { 4,2,8,0,5,7,1,3,9 };
	int arr[] = { 9,8,7,5,4,3,2,1,0 };
	//int arr[] = { 1,2,3,4,5,6,7,9,8 };

	cout << "排序前：";
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	int lunshu = 0;
	int cishu = 0;

	for (int j = 0; j < len-1; j++)	//外层轮数，元素个数-1
	{
		bool flag = 0;					//交换标志位

		for (int i = 0; i < len-1-j; i++)	//内层次数，元素个数-1-轮数
		{
			int tmp = 0;
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = 1;				//交换中
				cishu++;
			}
		}

		if (flag == 0)
		{
			break;
		}
		lunshu = j + 1;

	}
	cout << "交换了" << lunshu << "轮" << endl;
	cout << "交换了" << cishu << "次" << endl;

	cout << "升序后：";				//冒泡排序
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");

	return 0;
}
```

* 嵌套for循环，外层轮数、内层次数
* 设flag，若第n轮中未排，退出
* **交换了x轮、x次**

## 5.3 二维数组

### 5.3.1 定义方式

```markdown
数据类型 数组名[行数][列数];
数据类型 数组名[行数][列数]={{a,b},{c,d}};
数据类型 数组名[行数][列数]={a,b,c,d};
数据类型 数组名[][列数]={a,b,c,d};
```

示例：第2种方式

```c++
#include<iostream>
using namespace std;

int main() {

	/*
		数据类型 数组名[行数][列数];
		数据类型 数组名[行数][列数]={{a,b},{c,d}};
		数据类型 数组名[行数][列数]={a,b,c,d};
		数据类型 数组名[][列数]={a,b,c,d};
	*/
	int arr[2][3] =
	{
		{1,3,5},
		{2,4,6}
	};

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");

	return 0;
}
```

### 5.3.2 数组名操作

* 查看占用的内存空间大小
* 二维数组地址

### 5.3.3 应用案例

考试成绩统计：分别输出3名同学的总成绩

|      | 语文 | 数学 | 英语 |
| ---- | ---- | ---- | ---- |
| 张三 | 100  | 100  | 100  |
| 李四 | 90   | 50   | 100  |
| 王五 | 60   | 70   | 80   |

```c++
#include<iostream>
using namespace std;

int main() {

	/*
		考试成绩统计：分别输出3名同学的总成绩
	*/
	int arr[][3] =
	{
		{100,100,100},
		{90,50,100},
		{60,70,80}
	};
	
	string names[] = { "张三","李四","王五" };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	//总成绩
	int sum[3] = { 0,0,0 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum[i]+=arr[i][j];
		}
		cout << names[i]<<"的总分为："<<sum[i] << endl;
	}

	system("pause");

	return 0;
}
```

# 6 函数

## 6.1 概述

封装代码，减少重复代码

## 6.2 函数定义

`返回值类型 函数名（参数）{函数体语句;return 表达式}`

```c++
返回值类型 函数名（参数列表）
{
    函数体语句;
    return 表达式
}
```

## 6.3 函数调用

```c++
#include<iostream>
using namespace std;

//形参
int add(int num1, int num2)
{
	return num1 + num2;
}
int main1()
{
	int a = 5;
	int b = 6;
	//实参
	cout << add(a, b) << endl;

	system("pause");	//按任意键继续
	return 0;
}
```

## 6.4 值传递

```c++
#include<iostream>
using namespace std;

//形参
void swap(int num1, int num2)
{
	cout << "交换前:";
	cout << num1 << " " << num2 << endl;

	int tmp = num1;
	num1 = num2;
	num2 = tmp;
	cout << "交换后:";
	cout << num1 << " " << num2 << endl;
}
int main()
{
	int a = 5;
	int b = 6;
	swap(a, b);

	system("pause");	//按任意键继续
	return 0;
}
```

* 不影响实参

## 6.5 函数的常见样式

* 输入参数（有、无）
* 返回参数（有、无）

## 6.6 函数声明

```c++
#include<iostream>
using namespace std;

////声明
//int max(int, int);

int main()
{
	int a = 5;
	int b = 6;
	cout << max(a, b) << endl;

	system("pause");	//按任意键继续
	return 0;
}

//定义
int max(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}
```

**vs2019不声明也行？**

## 6.7 分文件编写

```c++
#include<iostream>
using namespace std;

////声明
//void swap(int* p1, int* p2);

int main()
{
	int a = 5;
	int b = 6;
	swap(&a, &b);
	cout << a<<" "<<b << endl;

	system("pause");	//按任意键继续
	return 0;
}

//定义
void swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
```

* .h头文件，写函数声明
* .cpp源文件，写函数定义
* 传址（指针），实参会变

```c++
#pragma once
#include<iostream>
using namespace std;
//头文件
void swap(int* p1, int* p2);
```

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include "swap.h"

//定义
void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
```

```c++
#include"swap.h"

int main()
{
	int a = 5;
	int b = 6;
	swap(&a, &b);
	cout << a << " " << b << endl;

	system("pause");	//按任意键继续
	return 0;
}
```

# 7 指针

## 7.1 基本概念

作用：通过指针间接访问内存，指针就是一个地址

## 7.2 定义和使用

```c++
#include<iostream>
using namespace std;

int main()
{
	int a = 100;
	int* p = &a;
	cout << "a的地址：" << &a << endl;
	cout << "p指针为：" << p << endl;

	system("pause");

	return 0;
}
```

## 7.3 所占的内存空间

* 32位系统：4字节
* 64位系统：8字节

```c++
#include<iostream>
using namespace std;

int main()
{
	int a = 100;
	int* p = &a;

	cout << "size of (int *)=\t" << sizeof(int *) << endl;
	cout << "size of (double *)=\t" << sizeof(double*) << endl;

	system("pause");

	return 0;
}
```

## 7.4 空指针和野指针

* 空指针：内存中编号为0的空间
* 用途：初始化指针
* 注意：指向的空间不可访问

**空指针**，访问报错！

```c++
#include<iostream>
using namespace std;

int main()
{
	//
	int* p = NULL;

	//空指针不可访问
	//内存编号0~255为系统占用内存，不允许访问
	//*p=100;	//非法

	system("pause");

	return 0;
}
```

**野指针**，访问报错！

```
#include<iostream>
using namespace std;

int main()
{
	//
	int* p = (int *)0x110;

	//访问报错
	cout << *p << endl;

	system("pause");

	return 0;
}
```

## 7.5 const修饰指针

三种情况：

1. const修饰指针——常量指针  const int * p——指向内容不可改
2. const修饰常量——指针常量  int * const p——指针指向不可改
3. const修饰指针、常量——const int * const p

```c++
#include<iostream>
using namespace std;

int main()
{
	/*
		1. const修饰指针——常量指针  const int * p——指向内容不可改
		2. const修饰常量——指针常量  int * const p——指针指向不可改
		3. const修饰指针、常量——const int * const p
	*/
	//常量指针
	int a = 100;
	const int* p = &a;
	//*p=		//常量指针，常量哦，不可改——不能通过*p赋值
	a = 1000;
	cout << *p << endl;

	//
	int a2 = 100;
	int* const p2 = &a2;
	//p2=		//指针常量，不能改指向

	system("pause");

	return 0;
}
```

* **迷糊**

## 7.6 指针和数组

* 指针访问数组中元素

```c++
#include<iostream>
using namespace std;

int main()
{
	/*
		指针访问数组中元素
	*/
	int arr[] = { 1,3,5,7,9 };

	//指针访问
	int* p = arr;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << *p << " ";
		p++;
	}
	cout << endl;

	system("pause");

	return 0;
}
```

* for循环遍历，指针++

## 7.7 指针和函数

**作用：**传址，会改实参值

```c++
#include<iostream>
using namespace std;

void swap1(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void swap2(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
int main()
{
	//传值,实参未变
	int a = 10;
	int b = 20;
	swap1(a, b);
	cout << a << " " << b << endl;
	
	//传址，实参变
	int x = 1;
	int y = 9;
	swap2(&x, &y);	//传址
	cout << x << " " << y << endl;

	system("pause");

	return 0;
}
```

* 传值
* 传址

## 7.8 指针、数组、函数

**案例：封装一个函数，利用冒泡排序，实现对整形数组的升序排列，如int arr[]={4,3,6,9,1,2,10,8,7,5}**

* 函数、数组、指针
* 冒泡排序、flag

```c++
#include<iostream>
using namespace std;

/*
	案例：封装一个函数，利用冒泡排序，实现对整形数组的升序排列，如int arr[]={4,3,6,9,1,2,10,8,7,5}

	* 函数、数组、指针
	* 冒泡排序、flag
*/
void bubblesort(int*p,int len)
{
	//轮数、次数
	int lunshu = 0;
	int cishu = 0;

	for (int i = 0; i < len-1; i++)					//外层，第几轮，元素个数-1
	{
		//flag，一轮中已经不再升序，则考虑跳出循环
		bool flag = 0;

		for (int j = 0; j < len -1- i; j++)			//内层，第几次
		{
			if (p[j]>p[j+1])
			{
				//int tmp = p[j];
				//p[j] = p[j + 1];
				//p[j + 1] = tmp;
				int tmp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = tmp;

				flag = 1;				//有继续排序
				cishu++;				//排序1次，自+
			}
		}
		if (flag == 0)
		{
			break;						//1轮中顺序已ok，跳出循环，结束
		}
		lunshu = i + 1;
	}
	cout << "合计排序" << lunshu << "轮，" << cishu << "次" << endl;
}
void myprint(int*p,int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << *p << " ";
		p++;
	}
	cout << endl;
}
int main()
{
	//int arr[] = { 4,3,6,9,1,2,10,8,7,5 };
	int arr[] = { 1,2,3,4,5,6,7,8,10,9 };

	//指针遍历，打印
	cout << "排序前：";
	int len = sizeof(arr) / sizeof(arr[0]);//元素个数
	myprint(arr, len);

	//冒泡排序
	bubblesort(arr,len);

	//指针遍历，打印
	cout << "排序后：";
	myprint(arr, len);
	system("pause");

	return 0;
}
```

# 8 结构体

## 8.1 基本概念

自定义数据类型，允许用户存储不同的数据类型

## 8.2 定义与使用

语法：`struct 名称{成员列表}`

**示例：**

vs2019不用引头文件`#include<string>`?

```c++
#include<iostream>
using namespace std;

//自定义数据类型，类型集合
struct Student
{
	string name;
	int age;
	int score;
}s3;		//定义时，顺便创建！
int main()
{
	//1.struct Student s1;
	Student s1;				//创建变量时，struct可省略
	s1.name = "张涛";
	s1.age = 16;
	s1.score = 100;
	cout << "姓名：" << s1.name << "	年龄：" << s1.age << "	分数：" << s1.score << endl;	//vs2019不用引头文件？

	//2.struct Student s2={...};
	Student s2 = { "李四",20,99 };
	cout << "姓名：" << s2.name << "	年龄：" << s2.age << "	分数：" << s2.score << endl;	//vs2019不用引头文件？

	//3.定义时，顺便创建
	s3= { "王五",20,99 };
	cout << "姓名：" << s3.name << "	年龄：" << s3.age << "	分数：" << s3.score << endl;	//vs2019不用引头文件？

	system("pause");
	return 0;
}
```

* 创建变量时，struct关键字可省略，定义时不可
* 用“."访问成员

## 8.3 数组

作用：将自定义结构体放入数组中，方便维护

语法：`struct 结构体名 数组名[元素个数]={{},{},...{}}`

## 8.4 指针

通过指针访问结构体成员，利用操作符`->`访问结构体属性

```c++
#include<iostream>
using namespace std;

//定义
struct Student
{
	string name;
	int age;
	int score;
};

int main()
{


	//struct Student s2={...};
	//struct 结构体名 数组名[元素个数]={{},{},...{}}

	Student stuArr[3] =
	{
		{"三",15,99},
		{"四",16,88},
		{"五",18,100}
	};
	cout << "姓名：" << stuArr[0].name << "	年龄：" << stuArr[0].age << "	分数：" << stuArr[0].score << endl;	//vs2019不用引头文件？

	//遍历，指针
	Student* p= stuArr;
	for (int i = 0; i < 3; i++)
	{
		cout << "姓名：" << p->name << "	年龄：" << p->age << "	分数：" << p->score << endl;
		p++;
	}

	system("pause");
	return 0;
}
```

## 8.5 嵌套

作用：结构体成员可以是另一个结构体

举例：老师辅导学生，老师结构体中记录学生的结构体

```c++
#include<iostream>
using namespace std;

//学生
struct Student
{
	string name;
	int age;
	int score;
};

//老师
struct Teacher
{
	int id;//编号
	string name;//
	int age;
	Student stu;	//struct关键字可省
};
int main()
{

	Teacher t1 =
	{
		10108,
		"老王",
		30,
		{"涛",15,99}
	};

	//遍历，指针
	Teacher* p = &t1;
	cout << "id：" <<p->id  <<"	名字："<<p->name<< "	年龄：" << p->age << "	学生：" <<p->stu.name << endl;

	system("pause");
	return 0;
}
```

## 8.6 结构体传参

* 传值

* 传址——主函数中会变

```c++
#include<iostream>
using namespace std;

struct Student
{
	string name;
	int age;
	int score;
};

//传值
void my_print1(Student s)
{
	cout << "姓名：" << s.name << "	年龄：" << s.age << "	分数：" << s.score << endl;
}

//传址
void my_print2(Student* p)
{
	cout << "姓名：" << p->name<< "	年龄：" << p->age << "	分数：" << p->score << endl;

}

int main()
{
	Student s1 = { "涛",18,99 };

	//传值
	my_print1(s1);

	//传址
	my_print2(&s1);

	system("pause");
	return 0;
}
```

## 8.7 const使用

**作用：**防止误操作

* **const 修饰后，不可赋值**
* **形参用指针，可减少内存空间，没有新的副本**

```c++
#include<iostream>
using namespace std;

struct Student
{
	string name;
	int age;
	int score;
};

//传址
void my_print2(const Student* p)
{
	//p->age = 150;				//const修饰，不可赋值，防止误操作
	cout << "姓名：" << p->name << "	年龄：" << p->age << "	分数：" << p->score << endl;

}

int main()
{
	Student s1 = { "涛",18,99 };

	//传址
	my_print2(&s1);

	system("pause");
	return 0;
}
```

## 8.8 案例

### 8.8.1 案例1

描述：毕设项目，3个老师，每个老师带5名学生

* 老师结构体：老师姓名、存5名学生的数组
* 学生结构体：学生姓名、分数
* 创建结构体数组放3名老师，通过**函数**给老师及所带的学生赋值
* **打印**出老师、学生数据

| TeacherA |          |      |       |
| -------- | -------- | ---- | ----- |
|          | StudentA | name | score |
| TeacherB |          |      |       |
|          | StudentB | name | score |

* 执行完程序，敲任意键，程序崩了，？`引发了异常: 读取访问权限冲突。_Pnext 是 0x5F746E69。`
* 跟第4个 ==04 结构体嵌套.cpp== 中的结构体冲突

![](E:\09_sd\vs2019\2023_01_Cpp_Class\assets\屏幕截图 2023-01-02 181256.png)

* 代码：

```c++
#include<iostream>
using namespace std;

//学生定义
struct Student
{
	string sName;
	int score;
};

//老师定义
struct Teacher
{
	string tName;
	Student sArray[5];
};


//赋值，传址
void SetInfo(Teacher tArray[], int len)
{
	string nameseed = "ABCDEFG";	//种子
	for (int i = 0; i < len; i++)
	{
		tArray[i].tName = "Teacher_";
		tArray[i].tName += nameseed[i];
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].sName = "Student_";
			tArray[i].sArray[j].sName += nameseed[j];

			int rand_score = rand() % 41 + 60;//0-40 60-100
			tArray[i].sArray[j].score = rand_score;
		}
	}
}

//打印
void MyPrint(Teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << tArray[i].tName << endl;
		for (int j = 0; j < 5; j++)
		{
			cout <<"\t" << tArray[i].sArray[j].sName << "\t" <<tArray[i].sArray[j].score << endl;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));	//基于时间的种子
	//老师结构体数组
	Teacher tArray[3];

	//赋值
	int len = sizeof(tArray) / sizeof(tArray[0]);//元素个数	3个老师打团
	SetInfo(tArray, len);		//

	//打印
	MyPrint(tArray, len);

	system("pause");
	return 0;
}
```

### 8.8.2 案例2——（冒泡排序）按年龄升序排列结构体数组

描述：结构体数组排序

```
	{
		{"刘备", 23, "男"},
		{"关羽", 22, "男"},
		{"张飞", 20, "男"},
		{"赵云", 21, "男"},
		{"貂蝉", 19, "女"}
	};
```

代码1——基础版：

* 结构体，按年龄排序——==指针==、函数、结构体、==冒泡排序==

```c++
#include<iostream>
using namespace std;

struct Hero
{
	string name;
	int age;
	string sex;
};

//bubblesort
void bubblesort_by_age(Hero h[], int len)
{
	for (int i = 0; i < len - 1; i++)		//外层，几轮，元素-1
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (h[j].age > h[j + 1].age)	//前大，则后移动
			{
				Hero tmp = h[j];			//个人信息整体移动
				h[j]= h[j + 1];
				h[j + 1] = tmp;
			}
		}
	}
}

void myprint(Hero h[], int len)
{
	for (int i = 0; i < len; i++,h++)
	{
		cout << "\t" << h->name << " " << h->age << " " << h->sex << endl;
	}
}
int main()
{
	Hero h[]=
	{
		{"刘备", 23, "男"},
		{"关羽", 22, "男"},
		{"张飞", 20, "男"},
		{"赵云", 21, "男"},
		{"貂蝉", 19, "女"}
	};

	int len = sizeof(h) / sizeof(h[0]);

	//排序前
	cout << "排序前：" << endl;
	myprint(h, len);

	//冒泡排序，按年龄升序排列
	bubblesort_by_age(h, len);

	//打印排序后结果
	cout << "排序前：" << endl;
	myprint(h, len);

	system("pause");

	return 0;
}
```
