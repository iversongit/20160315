 ///
 /// @file    abstract.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-15 04:47:35
 ///

#include <memory>
#include <iostream>
using std::cout;
using std::endl;

class A{
	public:
		//抽象类 --> 不能创建对象
		virtual void display() = 0;
};

class B : public A{
	public:
		B(){
			cout<<"B()"<<endl;
		}

		void display(){
			cout<<"B::display()"<<endl;
		}

		~B(){
			cout<<"~B()"<<endl;
		}
};

class C : public B{
	public:
		C(){
			cout<<"C()"<<endl;
		}

		void display(){
			cout<<"C::display()"<<endl;
		}

		~C(){
			cout<<"~C()"<<endl;
		}
};

void test(A *pa){
	pa->display();
}

int main(void){
	std::unique_ptr<B> b(new B);
	std::unique_ptr<C> c(new C);
	test(b.get());
	test(c.get());
	cout<<"-----------------"<<endl;
	A *pa = NULL;
	pa = &(*b);
	pa->display();
	pa = &(*c);
	pa->display();
	return 0;
}
