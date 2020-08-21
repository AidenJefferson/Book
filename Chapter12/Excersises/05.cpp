// Draw a red ¼-inch frame around a rectangle that is three-quarters the height of your screen and two-thirds the width.

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    // create window area
    Graph_lib::Point ls{100, 100};
    Graph_lib::Simple_window win{ ls, 1366, 768, "Excersise 5" };

    // create frame
    Graph_lib::Rectangle frame(Graph_lib::Point{ 0,0 }, 1366, 768);
    frame.set_fill_color(Graph_lib::Color::red);

    // create reactangle
    int width = 1366 * 2 / 3;   // truncation of double to int is ok
    int height = 768 * 0.75;    // truncation of double to int is ok
    Graph_lib::Rectangle rect(Graph_lib::Point{ (1366 - width) / 2,(768 - height) / 2 }, width, height);
    rect.set_fill_color(Graph_lib::Color::white);

    win.attach(frame);
    win.attach(rect);

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