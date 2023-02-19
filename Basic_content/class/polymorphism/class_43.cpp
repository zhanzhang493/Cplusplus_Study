#include <iostream>
#include <string>
using namespace std;

/* 案例 */
// 电脑组装

class CPU
{
    public:
        virtual void calculate() = 0;
};

class VideoCard
{
    public:
        virtual void display() = 0;
};

class Memory
{
    public:
        virtual void storage() = 0;
};

class Computer
{
    public:
        Computer(CPU * cpu, VideoCard * vc, Memory * mem)
        {
            m_cpu = cpu;
            m_vc = vc;
            m_mem = mem;
        }

        void work()
        {
            m_cpu->calculate();
            m_vc->display();
            m_mem->storage();
        }

        ~Computer()
        {
            if (m_cpu != NULL)
            {
                delete m_cpu;
                m_cpu = NULL;
            }

            if (m_vc != NULL)
            {
                delete m_vc;
                m_vc = NULL;
            }

            if (m_mem != NULL)
            {
                delete m_mem;
                m_mem = NULL;
            }
        }
    private:
        CPU * m_cpu;
        VideoCard * m_vc;
        Memory * m_mem;
};

// 具体厂商
class IntelCPU: public CPU
{
    virtual void calculate()
    {
        cout << "Intel CPU run." << endl;
    }
};

class IntelVC: public VideoCard
{
    virtual void display()
    {
        cout << "Intel VC run." << endl;
    }
};

class IntelMEM: public Memory
{
    virtual void storage()
    {
        cout << "Intel memory run." << endl;
    }
};

// 具体厂商
class ARMCPU: public CPU
{
    virtual void calculate()
    {
        cout << "ARM CPU run." << endl;
    }
};

class ARMVC: public VideoCard
{
    virtual void display()
    {
        cout << "ARM VC run." << endl;
    }
};

class ARMMEM: public Memory
{
    virtual void storage()
    {
        cout << "ARM memory run." << endl;
    }
};


void test01()
{
    CPU * intelCPU = new IntelCPU;
    VideoCard * intelCard = new IntelVC;
    Memory * intelMem = new IntelMEM;

    Computer * computer1 = new Computer(intelCPU, intelCard, intelMem);
    computer1->work();
    delete computer1;

    CPU * armCPU = new ARMCPU;
    VideoCard * armCard = new ARMVC;
    Memory * armMem = new ARMMEM;

    Computer * computer2 = new Computer(armCPU, armCard, armMem);
    computer2->work();
    delete computer2;
}

int main()
{
    test01();
    return 0;
}