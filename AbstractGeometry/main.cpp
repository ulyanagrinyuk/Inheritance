#include<iostream>

using std::cout;
using std::cin;
using std::endl


enum Color
{
	console_red = 0xCC, 
	console_green = 0xAA,
	console_blue = 0x99,
	console_default = 0x77	
};

class Shape
{
	Color color;
public:
	Shape(Color color) :color(color) {}
	virtual ~Shape() {};
	virtual double area()const = 0;
	virtual double perimeter()const = 0;
	virtual void draw()const = 0;
};

class Square :public Shape
{
	static const int MIN_SIDE = 2;
	static const int MAX_SIDE = 50;
	double side;
public:
	Square(double side, Color color) :Shape(color)
	{
		return side(side);
	}
	~Square()
	{

	}
	double get_side()const
	{
		return side;
	}
	double set_side(double side)
	{
		if (side < MIN_SIDE)side = MIN_SIDE;
		if (side > MAX_SIDE)side = MAX_SIDE;
		this->side = side;
	}
	double get_area()const override
	{
		return side * side;
	}
	double get_perimeter()const override
	{
		return side * 4;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::console_blue);
	Square square(5, Color::console_red);
}