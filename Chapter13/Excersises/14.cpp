// Define a right triangle class. Make an octagonal shape out of eight right triangles of different colors.

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

constexpr double PI = 3.1459;

namespace Graph_lib {
	struct Right_triangle : Shape {
	public:
		Right_triangle(Point p, int wid, int hei, double a)
			: w{ wid }, h{ hei }, ang{ a / 180 * PI }
		{
			add(p); // point of right angle
		}
		Right_triangle(Point p, int wid, int hei)
			: w{ wid }, h{ hei }, ang{ 0 }
		{
			add(p); // point of right angle
		}

		void draw_lines() const;

		int width() const { return w; }
		int height() const { return h; }
		double angle() const { return ang; }

		void change_width(int wid) { w = wid; }
		void change_height(int hei) { h = hei; }
		void change_angle(double a) { ang = a; }

	private:
		int w;
		int h;
		double ang;
	};

	void Right_triangle::draw_lines() const {
		if (fill_color().visibility())
		{	
			fl_color(fill_color().as_int());
			fl_begin_complex_polygon();
			fl_vertex(point(0).x, point(0).y);
			fl_vertex(point(0).x + w * cos(ang), point(0).y - w * sin(ang));
			fl_vertex(point(0).x - h * sin(ang), point(0).y - h * cos(ang));
			fl_end_complex_polygon();
		}

		if (color().visibility())
		{
			fl_color(color().as_int());
			fl_line(point(0).x, point(0).y, point(0).x + w * cos(ang), point(0).y - w * sin(ang));
			fl_line(point(0).x + w * cos(ang), point(0).y - w * sin(ang), point(0).x - h * sin(ang), point(0).y - h * cos(ang));
			fl_line(point(0).x - h * sin(ang), point(0).y - h * cos(ang), point(0).x, point(0).y);
		}
	}
}

int main()
try {
	// create window
	Graph_lib::Point ls{ 100,0 };
	Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 14" };

	Graph_lib::Vector_ref<Graph_lib::Right_triangle> tri;
	
	int color{ 0 };
	int fill{ 0 };

	for (double i = 0; i < 360; i += 360 / 8) {
		color++;
		fill++;
	
		tri.push_back(new Graph_lib::Right_triangle{ Graph_lib::Point{400,300}, 200, 50, i });
		tri[tri.size()-1].set_color(Graph_lib::Color::black);
		tri[tri.size()-1].set_fill_color(Graph_lib::Color{ color });
	}
	
	std::cout << tri.size();

	for (int i = 0; i < tri.size(); i++) {
		win.attach(tri[i]);
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
