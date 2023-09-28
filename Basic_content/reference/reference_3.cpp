#include <iostream>
#include <string>

/* 数组的引用 */
// * 不能建立引用的数组，但可以建立数组的引用
// * 数组的引用 数据类型 (& 别名)[数组大小] = 数组名;
// * 引用的数组： int & ref[3] --> 一个大小为3的数组, 每个元素为引用 (!!!error)

int main()
{   
    int arr[3] = {2, 4, 6};
    int (& ref)[3] = arr;

    for (int i = 0; i < 3; i++){
        std::cout << "ref[" << i << "]" << ref[i] << std::endl;
    }

    std::cout << "ref[" << 3 << "]" << ref[3] << std::endl;  // 编译不会出错，但访问越界了
    
    return 0;
}