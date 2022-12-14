#include <iostream>
#include <string>
using namespace std;

/* 内存分区模型 */
// 代码区：存放函数体的二进制代码，由操作系统进行管理
// 全局区：存放全局变量、静态变量、常量
// 栈区：由编译器自动分配释放，存放函数的参数值，局部变量
// 堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收

// 在程序编译后，生成.exe可执行程序（linux .out文件），未执行该程序前，分为两个区域：代码区和全局区

/* 代码区 */
// 存放CPU执行的机器指令
// 代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中存有一份代码即可
// 代码区是只读的，使其只读的原因是防止程序意外地修改了它的指令

/* 全局区 */
// 全局变量、静态变量
// 全局区还包含了常量区，字符串常量和其他常量也存放在此
// 该区域的数据在程序结束后由操作系统释放

// 程序运行后，分为两个区域：栈区和堆区

/* 栈区 */
// 由编译器自动分配释放，存放函数的参数值，局部变量，函数形参
// Please note: 不要返回局部变量的地址，栈区开辟的数据由编译器自动释放

/* 堆区 */
// 由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收
// 在c++中主要利用new在堆区开辟内存


int g_a = 10; // 全局变量

const int c_g_a = 10; // const修饰的全局变量

int * func();
int * func_1();

int main()
{
    int a = 10; // 局部变量

    cout << "局部变量a的地址: " << &a << endl;

    cout << "全局变量g_a的地址: " << &g_a << endl;

    static int s_a = 10; // 静态变量
    cout << "静态变量s_a的地址: " << &s_a << endl;

    cout << "字符串常量的地址: " << &"Hello world" << endl; // 字符串常量

    cout << "全局常量c_g_a的地址: " << &c_g_a << endl;

    const int c_l_a = 10; // const修饰的局部变量
    cout << "局部常量c_l_a的地址: " << &c_l_a << endl;

    int * p = func();
    cout << *p << endl; // 第一次可以打印正确的数字，是因为编译器做了保留
    cout << *p << endl; // 第二次这个数据就不再保留了

    int * q = func_1();
    cout << "堆区变量的地址: " << q << endl; // 第一次可以打印正确的数字，是因为编译器做了保留
    cout << "堆区变量的值: " << *q << endl; // 第二次这个数据就不再保留了

    return 0;
}

int * func() // 形参，局部参数，存放在栈区
{
    int a = 10;
    int * p = &a;
    return p;
}


int * func_1() 
{
    int * p = new int(10); // 利用new关键字，将数据开辟到堆区
    // 指针本身是个局部变量，只是指针保存的数据是堆区内存的地址
    return p;
}
