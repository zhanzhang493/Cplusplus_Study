#include <iostream>
using namespace std;

/* 指针 */
// * 指针也是种数据类型，那么这种数据类型占用多少内存空间
// * 在64位操作系统下，指针占用内存的大小是8 bytes.

int main()
{
    cout << "sizeof(int *) = " << sizeof(int *) << endl;
    cout << "sizeof(float *) = " << sizeof(float *) << endl;
    cout << "sizeof(double *) = " << sizeof(double *) << endl;
    cout << "sizeof(char *) = " << sizeof(char *) << endl;
    cout << "sizeof(bool *) = " << sizeof(bool *) << endl;
    cout << "sizeof(void *) = " << sizeof(void *) << endl;
    return 0;
}