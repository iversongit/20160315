 ///
 /// @file    protected.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-15 04:33:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base{
	public:
		void display(){
			cout<<"_x --> "<<_x<<endl;
		}

	protected: //这是另一种形式的抽象类
		Base(int x) : _x(x)
		{
			cout<<"Base(int)"<<endl;
		}

	private:
		int _x;
};

class Child : public Base{
	public:
	Child(int ix)
	:Base(ix)
	{
		cout<<"Child(int)"<<endl;
	}
};

int main(void){
//无法直接创建Base的实例，只能通过派生类去创建实例
	Child c(99); 
	c.display();
	return 0;
}
