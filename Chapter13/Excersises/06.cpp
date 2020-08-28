// Write a program that draws a class diagram like the one in §12.6.It will simplify matters if you start by defining a Box
// class that is a rectangle with a text label

#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib { // should be placed inside Graph.h & Graph.cpp, only here for github (also had to overload '=' for Box class from previous excercise, and from Bjarnes Text class.)

	struct Diagram_Box : Shape {
	public:
		Diagram_Box(Point p, int ww, int hh, int c_r, string s)
		{
			b = Box{ p,ww,hh,c_r };
			t = Text{ Point{p.x + 5, p.y + 15}, s };
		}

		void draw_lines() const;
		void set_color(Color c);

	private:
		Box b;
		Text t{ Point{0,0}, "empty" };
	};

	void Diagram_Box::draw_lines() const {
		b.draw_lines();
		t.draw_lines();
	}

	void Diagram_Box::set_color(Color c)
	{
		Shape::set_color(c);
		b.set_color(c);
		t.set_color(c);
	}
}

int main()
try {
	// create window
	Graph_lib::Point ls{ 100,0 };
	Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 6" };

	// testing diagram
	Graph_lib::Diagram_Box b{ Graph_lib::Point{200,200}, 100, 20, 4, "Test Box" };
	b.set_color(Graph_lib::Color::black);
	win.attach(b);
	
	win.wait_for_button();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
