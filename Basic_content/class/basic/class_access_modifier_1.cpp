#include <iostream>

using namespace std;
/* public, private, protected */


///////////////////////////////////////////////////////////
/* Public */
/* 
Comments:
公有成员在程序中类的外部是可访问的,
可以不使用任何成员函数来设置和获取公有变量的值
*/

class Line
{
	public:
		double length;
		void setLength( double len );
		double getLength( void );
};
 
// 成员函数定义
double Line::getLength(void)
{
    return length ;
}
 
void Line::setLength( double len )
{
    length = len;
}
///////////////////////////////////////////////////////////
/* Private */
/* 
Comments:
私有成员变量或函数在类的外部是不可访问的，甚至是不可查看的。
只有类和友元函数可以访问私有成员。
默认情况下，类的所有成员都是私有的。
这意味着，如果您没有使用任何访问修饰符，类的成员将被假定为私有成员。
例如在下面的类中，width 是一个私有成员
*/

#if 0
class Box
{
	double width;
	public:
		double length;
		void setWidth( double wid );
		double getWidth( void );
};
#endif

class Box
{
	public:
		double length;
		void setWidth( double wid );
		double getWidth( void );

	private:
		double width;
};
 
// 成员函数定义
double Box::getWidth(void)
{
	return width ;
}
 
void Box::setWidth( double wid )
{
	width = wid;
}
///////////////////////////////////////////////////////////
/* Protect */
/* 
Comments:
protected（受保护）成员变量或函数与私有成员十分相似，
但有一点不同，protected（受保护）成员在派生类（即子类）中是可访问的。
可以看到下面的实例中，从父类 Box 派生了一个子类 smallBox。
在这里 width 成员可被派生类 smallBox 的任何成员函数访问。
*/

class Box_protect
{
	protected:
		double width;
};
 
class SmallBox:Box_protect // SmallBox 是派生类
{
	public:
		void setSmallWidth( double wid );
		double getSmallWidth( void );
};
 
// 子类的成员函数
double SmallBox::getSmallWidth(void)
{
    return width ;
}
 
void SmallBox::setSmallWidth( double wid )
{
    width = wid;
}

///////////////////////////////////////////////////////////
int main()
{
///////////////////////////////////////////////////////////
	/* Public */
	cout << "# Public access modifier " << endl;
	Line line;

	// 设置长度
	line.setLength(6.0); 
	cout << "Length of line : " << line.getLength() << endl;

	// 不使用成员函数设置长度
	line.length = 10.0; // OK: 因为 length 是公有的
	cout << "Length of line : " << line.length << endl;
   
///////////////////////////////////////////////////////////
	/* Private */
	cout << "# Private access modifier " << endl;
	Box box;
 
	// 不使用成员函数设置长度
	box.length = 10.0; // OK: 因为 length 是公有的
	cout << "Length of box : " << box.length <<endl;

	// 不使用成员函数设置宽度
	// box.width = 10.0; // Error: 因为 width 是私有的
	box.setWidth(10.0);  // 使用成员函数设置宽度
	cout << "Width of box : " << box.getWidth() <<endl;
///////////////////////////////////////////////////////////
	/* Protect */
	cout << "# Protect access modifier " << endl;
	
	SmallBox box_protect;
 
	// 使用成员函数设置宽度
	box_protect.setSmallWidth(5.0);
	cout << "Width of box_protect : "<< box_protect.getSmallWidth() << endl;

	return 0;
}