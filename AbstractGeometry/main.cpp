﻿#include<iostream>
#include<Windows.h>
using namespace std;

namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,

		console_red = 0xCC,
		console_green = 0xAA,
		console_blue = 0x99,
		console_default = 0x77
	};

#define SHAPE_TAKE_PARAMETERS int start_x, int start_y, int line_width, Color color
#define SHAPE_GIVE_PARAMETERS start_x, start_y, line_width, color

	class Shape
	{
		static const int MIN_START_X = 10;
		static const int MIN_START_Y = 10;
		static const int MAX_START_X = 500;
		static const int MAX_START_Y = 400;
		static const int MIN_LINE_WIDTH = 5;
		static const int MAX_LINE_WIDTH = 25;
	protected:
		int start_x;
		int start_y;
		int line_width;
		Color color;
	public:
		Shape(int start_x, int start_y, int line_width, Color color) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}

		int get_start_x()const
		{
			return start_x;
		}
		int get_start_y()const
		{
			return start_y;
		}
		int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(int start_x)
		{
			if (start_x < MIN_START_X)start_x = MIN_START_X;
			if (start_x > MAX_START_X)start_x = MAX_START_X;
			this->start_x = start_x;
		}
		void set_start_y(int start_x)
		{
			if (start_y < MIN_START_Y)start_y = MIN_START_Y;
			if (start_y > MAX_START_Y)start_y = MAX_START_Y;
			this->start_y = start_y;
		}
		void set_line_width(int line_width)
		{
			if (line_width < MIN_LINE_WIDTH)line_width = MIN_LINE_WIDTH;
			if (line_width > MAX_LINE_WIDTH)line_width = MAX_LINE_WIDTH;
			this->line_width = line_width;
		}
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "Площадь фигуры" << get_area() << endl;
			cout << "Периметер фигуры" << get_perimeter() << endl;
			draw();
		}
	};

	//*class Square :public Shape
	//{
	//	static const int MIN_SIDE = 2;
	//	static const int MAX_SIDE = 50;
	//	double side;
	//public:
	//	Square(double side, Color color) :Shape(color)
	//	{
	//		set_side(side);
	//	}
	//	~Square() {}
	//	double get_side()const
	//	{
	//		return side;
	//	}
	//	void set_side(double side)
	//	{
	//		if (side < MIN_SIDE)side = MIN_SIDE;
	//		if (side > MAX_SIDE)side = MAX_SIDE;
	//		this->side = side;
	//	}
	//	double get_area()const override
	//	{
	//		return side * side;
	//	}
	//	double get_perimeter()const override
	//	{
	//		return side * 4;
	//	}
	//	void draw()const override
	//	{
	//		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//		SetConsoleTextAttribute(hConsole, color);
	//		for (int i = 0; i < side; i++)
	//		{
	//			for (int j = 0; j < side; j++)
	//			{
	//				cout << "* ";
	//			}
	//			cout << endl;
	//		}
	//		SetConsoleTextAttribute(hConsole, Color::console_default);
	//	}
	//};*/

	/*class Rectangle :public Shape
	{
		static const int MIN_SIDE = 20;
		static const int MAX_SIDE = 500;
		double side_a;
		double side_b;
	public:
		Rectangle(double side_a, double side_b, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_side_a(side_a);
			set_side_b(side_b);
		}
		~Rectangle() {}
		double get_side_a()const
		{
			return side_a;
		}
		double get_side_b()const
		{
			return side_b;
		}
		void set_side_a(double side_a)
		{
			if (side_a < MIN_SIDE)side_a = MIN_SIDE;
			if (side_a > MAX_SIDE)side_a = MAX_SIDE;
			this->side_a = side_a;
		}
		void set_side_b(double side_b)
		{
			if (side_b < MIN_SIDE)side_b = MIN_SIDE;
			if (side_b > MAX_SIDE)side_b = MAX_SIDE;
			this->side_b = side_b;
		}
		double get_area()const override
		{
			return side_a * side_b;
		}
		double get_perimeter()const override
		{
			return (side_a + side_b) * 2;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, start_x, start_y, start_x + side_a, start_y + side_b);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			DeleteObject(hwnd);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Сторона a" << side_a << endl;
			cout << "Сторона b" << side_b << endl;
			Shape::info();
		}
	};
	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
		~Square() {}
	};
}*/

	/*class Triangle :public Shape
	{
		double side_w;
	public:
		Triangle(double side_w, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_side_w(side_w);
		}
		~Triangle() {}
		double get_side_w()const
		{
			return side_w;
		}
		double set_side_w()const
		{
			return side_w;
		}
		void set_side_w(double side_d)
		{
			if (side_w < 50)side_w = 50;
			if (side_w > 100)side_w = 100;
			this->side_w = side_w;
		}
		double get_height()const
		{
			return sqrt(pow(side_w, 2) - pow(side_w / 2, 2));
		}
		double get_area()const
		{
			return side_w * get_side_w() / 2;
		}
		double get_perimeter()const
		{
			return side_w * 3;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);


				::Ellipse(hdc, start_x, start_y, start_x + 2 / side_w, start_y + 2 );

			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
	};
}*/

//class Isosceles :public Shape
//{
//	double median;
//	double bisector;
//public:
//	double get_median()
//	{
//		return median;
//	}
//	double get_bisector()
//	{
//		return bisector;
//	}
//	void set_median()
//	{
//		if (median < 100)median = 100;
//		if (median > 120)median = 120;
//		this->median = median;
//	}
//	void set_median()
//	{
//		if (bisector < 100)bisector = 100;
//		if (bisector > 120)bisector = 120;
//		this->bisector = bisector;
//	}
//	double get_height()const
//	{
//		return sqrt(pow(median, 2) - pow(bisector / 2, 2));
//	}
//	double get_area()const
//	{
//		return median * bisector / 2;
//	}
//	double get_perimeter()const
//	{
//		return median * 2 + bisector;
//	}
//	void draw()const
//	{
//		HWND hwnd = GetConsoleWindow();
//		HDC hdc = GetDC(hwnd);
//		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
//		HBRUSH hBrush = CreateSolidBrush(color);
//
//		SelectObject(hdc, hPen);
//		SelectObject(hdc, hBrush);
//
//
//		::Polygon(hdc, start_x, start_y, start_x + 2 / median, start_y + 2);
//
//		DeleteObject(hPen);
//		DeleteObject(hBrush);
//
//		ReleaseDC(hwnd, hdc);
//	}

	class Circle :public Shape
	{
		double radius;

	public:

		Circle(double radius, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_radius(radius);
		}
		~Circle() {}
		double get_radius()const
		{
			return radius;
		}
		double set_radius()const
		{
			return radius;
		}
		void set_radius(double radius)
		{
			if (radius < 50)radius = 50;
			if (radius > 200)radius = 200;
			this->radius = radius;
		}
		double get_area()const override
		{
			return radius * radius * 3.14;
		}
		double get_perimeter()const override
		{
			return 2 * 3.14 * radius;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Ellipse(hdc, start_x, start_y, start_x + 2 * radius, start_y + 2 * radius);

			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
	};
}

	void main()
{
		setlocale(LC_ALL, "");
		//Shape shape(Color::console_blue);
		/*Geometry::Square square(50, 300, 100, 5, Geometry::Color::console_red);
		square.info();

		Geometry::Rectangle rect(300, 150, 300, 300, 5, Geometry::Color::blue);
		rect.info();
		cout << typeid(typeid(rect)).name() << endl;*/

		/*Geometry::Triangle treg(400, 150, 400, 5, Geometry::Color::green);
		treg.info();
		cout << typeid(typeid(treg)).name() << endl;*/

		/*Geometry::Isosceles iso(50, 100, 120, 50, Geometry::Color::blue);
		iso.info();*/

		Geometry::Circle cir(300, 60, 300,60, Geometry::Color::yellow);
		cir.info();
		cout << typeid(typeid(cir)).name() << endl; 

		
}