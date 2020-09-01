// Draw the color matrix from §13.10, but without lines around each color.

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
	// create window
	Graph_lib::Point ls{ 100,0 };
	Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 13" };

	Graph_lib::Vector_ref<Graph_lib::Rectangle> colors;

	double size{ 20 }; // colour square size

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			colors.push_back(new Graph_lib::Rectangle{ Graph_lib::Point{i * size, j * size}, size, size });
			colors[colors.size() - 1].set_fill_color(Graph_lib::Color{ i * 16 + j });
		}
	}

	for (int i = 0; i < colors.size(); i++) {
		win.attach(colors[i]);
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
