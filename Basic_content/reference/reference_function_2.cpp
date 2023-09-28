#include <iostream>
#include <string>

/* 引用做函数返回值 */
// * 可以作为函数的返回值
// * 注意：不要返回局部变量的引用
// * 如果函数的返回值是引用，这个函数调用可以作为左值
// * 如果函数的返回值是引用，赋值给另外一个变量，拷贝赋值，而不是传递地址

int * test01();
int & test02();

int main()
{
    // 函数返回的是指针
    int* ref1 = test01();
    std::cout << "ref1指向的地址: " << ref1 << std::endl;
    std::cout << "ref1的指向的值: " << *ref1 << std::endl;

    *ref1 = 500;
    std::cout << "ref1指向的地址: " << ref1 << std::endl;
    std::cout << "ref1的指向的值: " << *ref1 << std::endl;

    delete ref1;

    // 函数返回的是引用
    std::cout << "*函数返回的是引用*" << std::endl;
    int& ref2 = test02();
    std::cout << "ref2的地址是: " << &ref2 << std::endl;
    std::cout << "ref2的值是: " << ref2 << std::endl;

    std::cout << "*函数返回的是引用，这个函数调用可以作为左值*" << std::endl;
    test02() = 1000; // 左值
    std::cout << "ref2的地址是: " << &ref2 << std::endl;
    std::cout << "ref2的值是: " << ref2 << std::endl;

    
    std::cout << "*函数的返回值是引用，赋值给另外一个变量，拷贝赋值，而不是传递地址*" << std::endl;
    int value = test02();
    std::cout << "value的地址是: " << &value << std::endl;
    std::cout << "value的值是: " << value << std::endl;
    std::cout << "ref2的地址是: " << &ref2 << std::endl;
    std::cout << "ref2的值是: " << ref2 << std::endl;

    return 0;
}

int* test01()
{
    // int a = 10;  // 局部变量存放在栈区
    int* ptr = new int(10); // 局部变量存放在堆区
    std::cout << "run test01(), 返回指针, 函数内部产生一个堆区变量(v=10), 地址是: " << ptr << std::endl;
    return ptr;
}

int& test02()
{
    static int a = 20; // 静态变量存放在全局区
    std::cout << "run test01(), 返回引用, 函数内部产生一个静态变量(v=20), 地址是: " << &a << std::endl;
    return a;
}