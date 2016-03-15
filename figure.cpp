 ///
 /// @file    figure.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-15 03:50:41
 ///

#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

const float PI = 3.14159;

class Figure{
	public:
		virtual float area() = 0;
		virtual void display() = 0;
};

//对于抽象类的派生类，如果有一个纯虚函数
//没有实现，那么派生类也会变成一个抽象类
class Circle : public Figure
{
	public:
		Circle(float radius)
		:_radius(radius)
		{
			cout<<"Circle(float)"<<endl;
		}

		float area(){
			return PI * _radius * _radius;
		}

		void display(){
			cout<<"Circle: ";
		}

	private:
		float _radius;
};

class Rectangle : public Figure
{
	public:
		Rectangle(float x,float y)
		:_x(x)
		,_y(y)
		{
			cout<<"Rectangle(float,float)"<<endl;
		}

		float area(){
			return _x * _y;
		}

		void display(){
			cout<<"Rectangle: ";
		}
	private:
		float _x;
		float _y;
};

class Triangle : public Figure
{
	public:
		Triangle(float x,float y, float z)
		:_ix(x)
		,_iy(y)
		,_iz(z)
		{
			cout<<"Triangle(float,float,float)"<<endl;
		}

		float area(){
			float p = (_ix + _iy + _iz) / 2;
			return sqrt(p * (p-_ix) * (p-_iy) * (p-_iz));
		}

		void display(){
			cout<<"Triangle: ";
		}

	private:
		float _ix;
		float _iy;
		float _iz;
};

void print(Figure *pf){
	pf->display();
	cout<<pf->area()<<endl;
}

int main(void){
	Circle circle(2.0);
	Rectangle rect(6.0,8.0);
	Triangle tri(6.0,6.0,6.0);

	print(&circle);
	print(&rect);
	print(&tri);

	return 0;
}
