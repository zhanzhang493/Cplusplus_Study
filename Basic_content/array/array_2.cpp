#include <iostream>
using namespace std;

/* 1-dimensional array */
// 数组名可以统计整个数组在内存中的长度
// 数组名可以获取数组在内存中的首地址
// 数组名是常量，不可以进行赋值操作，也就是说 grade = 100 <- 错误的

int main()
{
    int grade[10] = {90, 99, 100, 87, 86, 66, 76, 58, 80, 98}; 

    cout << "int类型占内存大小: " << sizeof(int) << endl;
    cout << "grade数组占内存大小: " << sizeof(grade) << endl;
    cout << "grade中元素的个数: " << sizeof(grade) / sizeof(int) << endl;

    cout << "grade的地址: " << grade << endl;
    cout << "grade的首地址: " << grade << endl;
    cout << "grade的第二个元素的地址: " << grade + 1 << endl;
    cout << "grade的第二个元素的地址: " << &grade[1] << endl;

    for (int i = 0; i < 10; i++){
        if (i != 9){
            cout << grade[i] << ", ";
        }else{
            cout << grade[i] << endl;
        }
    }
}