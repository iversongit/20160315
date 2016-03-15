 ///
 /// @file    virtual_multi_inherit.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-15 08:51:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A{
	public:
		virtual void a(){
			cout<<"A::a()"<<endl;
		}

		virtual void b(){
			cout<<"A::b()"<<endl;
		}

		virtual void c(){
			cout<<"A::c()"<<endl;
		}

		virtual void d(){
			cout<<"A::d()"<<endl;
		}
};

class B{
	public:
		virtual void a(){
			cout<<"B::a()"<<endl;
		}

		virtual void b(){
			cout<<"B::b()"<<endl;
		}

		void c(){
			cout<<"B::c()"<<endl;
		}

		void d(){
			cout<<"B::d()"<<endl;
		}
};

class C : public A,public B{
	public:
		virtual void a(){
			cout<<"C::a()"<<endl;
		}

		void c(){
			cout<<"C::c()"<<endl;
		}

		void d(){
			cout<<"C::d()"<<endl;
		}
};

int main(){
	C c;
	cout<<"sizeof(c)-->"<<sizeof(c)<<endl;
	cout<<endl;

	A *pa = &c;
	cout<<"pa -->"<<std::hex<<pa<<endl;
	pa->a();
	pa->b();
	pa->c();
	cout<<"---------------------------"<<endl;

	B *pb = &c;
	cout<<"pb -->"<<std::hex<<pb<<endl;
	pb->a();
	pb->b();
	pb->c();
	pb->d();
	cout<<"---------------------------"<<endl;

	C *pc = &c;
	cout<<"pc -->"<<std::hex<<pc<<endl;
	pc->a();
//	pc->b();
	pc->c();
	pc->d();

	return 0;
}
