// “Tile” a window with small right triangles

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
	
	int width{ 200 };
	int height{ 60 };
	int color{ 50 };
	int fill{ 50 };

	int w_offset = 800 / width;
	int h_offset = 600 / height;

	for (int i = 0; i < 800; i += width ) {
		for (int j = 0; j < 600; j += height) {
			tri.push_back(new Graph_lib::Right_triangle{ Graph_lib::Point{i * 1.0,j * 1.0 + height}, width, height }); // 1.0 required as I set Point to take double
			tri[tri.size() - 1].set_color(Graph_lib::Color{ color });
			tri[tri.size() - 1].set_fill_color(Graph_lib::Color{ fill });
			color++;
			fill++;
			tri.push_back(new Graph_lib::Right_triangle{ Graph_lib::Point{i * 1.0 + width,j * 1.0}, width, height, 180 }); // 1.0 required as I set Point to take double
			tri[tri.size() - 1].set_color(Graph_lib::Color{ color });
			tri[tri.size() - 1].set_fill_color(Graph_lib::Color{ fill });
			color++;
			fill++;
		}
	}

	for (int i = 0; i < tri.size(); i++) {
		win.attach(tri[i]);
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
