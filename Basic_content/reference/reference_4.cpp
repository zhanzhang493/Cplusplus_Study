#include <iostream>
#include <string>
using namespace std;

/* 引用的本质 */
// 引用的本质在c++内部实现是一个指针常量
// 不能建立引用数组，但可以建立数组的引用
// 数组的引用 数据类型 (& 别名)[数组大小] = 数组名；
// 引用的数组： int & ref[3] --> 一个大小为3的数组，每个元素为引用 <- error

void func(int & ref) // 发现是reference, 转换为 int * const ref = &a
{
    ref = 100; // ref是引用，转换为 *ref = 100
}

int main()
{   
    /* 数组的引用 */
    int arr[3] = {2, 4, 6};
    int (& ref)[3] = arr;

    for (int i = 0; i < 3; i++){
        cout << ref[i] << endl;
    }

    /* 引用的本质 */
    int a = 10;

    int & ref_2 = a;
    // 自动转换为 int * const ref_2 = &a; 
    // 指针常量：指针指向不可改，也说明为什么引用不可更改
    ref_2 = 20; // 内部发现ref_2是引用，自动帮我们转换为: *ref = 20;

    cout << "a: " << a << endl;
    cout << "ref_2: " << ref_2 << endl;

    func(ref_2);

    cout << "a: " << a << endl;
    cout << "ref_2: " << ref_2 << endl;
    
    return 0;
}