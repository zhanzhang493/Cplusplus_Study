#include <iostream>
#include <string>
using namespace std;

/* class and struct */
// struct: 默认public
// class: 默认private

class C1
{
    int m_A; // 默认private
};

struct S1
{
    int m_A; // 默认public
};

int main()
{
    C1 c;
    // c.m_A = 1; error: private
    S1 s;
    s.m_A = 1;  // correct: public
    cout << "m_A = " << s.m_A << endl;

    return 0;
}