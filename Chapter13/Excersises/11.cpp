// Draw a 300-by-200-pixel ellipse. Draw a 400-pixel-long x axis and a 300-pixel-long y axis through the center of the
// ellipse. Mark the foci. Mark a point on the ellipse that is not on one of the axes. Draw the two lines from the foci to the
// point.

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

constexpr double PI = 3.14159;

int main()
try {
	// create window
	Graph_lib::Point ls{ 100,0 };
	Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 11" };

	// create ellipse
	Graph_lib::Point center{ 400,300 };
	Graph_lib::Ellipse e{ center,300,200 };
	e.set_color(Graph_lib::Color::black);

	// create axis
	Graph_lib::Axis x{ Graph_lib::Axis::Orientation::x, Graph_lib::Point{200,300}, 400, 20, " " };
	x.set_color(Graph_lib::Color::black);
	Graph_lib::Axis y{ Graph_lib::Axis::Orientation::y, Graph_lib::Point{400,450}, 300, 20, " " };
	y.set_color(Graph_lib::Color::black);

	// create marks
	Graph_lib::Mark foci{ center, 'X' };
	Graph_lib::Mark outlier{ Graph_lib::Point{center.x + 300 * cos(65 / 180.0 * PI), center.y + 200 * sin(65 / 180.0 * PI)}, 'X' };
	
	// create line
	Graph_lib::Line l{ center,outlier.point(0) };
	l.set_color(Graph_lib::Color::red);

	win.attach(e);
	win.attach(x);
	win.attach(y);
	win.attach(foci);
	win.attach(outlier);
	win.attach(l);

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
