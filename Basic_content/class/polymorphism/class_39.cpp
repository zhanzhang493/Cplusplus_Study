#include <iostream>
#include <string>
using namespace std;

/* 多态的案例 */
// 利用普通和多态写法，实现两个操作数进行运算的计算器类

// 如果想扩展新功能，需修改源代码
// 在真的开发中，提倡 开闭原则
// 开闭原则： 对扩展进行开发，对修改进行关闭

// 多态的优点
// 代码组织结构清晰
// 可读性强
// 利于前期和后期的扩展以及维护

class Calculator
{
    public:
        int get_result(string oper)
        {
            if (oper == "+"){
                return m_Num1 + m_Num2;
            } else if (oper == "-") {
                return m_Num1 - m_Num2;
            } else if (oper == "*") {
                return m_Num1 * m_Num2;
            } else {
                return 0;
            }
        }

        int m_Num1;
        int m_Num2;
};

// 多态实现
class BaseCalculator
{
    public:
        virtual int getResult()
        {
            return 0;
        }

        int m_Num1;
        int m_Num2;
};

class AddCalculator: public BaseCalculator
{
    public:
        int getResult()
        {
            return m_Num1 + m_Num2;
        }
};

class SubCalculator: public BaseCalculator
{
    public:
        int getResult()
        {
            return m_Num1 - m_Num2;
        }
};

class MulCalculator: public BaseCalculator
{
    public:
        int getResult()
        {
            return m_Num1 * m_Num2;
        }
};

void test01()
{
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 20;
    cout << "+: " << c.get_result("+") << endl;
    cout << "-: " << c.get_result("-") << endl;
    cout << "*: " << c.get_result("*") << endl;
}

void test02()
{
    // 多态使用条件
    // 父类指针或引用，指向子类对象

    BaseCalculator * abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 30;
    cout << "+: " << abc->getResult() << endl;
    delete abc; // 用完记得销毁

    abc = new SubCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 30;
    cout << "-: " << abc->getResult() << endl;
    delete abc; // 用完记得销毁

    abc = new MulCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 30;
    cout << "*: " << abc->getResult() << endl;
    delete abc; // 用完记得销毁
}

int main()
{
    test01();
    test02();
    return 0;
}