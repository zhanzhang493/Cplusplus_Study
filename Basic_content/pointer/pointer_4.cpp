#include <iostream>
using namespace std;

/* const 修饰指针的三种情况 */
// * 常量指针 const int *: 指针的指向可以修改，但指针指向的内存的值不可以修改
// * 指针常量 int * const：指针的指向不可以修改，但指针指向的内存的值可以修改
// * const 修饰指针和常量: const int * const : 指针的指向，和指针指向的内存的值都不可以修改


int main()
{   
    int a = 10;
    int b = 20;

    // 常量指针
    const int * p = &a;
    p = &b;  // 常量指针可以指向不同的内存
    // *p = 100;  error, 常量指针指向的内存不能更改

    // 指针常量
    int * const q = &a;
    // q = &b; error, 指针常量不能修改指向的内存
    *q = 100;  // 指针常量指向的内存可以修改
    cout << "b的值: " << *q << endl;

    // const int * const
    const int * const m = &a;  // 都不能修改

    return 0;
}