 ///
 /// @file    vitual2.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-15 08:12:59
 ///
 
#include <iostream>
using std::endl;
using std::cout;

//情况三：
//（1）每个基类都有自己的虚函数表
//（2）派生类如果有自己的虚函数，会被加入到第一个
//虚函数表中
//（3）在内存布局中，其基类的布局按照基类被声明的
//顺序进行排列
//（4）派生类会覆盖基类的虚函数，只有第一个虚函数
//表中存放的是真实的被覆盖的函数的地址，其他的虚
//函数表中存放的并不是真实的对应的虚函数地址，而
//只是一条跳转指令
class Base1{
	public:
		Base1(int base1=10) : _base1(base1)
		{
			cout<<"Base1(int)"<<endl;
		}

		virtual void f(){
			cout<<"Base1::f()"<<endl;
		}

		virtual void g(){
			cout<<"Base1::g()"<<endl;
		}

		virtual void h(){
			cout<<"Base1::h()"<<endl;
		}

	private:
		int _base1;
};

class Base2{
	public:
		Base2(int base2=100) : _base2(base2)
		{
			cout<<"Base2(int)"<<endl;
		}

		virtual void f(){
			cout<<"Base2::f()"<<endl;
		}

		virtual void g(){
			cout<<"Base2::g()"<<endl;
		}

		virtual void h(){
			cout<<"Base2::h()"<<endl;
		}

	private:
		int _base2;
};

class Base3{
	public:
		Base3(int base3=1000) : _base3(base3)
		{
			cout<<"Base3(int)"<<endl;
		}

		virtual void f(){
			cout<<"Base3::f()"<<endl;
		}

		virtual void g(){
			cout<<"Base3::g()"<<endl;
		}

		virtual void h(){
			cout<<"Base3::h()"<<endl;
		}

	private:
		int _base3;
};

class Derived : public Base1,public Base2,public Base3{
	public:
		Derived(int der=10000) : _der(der)
		{
			cout<<"Derived(int)"<<endl;
		}

		void f(){
			cout<<"Derived::f()"<<endl;
		}

		virtual void fd(){
			cout<<"Derived::fd()"<<endl;
		}

	private:
		int _der;
};


int main(void){
	Derived d;
	return 0;
}
