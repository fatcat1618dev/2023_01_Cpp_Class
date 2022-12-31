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