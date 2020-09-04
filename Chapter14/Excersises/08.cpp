// Define a class Octagon to be a regular octagon. Write a test that exercises all of its functions (as defined by you or
// inherited from Shape).

#include "Simple_window.h"
#include "Graph.h"

constexpr double PI = 3.14159;

namespace Graph_lib { // from previous section
	struct Regular_polygon : Closed_polyline {
	public:
		Regular_polygon(Point p, int sides, double distance);
		Regular_polygon();

		// no need for 'draw_lines()' as we use Open_polyline's version 
		Point center() const { return cent; }
		int sides() const { return sid; }
		double distance() const { return dist; }

	protected:
		Point cent;
		int sid; // No of sides
		double dist; // distance from centre to corner
	};

	Regular_polygon::Regular_polygon()
		: cent{ Point{0,0} }, dist{ 0 }, sid{ 0 }
	{
	}

	Regular_polygon::Regular_polygon(Point p, int sides, double distance)
		: cent{ p }, dist{ distance }, sid{ sides }
	{
		if (sid < 3) throw std::runtime_error("sides greater than 2 needed for Regular_polygon");

		double angle = 2 * PI / sid;
		for (int i = 0; i < sid; i++) {
			add(Point{ cent.x + dist * cos(i * angle), cent.y + dist * sin(i * angle) });
		}
	}
	
	struct Octagon : public Regular_polygon {
	public:
		Octagon(Point p, double distance)
		{
			this->cent = p;
			this->dist = distance;
			this->sid = 8;

			double angle = 2.0 * PI / sid;
			for (int i = 0; i < sid; i++) {
				add(Point{ center().x + dist * cos(i * angle), center().y + dist * sin(i * angle) });
			}
		}
	};
}

int main()
try {
    using namespace Graph_lib;

    Simple_window win{ Point{100,0}, 800, 600, "Excersise 8" };

	// constructor
	Octagon o{ Point{400,300,}, 50 };
	o.set_color(Color::black);

	// center access
	cout << o.center().x << "\t" << o.center().y << endl;

	// sides access
	cout << o.sides() << endl;

	// distance access
	cout << o.distance() << endl;

	// fill color
	cout << o.fill_color().as_int() << endl;

	// no of points
	cout << o.number_of_points() << endl;
	
	// color setting
	o.set_color(Color::cyan);
	o.set_fill_color(Color::magenta);

	// style setting
	o.set_style(Line_style::dashdot);

    win.attach(o);
    win.wait_for_button();
    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
