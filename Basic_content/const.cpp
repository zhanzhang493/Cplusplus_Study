#include <iostream>
using namespace std;
/* 
Author: zhan.zhang493@qq.com 
Begin-Date: 2022-08-10       
Details: study 'const'   
*/

/* const的作用：
1. 类型检查 
(1) const常量与#define宏定义常量的区别：const常量具有类型，编译器可以进行安全检查；
#define宏定义没有数据类型，只是简单的字符串替换，不能进行安全检查。
(2) const定义的变量只有类型为整数或枚举，且以常量表达式初始化时才能作为常量表达式。
(3) 其他情况下它只是一个 const 限定的变量，不要将与常量混淆。
2. 防止修改，起保护作用，增加程序健壮性，尤其是在函数定义中
void f(const int i){
    i++; // error
}
3. 可以节省空间，避免不必要的内存分配
(1) const定义常量从汇编的角度来看，只是给出了对应的内存地址，而不是像#define一样给出的是立即数。
(2) const定义的常量在程序运行过程中只有一份拷贝，而#define定义的常量在内存中有若干个拷贝。*/

//////////// start /////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
/* 类型检查，防止程序修改变量 */
#if 0 
void f(const int i){    // variable 'i' declared const here
    i = 10;         // error: assignment of read-only parameter 'i'
    cout<<i<<endl;    
}
#endif

void f_correct(int i){    
    cout<<"# protect function input variable."<<endl;
    i = 10;         
    cout<<i<<endl;    
}

////////////////////////////////////////////////////////////////////
/* 定义const*/
#if 0
void define_const(){    
    const int b = 10;
    b = 30;         // const变量不能修改
    const string s = "helloworld"; 
    const int i, j = 10;        // const变量必须初始化    
    cout<<b<<s<<i<<j<<endl;    
}
#endif

void define_const_correct(){ 
    cout<<"# Define a const variable."<<endl;  
    int b = 10;
    b = 30;
    const string s = "helloworld"; 
    const int i = 20, j = 10;            
    cout << b << ',' << s << ',' << i << ',' << j << endl;    
}

////////////////////////////////////////////////////////////////////
/* 指针与const */
/*与指针相关的const有四种：
(1) const char * a; //指向const对象的指针或者说指向常量的指针。
(2) char const * a; //同上
(3) char * const a; //指向类型对象的const指针。或者说常指针、const指针。
(4) const char * const a; //指向const对象的const指针。*/

//#1指向常量的指针
#if 0
void pointConst(){
    const int *ptr;
    *ptr = 10; // error

    const int p = 10;
    const void *vp = &p;
    void *vp = &p; // error: 不能用void *vp来保存const对象的地址，必须用const void *vp
}
/* Comments:
(1) ptr是一个指向int类型const对象的指针，const定义的是int类型，
也就是ptr所指向的对象是const的，
而不是ptr本身，所以ptr可以不用赋初始值，
但是不能通过ptr去修改所指对象的值。<--key point
(2) 一种特殊的void类型指针，
可以存储任何类型的对象地址，
就是说任何类型的指针都可以赋值给void类型的指针变量。
经过使用类型显示转换，
通过void类型值的指针便可以访问任何类型的数据。 */
#endif

void pointConst_correct(){
    cout<<"# point a const variable."<<endl;
    const int *ptr;
    const int j = 10;
    ptr = &j;   // 正确，指针指向了一个const int类型的变量
    cout << *ptr << endl;
    const int i = 20;
    ptr = &i;
    cout << *ptr << endl; // 正确，指针本身是可以修改的
    int var = 30;
    ptr = &var;
    cout << *ptr << endl; // 正确，允许把非const对象的地址赋给指向const对象的指针

    const int p = 10;
    const void *vp = &p;
    cout << *ptr << endl; // 正确，用const void *vp保存const变量的地址

}
/* Comments: 
(1) 对于指向常量的指针，不能通过指针来修改对象的值
(2) 允许把非const对象的地址赋值给const对象的指针，如果要修改指针所指向的对象值，
必须通过其他方式修改，不能直接通过当前指针直接修改。
(3) 不能使用void*指针保存const对象的地址，必须使用const void*类型的指针保存const对象的地址。*/

//#2 常指针
/* const指针必须初始化，且const指针的值不能修改 */
#if 0
void constPtr(){
    cout<<"# a const point."<<endl;
    int num = 0;
    int *const ptr = &num;
    int val = 30;
    ptr = &val;  // error: const指针不能被修改
    cout<< *ptr << endl;
}
#endif

void constPtr_correct(){
    cout<<"# a const point."<<endl;
    int num = 0;
    int *const ptr = &num;
    num = 20;  // correct： const指针不能被修改（指向的地址不能修改），但是地址里的内容可以修改
    cout<< *ptr << endl;
}

//#3 指向const变量的const指针
/* const指针必须初始化，且const指针的值不能修改 */
#if 0
void constPtr_to_constVar(){
    const int num=0;
    int * const ptr=&num; //error! const int* -> int*
    cout<<*ptr<<endl;
}
/* Comments:
当把一个const常量的地址赋值给ptr时候，由于ptr指向的是一个变量，而不是const常量，所以会报错 const int* -> int* */
#endif
void constPtr_to_constVar_correct(){
    cout<<"# const point to const variable."<<endl;
    const int num=0;
    const int *const ptr=&num; // correct: const变量必须由指向const变量的指针来指向
    cout<<*ptr<<endl;
}

////////////////////////////////////////////////////////////////////
/* const修饰函数返回值 */
//#1 const修饰函数返回值
const int func_constReturn(){  // 这个本身无意义，因为参数返回本身就是赋值给其他的变量
    cout << "# const int" <<endl;
    return 10;
}

//#2 const int * 指针指向的内容不变
const int* func_ptr(){  // 指针指向的内容不变，但指针本身的内容可以变，也就是说，不能通过指针修改指向的内容
    const int a = 2;
    const int *ptr = &a;
    cout << "# const int *" <<endl;
    cout << *ptr << endl;
    return ptr;
}

//#3 int *const 指针本身不可变
#if 0
int *const func_constPtr(int b){  // warning: 能run, but个人认为这样有很大的风险，因为b是一个形参，在函数结束后释放
#endif
int *const func_constPtr(int &b){  // correct, 引用
    int a = 30;
    #if 0
    int *const ptr = &a; // warning: 能run, but 个人认为这样有很大的风险，因为&a是一个局部变量
    #endif
    int *const ptr = &b;
    cout << "# int *const" <<endl;
    cout << "* const ptr address = " << ptr << endl;
    return ptr;   
}

////////////////////////////////////////////////////////////////////
/* const修饰函数参数 */
//#1 传递过来的参数及指针本身在函数内不可变，无意义！
void func(const int var); // 传递过来的参数不可变
void func(int *const var); // 指针本身不可变
/* Comments: 
表明参数在函数体内不能被修改，但此处没有任何意义，var本身就是形参，在函数内不会改变。
包括传入的形参是指针也是一样。
输入参数采用“值传递”，由于函数将自动产生临时变量用于复制该参数，
该输入参数本来就无需保护，所以不要加const 修饰。*/

//#2 参数指针所指内容为常量不可变
void StringCopy(char *dst, const char *src);
/* 其中src 是输入参数，dst 是输出参数。
给src加上const修饰后，如果函数体内的语句试图改动src的内容，编译器将指出错误。
这就是加了const的作用之一。
和#1的区别，指针本身是不可变的（指向的地址），但地址里的内容可以约束其不能改变。*/

//#3 参数为引用，为了增加效率同时防止修改。
struct Student{
    int ID;
    string Name;
};

 void func(const Student &a);
 /* Comments:对于非内部数据类型的参数而言，
 像void func(Student a) 这样声明的函数注定效率比较低。
 因为函数体内将产生Student类型的临时对象用于复制参数a，
 而临时对象的构造、复制、析构过程都将消耗时间，特别是自定义的类型时。
 为了提高效率，可以将函数声明改为void func(Student &a)，因为“引用传递”仅借用一下参数的别名而已，不需要产生临时对象。
 但是函数void func(Student &a) 存在一个缺点：
“引用传递”有可能改变参数a，这是我们不期望的。
解决这个问题很容易，加const修饰即可，因此函数最终成为 void func(const Student &a)。
特别注意，否应将void func(int x) 改写为void func(const int &x)，以便提高效率？
完全没有必要，因为内部数据类型的参数不存在构造、析构的过程，而复制也非常快，“值传递”和“引用传递”的效率几乎相当。*/


////////////////////////////////////////////////////////////////////
/* 类中使用const */
/* Comments: 
在一个类中，任何不会修改数据成员的函数都应该声明为const类型。
如果在编写const成员函数时，不慎修改数据成员，或者调用了其它非const成员函数，
编译器将指出错误，这无疑会提高程序的健壮性。
*使用const关键字进行说明的成员函数，称为常成员函数。
*只有const成员函数才有资格操作常量或常对象，没有使用const关键字进行说明的成员函数不能用来操作常对象。
*const对象只能访问const成员函数，而非const对象可以访问任意的成员函数，包括const成员函数。
*const成员函数只能访问const成员函数。*/

class Apple
{
private:
    int people[100];
public:
    Apple(int i); 
    const int apple_number;
    void take(int num) const;
    int add();
    int add(int num) const;
    int getCount() const;
};

Apple::Apple(int i):apple_number(i)
{
}

int Apple::add(){
    take(1);
    return 0;
}

int Apple::add(int num) const{
    take(num);
    return num;
}

void Apple::take(int num) const
{
    cout<<"take func "<<num<<endl;
}
int Apple::getCount() const
{
    take(1);
    #if 0
    add();  // error: add方法并非const修饰，所以运行报错。
    #endif
    add(2);

    return 0;
}



////////////////////////////////////////////////////////////////////
/* const对象默认为文件局部变量 */
/*  Comments: 非const变量默认为extern。要使const变量能够在其他文件中访问，必须在文件中显式地指定它为extern。
否则不同的文件中定义相同名字的const 变量是不同的变量 */

////////////////////////////////////////////////////////////////////
/* main */
int main(){
    /* const basic principle*/
    f_correct(3);
    define_const_correct();

    /*const and Ptr*/
    pointConst_correct();
    constPtr_correct();
    constPtr_to_constVar_correct();
    
    /* const and func */
    int a = func_constReturn();   // 变量a可以不是const 类型
    cout << a << endl;
    const int *ptr = func_ptr();  // 返回的是一个指向const int *，因此变量也必须是const int *

    int * ptr2 = func_constPtr(a); // 为什么*const可以修改
    cout<< *ptr2 << endl;
    cout << "* const ptr address = " << ptr2 << endl;
    ptr2 = &a;
    cout << "* const ptr address = " << ptr2 << endl;
    cout<< *ptr2 << endl;
    
    cout << "* const and class = " << endl;
    Apple apple(2);
    cout << apple.getCount() <<endl;
    apple.add(10);
    apple.add();

    const Apple bapple(2); // bapple是const 对象
    bapple.add(3); // correct
    #if 0
    // bapple.add(); // error: const对象只能访问const成员函数。
    #endif

    return 0;
}