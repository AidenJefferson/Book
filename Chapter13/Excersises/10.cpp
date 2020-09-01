// Define a class Regular_polygon. Use the center, the number of sides(> 2), and the distance from the center to a corner
// as constructor argument

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

constexpr double PI = 3.14159;

namespace Graph_lib { // placed here for Github, should go in Graph.cpp/Graph.h
	struct Regular_polygon : Closed_polyline {
	public:
		Regular_polygon(Point p, int sides, double distance);

		// no need for 'draw_lines()' as we use Open_polyline's version 
		Point center() const { return cent; }
		int sides() const { return sid; }
		double distance() const { return dist; }
	
	private:
		Point cent;
		int sid; // No of sides
		double dist; // distance from centre to corner
	};

	Regular_polygon::Regular_polygon(Point p, int sides, double distance)
		: cent{ p }, dist{ distance }, sid{ sides }
	{
		if (sid < 3) throw std::runtime_error("sides greater than 2 needed for Regular_polygon");

		double angle = 2 * PI / sid;
		for (int i = 0; i < sid; i++) {
			add(Point{ cent.x + dist * cos(i * angle), cent.y + dist * sin(i * angle) });
		}
	}
}

int main()
try {
	// create window
	Graph_lib::Point ls{ 100,0 };
	Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 10" };

	Graph_lib::Regular_polygon p{ Graph_lib::Point{100,100}, 4, 50 };
	p.set_color(Graph_lib::Color::black);
	
	win.attach(p);
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
