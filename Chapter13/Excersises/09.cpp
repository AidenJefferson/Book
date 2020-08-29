// Tile a part of a window with Regular_hexagons (use at least eight hexagons).

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

constexpr double PI = 3.14159;

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

		// no need for 'draw_lines()' as we use Open_polyline's version 
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
	Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 9" };

	Graph_lib::Vector_ref<Graph_lib::Regular_hexagon> hex;

	double size{ 50 }; // all hex's are same size


	hex.push_back(new Graph_lib::Regular_hexagon{ Graph_lib::Point{ 400,300 }, size });

	// this for loop will place hexagons around the above centre he 
	int layers{ 3 }; // num of hexagon layers
	double loop{ 0 };
	double offset{ 0 };
	double angle{ 0 };

	for (int i = 0; i < layers; i++) {
		for (int j = 0; j < 6 * i; j++) {
			if (i != 1 && j % i != 0)
				loop = (i * 2 - 1) * size;
			else
				loop = 2 * i * size * cos(PI / 6.0);

			offset = 180.0 / 6.0;
			angle = (offset + j * offset * 2 / i) * PI / 180.0;

			hex.push_back(new Graph_lib::Regular_hexagon{ Graph_lib::Point{ hex[0].center().x + loop * cos(angle),
				hex[0].center().y + loop * sin(angle)}, size });
		}
	}

	int col{ 0 };
	for (int i = 0; i < hex.size(); i++) {
		hex[i].set_fill_color(Graph_lib::Color{ col });
		hex[i].set_color(Graph_lib::Color{ col });
		col = (col == 255)? 0 : (col + 1);
		
		cout << i << endl;

		win.attach(hex[i]);
		win.wait_for_button();
	}

	
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
