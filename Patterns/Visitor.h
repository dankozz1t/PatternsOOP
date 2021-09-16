#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace visitor
{
	class Visitor;
	
	class Prototype
	{
	public:
		virtual void print() const = 0;
		virtual void accept(Visitor * v) = 0;
	};

	class _Rectangle : public Prototype
	{
		public:
		
		int width, height;


		_Rectangle(int w, int h) : width(w), height(h) {}

		void print() const override
		{
			cout << "W = " << width << "\nH = " << height << endl;
		}

		void accept(Visitor* v) override;

	};


	class _Circle : public  Prototype
	{
		public:
		
		int radius;

		_Circle(int r) : radius(r) {}

		void print() const override
		{
			cout << "R = " << radius << endl;
		}


		void accept(Visitor* v) override;
	};


	class Visitor
	{
	public:
		virtual void visit(_Circle *c) =0;
		virtual void visit(_Rectangle *r) = 0;
	};

	class HTML_Export: public Visitor
	{
		string fName;
	public:
		HTML_Export(string n) :fName(n){}
		
		void visit(_Circle* c) override
		{
			string result = "<html> \n      <head> \n		<title>Ультра Фигуры</title>\n	    </head> \n	    <body> \n	        <p> Круг, Радиус = ";
			result += to_string(c->radius);
			result += "</p> \n		 </body> \n	</html>";
			ofstream out(fName, ios::app);
			out << result << endl;
			out.close();

		}
		
		void visit(_Rectangle* r) override
		{
			string result = "<html> \n      <head> \n		<title>Ультра Фигуры</title>\n	    </head> \n	    <body> \n	        <p> Прямоугольник: H =";
			result += to_string(r->height);
			result += ", W = ";
			result += to_string(r->width);
			result += "</p> \n		 </body> \n	</html>";
			ofstream out(fName, ios::app);
			out << result << endl;
			out.close();
		}
		
	};


	class TXT_Export : public Visitor
	{
		string fName;
	public:
		TXT_Export(string n) :fName(n) {}

		void visit(_Circle* c) override
		{
			string result = "Круг, РАДИУС: ";
			result += to_string(c->radius);
			result += "\n";
			ofstream out(fName, ios::app);
			out << result << endl;
			out.close();

		}

		void visit(_Rectangle* r) override
		{
			string result = "Прямоугольник: H =";
			result += to_string(r->height);
			result += ", W = ";
			result += to_string(r->width);
			result += "\n";
			ofstream out(fName, ios::app);
			out << result << endl;
			out.close();
		}

	};
	
	void _Rectangle::accept(Visitor* v)
	{
		v->visit(this);
	}

	void _Circle::accept(Visitor* v)
	{
		v->visit(this);
	}

	
}

//using namespace visitor;
//int main()
//{
//	goToRush();
//
//	Prototype* arr[] = { new _Circle(15), new _Rectangle(12,45), new _Circle(34) };
//
//	for (auto a : arr)
//		a->print();
//
//	Visitor* visitor = new HTML_Export("index.html");
//	for (auto a : arr)
//		a->accept(visitor);
//	
//	Visitor* visitort = new TXT_Export("figure.txt");
//	for (auto a : arr)
//		a->accept(visitort);
//	
//	return 0;
//}