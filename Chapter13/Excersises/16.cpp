// “Tile” a window with small right triangles

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

constexpr double PI = 3.1459;

namespace Graph_lib { // placed here for Github, should go in Graph.cpp/Graph.h
	struct Regular_hexagon : Closed_polyline {
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
	Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 16" };

	Graph_lib::Vector_ref<Graph_lib::Regular_hexagon> hex;
	
	double width{ 57.735027 };
	int color{ 56 };

	int dist_to_below = 2* width * cos(30 / 180.0 * PI);

	for (double i = 0; i < 800; i += width*3 ) {
		for (int j = 0; j < 600; j += dist_to_below) {
			hex.push_back(new Graph_lib::Regular_hexagon{ Graph_lib::Point{i, j*1.0}, width }); // 1.0 required as I set Point to take double
			hex[hex.size() - 1].set_color(Graph_lib::Color{ color });
			color++;
			hex.push_back(new Graph_lib::Regular_hexagon{ Graph_lib::Point{i + width * 1.5, j * 1.0 + 0.5 * dist_to_below }, width }); // 1.0 required as I set Point to take double
			hex[hex.size() - 1].set_color(Graph_lib::Color{ color });
			color++;
		}
	}

	for (int i = 0; i < hex.size(); i++) {
		win.attach(hex[i]);
	}

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
