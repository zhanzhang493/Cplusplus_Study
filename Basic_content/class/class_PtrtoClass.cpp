#include <iostream>

using namespace std;

//////////////////////////////////////////
/* 指向类class的指针 */
/* 
Comments:
一个指向 C++ 类的指针与指向结构的指针类似，

访问指向类的指针的成员，需要使用成员访问运算符 ->，

就像访问指向结构的指针一样。

与所有的指针一样， 必须在使用指针之前，对指针进行初始化。

在成员函数内部，我们可以直接使用调用该函数的对象的成员，而无需通过成员访问运算符来做到这一点，

因为this所指的正是这个对象。任何对类成员的直接访问都被看成this的隐式使用。

this的目的总是指向这个对象，所以this是一个常量指针，我们不允许改变this中保存的地址

this指针的使用：
一种情况就是，在类的非静态成员函数中返回类对象本身的时候，直接使用 return *this；

另外一种情况是当参数与成员变量名相同时，如this->n = n （不能写成n = n）。
*/
//////////////////////////////////////////

class Box
{
   public:
      // 构造函数定义
      Box(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
      }
      double Volume()
      {
         return length * breadth * height;
      }
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

int main(void)
{
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2
   Box *ptrBox;                // Declare pointer to a class.

   // 保存第一个对象的地址
   ptrBox = &Box1;

   // 现在尝试使用成员访问运算符来访问成员
   cout << "Volume of Box1: " << ptrBox->Volume() << endl;

   // 保存第二个对象的地址
   ptrBox = &Box2;

   // 现在尝试使用成员访问运算符来访问成员
   cout << "Volume of Box2: " << ptrBox->Volume() << endl;
  
   return 0;
}