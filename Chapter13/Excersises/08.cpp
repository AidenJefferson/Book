// Define a class Regular_hexagon(a regular hexagon is a six - sided polygon with all sides of equal length). Use the
// center and the distance from the center to a corner point as constructor arguments

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

constexpr double PI = 3.14;

namespace Graph_lib { // placed here for Github, should go in Graph.cpp/Graph.h
	struct Regular_hexagon : Closed_polyline{
	public:
		Regular_hexagon(Point p, double distance)
			: dist{ distance }, cent{ p }
		{
			add(Point{ cent.x - dist * sin(30.0 / 180 * PI), cent.y - dist * cos(30.0 / 180 * PI) });
			add(Point{ cent.x + dist * sin(30.0 / 180 * PI), cent.y - dist * cos(30.0 / 180 * PI) });
			add(Point{ cent.x + dist, cent.y });
			add(Point{ cent.x + dist * sin(30.0 / 180 * PI), cent.y + dist * cos(30.0 / 180 * PI) });
			add(Point{ cent.x - dist * sin(30.0 / 180 * PI), cent.y + dist * cos(30.0 / 180 * PI) });
			add(Point{ cent.x - dist, cent.y });
		}

		Point center() const { return cent; }
		double distance() const { return dist; }
	
	private:
		Point cent;
		double dist; // distance from centre to corner
	};
}

int main()
try {
	// create window
	Graph_lib::Point ls{ 100,0 };
	Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 8" };

	Graph_lib::Regular_hexagon h{ Graph_lib::Point{100,100}, 50 };
	h.set_color(Graph_lib::Color::black);
	Graph_lib::Mark m{ h.center(), 'x' };
	m.set_color(Graph_lib::Color::black);

	win.attach(h);
	win.attach(m);
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
