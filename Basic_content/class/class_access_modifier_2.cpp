#include <iostream>
#include<assert.h>

using namespace std;
/* 继承中的特定 */
/* 
Comments:
有public, protected, private三种继承方式，它们相应地改变了基类成员的访问属性。

1.public 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：public, protected, private

2.protected 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：protected, protected, private

3.private 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：private, private, private

但无论哪种继承方式，上面两点都没有改变：

1.private 成员只能被本类成员（类内）和友元访问，不能被派生类访问；

2.protected 成员可以被派生类访问。
*/


class A{
	public:
		int a;
		A(){
			a1 = 1;
			a2 = 2;
			a3 = 3;
			a = 4;
		}
		virtual void fun(){  // 如果有override的需求，加上virtual，否则可能会让程序结果有偏差
			cout << "a =" << a << endl;     
			cout << "a1 =" << a1 << endl;      
			cout << "a2 =" << a2 << endl;       
			cout << "a3 =" << a3 << endl;       
		}
	public:
		int a1;
	protected:
		int a2;
	private:
		int a3;
};


///////////////////////////////////////////////////////////
/* Public */
class B : public A{
	public:
		B(int i){
			A();
			a = i;
		}
		void fun(){
			cout << "a =" << a << endl;       //正确，public成员
			cout << "a1 =" << a1 << endl;       //正确，基类的public成员，在派生类中仍是public成员。
			cout << "a2 =" << a2 << endl;       //正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
			// cout << "a3 =" << a3 << endl;       //错误，基类的private成员不能被派生类访问。
		}
};

///////////////////////////////////////////////////////////
/* protected  */
class C : protected  A{
	public:
	int a;
		C(int i){
			A();
			a = i;
		}
		void fun(){
			cout << "a =" << a << endl;       //正确，public成员
			cout << "a1 =" << a1 << endl;       //正确，基类的public成员，在派生类中变成了protected，可以被派生类访问。
			cout << "a2 =" << a2 << endl;       //正确，基类的protected成员，在派生类中还是protected，可以被派生类访问。
			// cout << "a3 =" << a3 << endl;       //错误，基类的private成员不能被派生类访问。
		}
};

///////////////////////////////////////////////////////////
/* private  */
class D : private  A{
	public:
	int a;
		D(int i){
			A();
			a = i;
		}
		void fun(){
			cout << "a =" << a << endl;       //正确，public成员
			cout << "a1 =" << a1 << endl;       //正确，基类public成员,在派生类中变成了private,可以被派生类访问。
			cout << "a2 =" << a2 << endl;       //正确，基类的protected成员，在派生类中变成了private,可以被派生类访问。
			// cout << "a3 =" << a3 << endl;       //错误，基类的private成员不能被派生类访问。
		}
};

///////////////////////////////////////////////////////////
int main()
{
///////////////////////////////////////////////////////////
	/* Public */
	cout << "# Public access modifier " << endl;
	A a;
	a.fun();
	B b(10);
	cout << b.a << endl;
	cout << b.a1 << endl;   //正确
	// cout << b.a2 << endl;   //错误，类外不能访问protected成员
	// cout << b.a3 << endl;   //错误，类外不能访问private成员
	b.fun();
	
///////////////////////////////////////////////////////////
	/* protected */	
	cout << "# Protected access modifier " << endl;
	C c(3);
	cout << c.a << endl;       //正确。public成员
	// cout << c.a1 << endl;      //错误，protected成员不能在类外访问。
	// cout << c.a2 << endl;      //错误，protected成员不能在类外访问。
	// cout << c.a3 << endl;      //错误，private成员不能在类外访问。
	c.fun();
	
///////////////////////////////////////////////////////////
	/* private */	
	cout << "# private access modifier " << endl;
	D d(5);
	cout << d.a << endl;       //正确。public成员
	// cout << d.a1 << endl;      //错误，private成员不能在类外访问。
	// cout << d.a2 << endl;      //错误, private成员不能在类外访问。
	// cout << d.a3 << endl;      //错误，private成员不能在类外访问。
	d.fun();
	
	
///////////////////////////////////////////////////////////
	/* virtual */	
	cout << "# virtual" << endl;
	A *ptr = new B(1); // vitural 的作用，让这种情况下，ptr指向B，而不是A
	ptr->fun();

///////////////////////////////////////////////////////////
	return 0;
	
}