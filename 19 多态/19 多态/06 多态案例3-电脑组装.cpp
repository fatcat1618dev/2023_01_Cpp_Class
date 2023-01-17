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

//���̣�Intel/Lenovo
class IntelCpu:public Cpu
{
public:
	void calculate()
	{
		cout << "Intel��CPU����ing" << endl;
	}
};
class LenovoCpu :public Cpu
{
public:
	void calculate()
	{
		cout << "Lenovo��CPU����ing" << endl;
	}
};

//GPU
class IntelGpu :public Gpu
{
public:
	void display()
	{
		cout << "Intel��GPU����ing" << endl;
	}
};
class LenovoGpu :public Gpu
{
public:
	void display()
	{
		cout << "Lenovo��GPU����ing" << endl;
	}
};
//�ڴ�
class IntelMemory :public Memory
{
public:
	void storage()
	{
		cout << "Intel��DDR����ing" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	void storage()
	{
		cout << "Lenovo��DDR����ing" << endl;
	}
};

//������
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
		cout << "����ָ��" << endl;
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
	//��װ��1̨����
	cout << "..................��1̨................." << endl;
	Cpu* intelcpu = new IntelCpu;
	Gpu* intelgpu = new IntelGpu;		//IntelGpu�ǳ����ࣿ
	Memory* intelmem = new IntelMemory;	//�����ࣿ

	PC* computer1 = new PC(intelcpu, intelgpu, intelmem);
	computer1->pcRun();
	delete computer1;

	//��2̨
	cout << "..................��2̨................." << endl;
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