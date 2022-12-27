#include <iostream>
#include <string>
using namespace std;

/* 访问权限 */
// 类的访问权限有三种
// public:    成员，类内可以访问，类外可以访问
// protected: 成员，类内可以访问，类外不可以访问，派生类（即子类）可以访问。
// private:   成员，类内可以访问，类外不可以访问，派生类（即子类）不可以访问。

// 立方体类设计
// 1. 创建类
// 2. 设计属性
// 3. 设计行为，获得体积和面积
// 4. 利用全局函数和成员函数，分别判断两个立方体是否相等

class Cube
{
    public:

    protected:

    private:
        int m_L;
        int m_W;
        int m_H;

    public:
    void set_cube(int l, int w, int h)
    {
        m_L = l;
        m_W = w;
        m_H = h;
    }

    int get_l()
    {
        return m_L;
    }

    int get_w()
    {
        return m_W;
    }

    int get_h()
    {
        return m_W;
    }
   
   int cal_s()
   {
        return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
   }

   int cal_v()
   {
        return m_L * m_W * m_H;
   }

    void show_info()
    {
        cout << "Long: " << m_L << endl; // 私有属性，成员函数可以直接访问
        cout << "Width: "  << m_W << endl;
        cout << "Height: "  << m_H << endl;
        cout << "面积: "  << cal_s() << endl;
        cout << "体积: "  << cal_v() << endl;
    }

    bool is_same_by_class(Cube &c)
    {
        if (m_L == c.get_l() && m_W == c.get_w() && m_H == c.get_h()){
            return true;
        }else{
            return false;
        }
    }
};

bool is_same_cube(Cube c1, Cube c2)
{
    if (c1.get_l() == c2.get_l() && c1.get_w() == c2.get_w() && c1.get_h() == c2.get_h()){
        return true;
    }else{
        return false;
    }
    
}

int main()
{
    Cube c1, c2;
    c1.set_cube(10, 20, 30);
    c2.set_cube(10, 30, 20);

    c1.show_info();
    c2.show_info();

    cout << "Is same: " << is_same_cube(c1, c2) << endl;
    cout << "Is same: " << c1.is_same_by_class(c2) << endl;
    return 0;
}