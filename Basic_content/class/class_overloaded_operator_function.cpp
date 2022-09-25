#include <iostream>

using namespace std;

//////////////////////////////////////////
/* class 重载运算符和重载函数 */
/*
Comments:
C++ 允许在同一作用域中的某个函数和运算符指定多个定义，分别称为函数重载和运算符重载。

重载声明是指一个与之前已经在该作用域内声明过的函数或方法具有相同名称的声明，
但是它们的参数列表和定义（实现）不相同。

当您调用一个重载函数或重载运算符时，编译器通过把您所使用的参数类型与定义中的参数类型进行比较，决定选用最合适的定义。

选择最合适的重载函数或重载运算符的过程，称为重载决策。
*/
//////////////////////////////////////////


//////////////////////////////////////////
/* class 重载函数 */
/*
Comments:
在同一个作用域内，可以声明几个功能类似的同名函数，但是这些同名函数的形式参数（指参数的个数、类型或者顺序）必须不同。

不能仅通过返回类型的不同来重载函数。
*/
//////////////////////////////////////////

class printData
{
   public:
      void print(int i) 
	  {
        cout << "Int: " << i << endl;
      }
 
      void print(double  f) 
	  {
        cout << "Float: " << f << endl;
      }
 
      void print(char c[]) 
	  {
        cout << "Strings: " << c << endl;
      }
};

//////////////////////////////////////////
/* class 重载运算符 */
/*
Comments:
您可以重定义或重载大部分 C++ 内置的运算符。这样，就能使用自定义类型的运算符。

重载的运算符是带有特殊名称的函数，
函数名是由关键字 operator 和其后要重载的运算符符号构成的。

与其他函数一样，重载运算符有一个返回类型和一个参数列表。
*/
//////////////////////////////////////////

class Box
{
   public:
 
      double getVolume(void)
      {
         return length * breadth * height;
      }
      void setLength( double len )
      {
          length = len;
      }
 
      void setBreadth( double bre )
      {
          breadth = bre;
      }
 
      void setHeight( double hei )
      {
          height = hei;
      }
      // 重载 + 运算符，用于把两个 Box 对象相加
      Box operator+(const Box& b)
      {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }
   private:
      double length;      // 长度
      double breadth;     // 宽度
      double height;      // 高度
};

//////////////////////////////////////////
/* main */
//////////////////////////////////////////

int main(void)
{
	//////////////////////////////////////////
	/* class 重载函数 */
	printData pd;
 
	// 输出整数
	pd.print(5);
	// 输出浮点数
	pd.print(500.263);
	// 输出字符串
	char c[] = "Hello C++";
	pd.print(c);
	
	//////////////////////////////////////////
	/* class 重载运算符 */
	Box Box1;                // 声明 Box1，类型为 Box
	Box Box2;                // 声明 Box2，类型为 Box
	Box Box3;                // 声明 Box3，类型为 Box
	double volume = 0.0;     // 把体积存储在该变量中

	// Box1 详述
	Box1.setLength(6.0); 
	Box1.setBreadth(7.0); 
	Box1.setHeight(5.0);

	// Box2 详述
	Box2.setLength(12.0); 
	Box2.setBreadth(13.0); 
	Box2.setHeight(10.0);

	// Box1 的体积
	volume = Box1.getVolume();
	cout << "Volume of Box1 : " << volume <<endl;

	// Box2 的体积
	volume = Box2.getVolume();
	cout << "Volume of Box2 : " << volume <<endl;

	// 把两个对象相加，得到 Box3
	Box3 = Box1 + Box2;

	// Box3 的体积
	volume = Box3.getVolume();
	cout << "Volume of Box3 : " << volume <<endl;

	return 0;
}