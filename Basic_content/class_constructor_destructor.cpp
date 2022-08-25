#include <iostream>

using namespace std;

////////////////////////////////////////////////////
/* 构造函数 */
/*
Comments:
类的构造函数是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。

构造函数的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回 void。构造函数可用于为某些成员变量设置初始值。
*/

////////////////////////////////////////////////////
/* 析构函数 */
/*
Comments:
类的析构函数是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行。

析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，

它不会返回任何值，也不能带有任何参数。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。
*/
////////////////////////////////////////////////////


class Line
{
	public:
		void setLength( double len );
		double getLength( void );
		void setWidth( double wid );
		double getWidth( void );
		Line();  // 这是构造函数
		Line(double len); // 带参数的构造函数
		Line(double len, double wid);
		~Line();  // 这是析构函数声明
 
	private:
		double length;
		double width;
};
 
// 成员函数定义，包括构造函数
Line::Line(void)
{
	cout << "Object is being created" << endl;
}

Line::Line( double len )
{
	cout << "Object is being created, length = " << len << endl;
	length = len;
}
 
Line::Line( double len, double wid ): length(len), width(wid)
{
	cout << "Object is being created, length = " << len << "; and width = " << wid << endl;
}

// 成员函数定义，包括构造函数
Line::~Line(void)
{
	cout << "Object is being deleted" << endl;
}


// 其他成员函数
void Line::setLength( double len )
{
	length = len;
}
 
double Line::getLength( void )
{
	return length;
}

void Line::setWidth( double wid )
{
	width = wid;
}
 
double Line::getWidth( void )
{
	return width;
}

///////////////////////////////////////
int main()
{
//////////////////////////////////////
	Line line1;

	// 设置长度
	line1.setLength(6.0); 
	cout << "Length of line : " << line1.getLength() <<endl;
	
/////////////////////////////////////	
	Line line2(10.0);

	// 获取默认设置的长度
	cout << "Length of line : " << line2.getLength() <<endl;
	// 再次设置长度
	line2.setLength(6.0); 
	cout << "Length of line : " << line2.getLength() <<endl;
	
/////////////////////////////////////	
	Line line3(10.0, 2.0);
	cout << "Width of line : " << line3.getWidth() <<endl; 
	line3.setWidth(3.0);
	cout << "Width of line : " << line3.getWidth() <<endl;
	
	
	return 0;
}