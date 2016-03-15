 ///
 /// @file    virtualdestructor.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-15 05:21:53
 ///
 
#include <iostream>
using std::cout;
using std::endl;

const int NUM = 64;

class Base{
	public:
		Base()
		:_pstr(new char[NUM])
		{
			cout<<"Base()"<<endl;
		}

		virtual void display()
		{
		
		}

        virtual ~Base(){
			cout<<"~Base()"<<endl;
			delete[] _pstr;
		}
	
	private:
		char *_pstr;
};

class Sub : public Base{
	public:
		Sub()
		:Base()
		,_pcstr(new char[NUM])
		{
			cout<<"Sub()"<<endl;
		}

		void display()
		{
		
		}

		~Sub(){
			cout<<"~Sub()"<<endl;
			delete[] _pcstr;
		}
	private:
		char *_pcstr;
};

int main(void){
//Sub sub;
#if 1
//如果对基类的析构函数不加virtual
//此时，进行对象的销毁时，不会执行
//派生类的析构函数，就会造成内存泄漏
    Base *pbase = new Sub;
	delete pbase;
#endif
	return 0;
}
