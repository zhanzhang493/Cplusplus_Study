#include<iostream>
using namespace std;

/* goto: 如果标记名称存在，执行goto语句时，会跳转到标记的位置 */

int main()
{
    cout << '1' << endl;

    goto FLAG;

    cout << '2' << endl;
    cout << '3' << endl;
    cout << '4' << endl;
    cout << '5' << endl;

    FLAG:
    cout << '6' << endl;
    cout << '7' << endl;
    cout << '8' << endl;
}