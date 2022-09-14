#include <iostream>

using namespace std;

//////////////////////////////////////////
/* class 的 this 指针 */
/*
Comments:
在 C++ 中，每一个对象都能通过 this 指针来访问自己的地址。

this 指针是所有成员函数的隐含参数。因此，在成员函数内部，它可以用来指向调用对象。

友元函数没有 this 指针，因为友元不是类的成员。只有成员函数才有 this 指针。
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
		
		Box(Box &box) // 拷贝构造函数
		{
			cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
			length = box.length;
			breadth = box.breadth;
			height = box.height;
		}
		/*
		Comments: 
		私有成员的定义是：只可以被本类中的其他成员访问。

		拷贝构造函数 当然是其类的一个成员，当然可以访问他的私有成员了。

		私有等属性是对类说的，不是对对象说的。
		*/
		
		~Box(void) //析构函数
		{
			cout << "Object is being deleted" << endl;
		}
		
		double Volume()
		{
			return length * breadth * height;
		}
		
		int compare(Box box)
		{
			return this->Volume() > box.Volume();
		}
	private:
		double length;     // Length of a box
		double breadth;    // Breadth of a box
		double height;     // Height of a box
};
 

//////////////////////////////////////////
int main(void)
{
	Box Box1(3.3, 1.2, 1.5);    // Declare box1
	Box Box2(8.5, 6.0, 2.0);    // Declare box2

	if(Box1.compare(Box2))
	{
		cout << "Box2 is smaller than Box1" <<endl;
	}
	else
	{
		cout << "Box2 is equal to or larger than Box1" <<endl;
	}
	return 0;
}