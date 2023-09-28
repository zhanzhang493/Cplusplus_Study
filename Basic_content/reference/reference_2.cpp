#include <iostream>
#include <string>

/* 引用的本质 */
// * 引用的本质在c++内部实现是一个指针常量

void func(int& ref)  // 发现是reference, 转换为 int * const ref = &a
{
    std::cout << "run func(int&), " << "赋值为100" << std::endl; 
    ref = 100;  // ref是引用，转换为 *ref = 100
}

int main()
{   
    int a = 10;
    int& ref_1 = a;
    std::cout << "ref_1是a的引用." << std::endl;
    // 自动转换为 int * const ref_2 = &a; 
    // 指针常量：指针指向不可改，也说明为什么引用不可更改
    ref_1 = 20; // 内部发现ref_2是引用，自动帮我们转换为: *ref = 20;

    std::cout << "a: " << a << std::endl;
    std::cout << "ref_1: " << ref_1 << std::endl;

    func(ref_1);

    std::cout << "a: " << a << std::endl;
    std::cout << "ref_1: " << ref_1 << std::endl;
    
    return 0;
}