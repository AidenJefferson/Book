// Define the functions from exercise 4 for a Circleand an Ellipse.Place the connection points on or outside the shape but
// not outside the bounding rectangle.


#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib { // should be placed inside Graph.h, only here for github
    
	Point n(const Circle& c) {
		return Point{ c.point(0).x + c.radius(), c.point(0).y };
	}

	Point e(const Circle& c) {
		return Point{ c.point(0).x + c.radius() * 2, c.point(0).y + c.radius() };
	}

	Point s(const Circle& c) {
		return Point{ c.point(0).x + c.radius(), c.point(0).y + c.radius() * 2 };
	}

	Point w(const Circle& c) {
		return Point{ c.point(0).x, c.point(0).y + c.radius() };
	}

	Point center(const Circle& c) {
		return Point{ c.point(0).x + c.radius(), c.point(0).y + c.radius() };
	}

	Point ne(const Circle& c) {
		return Point{ c.point(0).x + c.radius() * 2, c.point(0).y };
	}

	Point se(const Circle& c) {
		return Point{ c.point(0).x + c.radius() * 2, c.point(0).y + c.radius() * 2 };
	}

	Point sw(const Circle& c) {
		return Point{ c.point(0).x, c.point(0).y + c.radius() * 2 };
	}

	Point nw(const Circle& c) {
		return c.point(0);
	}

}

int main()
try {
	// create window
	Graph_lib::Point ls{ 100,0 };
	Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 5" };

	// testing co-ordinates
	Graph_lib::Rectangle c{ Graph_lib::Point{300,300}, 300, 100 };
	c.set_color(Graph_lib::Color::black);
	win.attach(c);

	Graph_lib::Line l1{ Graph_lib::n(c), Graph_lib::s(c) };
	Graph_lib::Line l2{ Graph_lib::e(c), Graph_lib::w(c) };
	Graph_lib::Line l3{ Graph_lib::ne(c), Graph_lib::sw(c) };
	Graph_lib::Line l4{ Graph_lib::nw(c), Graph_lib::se(c) };
	win.attach(l1);
	win.attach(l2);
	win.attach(l3);
	win.attach(l4);

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
