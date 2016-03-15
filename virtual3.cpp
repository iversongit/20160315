 ///
 /// @file    vitual2.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-15 08:12:59
 ///
 
#include <iostream>
using std::endl;
using std::cout;

//情况四：钻石型虚继承
//虚基指针所指向的虚基表的内容：
//（1）虚基指针的第一条内容表示的是该虚基指针距离
//所在的子对象的首地址的偏移
//（2）虚基指针的第二条内容表示的是该虚基指针距离
//虚基类子对象的首地址的偏移
//
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

class Base2 : virtual public Base1{
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

		virtual void ha(){
			cout<<"Base2::ha()"<<endl;
		}

	private:
		int _base2;
};

class Base3 : virtual public Base1{
	public:
		Base3(int base3=1000) : _base3(base3)
		{
			cout<<"Base3(int)"<<endl;
		}

		virtual void f(){
			cout<<"Base3::f()"<<endl;
		}

		virtual void hb(){
			cout<<"Base3::hb()"<<endl;
		}

	private:
		int _base3;
};

class Derived : public Base2,public Base3{
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
