#include <iostream>
#include <string>
using namespace std;

/* 继承 */
// 继承是面向对象的三大特性之一
// 语法：
// class 子类: 继承方式 父类
// 子类 == 派生类
// 父类 == 基类
// 子类，包含了两大部分：从基类继承过来的，新增的
// 从基类继承的，变现其共性
// 新增的，变现为个性


class WebPage
{
    public:
        void header()
        {
            cout << "Header." << endl;
        }

        void bottom()
        {
            cout << "Bottom." << endl;
        }

        void footer()
        {
            cout << "Help." << endl;
        }

        void left()
        {
            cout << "content." << endl;
        }

        virtual void content(){} // virtual 关键词
        // 如果有override的需求，加上virtual，否则可能会让程序结果有偏差

        void show_info()
        {
            cout << "---------------" << endl;
            header();
            bottom();
            footer();
            left();
            content();
        }
};

/* 继承 */
class JavaPage: public WebPage
{
    public:
        void content()
        {
            cout << "Java content." << endl;
        }
};

class PythonPage: public WebPage
{
    public:
        void content()
        {
            cout << "Python content." << endl;
        }
};

class CppPage: public WebPage
{
    public:
        void content()
        {
            cout << "C++ content." << endl;
        }
};

void test01()
{
    JavaPage j1;
    j1.show_info();
    PythonPage p1;
    p1.show_info();
    CppPage c1;
    c1.show_info();
}

int main()
{
    test01();
    return 0;
}