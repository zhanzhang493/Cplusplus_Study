#include <iostream>

using namespace std;
//////////////////////////////////////////
/* Copy constructor */
/*
Comments:
拷贝构造函数是一种特殊的构造函数，它在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象。拷贝构造函数通常用于：

1. 通过使用另一个同类型的对象来初始化新创建的对象。

2. 复制对象把它作为参数传递给函数。

3. 复制对象，并从函数返回这个对象。

如果在类中没有定义拷贝构造函数，编译器会自行定义一个。如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数。
*/



//////////////////////////////////////////

class Line
{
	public:
		int getLength( void );
		Line( int len );             // 简单的构造函数
		Line( const Line &obj);      // 拷贝构造函数
		~Line();                     // 析构函数

	private:
		int *ptr;
};
 
// 成员函数定义，包括构造函数
Line::Line(int len)
{
	cout << "调用构造函数" << endl;
	// 为指针分配内存
	ptr = new int;
	*ptr = len;
}
 
Line::Line(const Line &obj)
{
	cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
	ptr = new int;
	*ptr = *obj.ptr; // 拷贝值
}
/*
Comments: 
私有成员的定义是：只可以被本类中的其他成员访问。

拷贝构造函数 当然是其类的一个成员，当然可以访问他的私有成员了。

私有等属性是对类说的，不是对对象说的。
*/
 
Line::~Line(void)
{
	cout << "释放内存" << endl;
	delete ptr;
}
int Line::getLength( void )
{
	return *ptr;
}
 
void display(Line obj)
{
	cout << "line 大小 : " << obj.getLength() <<endl;
}

///////////////////////////////////////////////////
// 程序的主函数
int main( )
{
	Line line(10);
	
	Line line2(line);

	display(line);

	return 0;
}