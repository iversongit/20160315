 ///
 /// @file    virtual.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-15 07:32:59
 ///

//情况一：单个虚继承，不带虚函数
//虚继承和继承的区别：
//（1）多了一个虚基指针
//（2）虚基类位于派生类存储空间的最末尾
//
//情况二：单个虚继承，带虚函数
//（1）如果派生类没有自己的虚函数，此时
//派生类不会产生虚函数指针
//（2）如果派生类拥有自己的虚函数，此时
//派生类对象就会产生自己本身的虚函数指针
//并且该虚函数指针位于派生类对象存储空间
//的开始位置
#include <iostream>
using std::cout;
using std::endl;

class Base{
	public:
		Base(int x=0) : _x(x)
		{
			cout<<"Base(int)"<<endl;
		}

		virtual 
		void display(){
			cout<<"Base::display()"<<endl;
		}
	private:
		int _x;
};

class Sub : virtual public Base{
	public:
		Sub(int ix) : _ix(ix)
		{
			cout<<"Sub(int)"<<endl;
		}
#if 1	
		virtual void f(){
			cout<<"Sub::f()"<<endl;
		}


		virtual void display(){
			cout<<"Sub::display()"<<endl;
		}

		virtual void fd(){
			cout<<"Sub::fd()"<<endl;
		}
#endif
	private:
		int _ix;
};

int main(void){
	Sub sub(88);
	cout<<"sizeof(Base)-->"<<sizeof(Base)<<endl;
	cout<<"sizeof(Sub)-->"<<sizeof(Sub)<<endl;

	typedef void (*Function)(void);
	int **pvtable = (int **)&sub;
	int pvtableaddr = *(int *)pvtable; //虚函数入口地址
	int pvtablefirstfunctionaddr = *(int *)pvtableaddr; //对应代码区入口地址
	Function pfunc = (Function)pvtablefirstfunctionaddr;
	pfunc();
	return 0;
}
