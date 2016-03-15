 ///
 /// @file    sub.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-15 05:10:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base{
	public:
	//两个虚函数，但未形成覆盖
		virtual void func(int x)
		{
			cout<<"Base::func(int) -->"<<x<<endl;
		}
};

class Sub : public Base{
	public:
		virtual void func(float x){
			cout<<"Sub::func(float) -->"<<(int)x<<endl;
		}
};

void test(Base &b){
	b.func(5);
}

int main(void){
	Base base;
	Sub sub;
	test(base);
	test(sub);
	cout<<"--------------------"<<endl;
	sub.func(88); //隐藏了基类的func函数
	cout<<"--------------------"<<endl;
	Base *b = &base;
	b->func(8);
	b = &sub;
	b->func(6);
	return 0;
}
