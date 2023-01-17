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