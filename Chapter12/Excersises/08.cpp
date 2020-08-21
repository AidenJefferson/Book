// Draw the Olympic five rings. If you can’t remember the colors, look them up.


#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    // create window too large for screen
    Graph_lib::Point ls{100, 100};
    Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 8" };

    // create rings
    Graph_lib::Circle ring1(Graph_lib::Point{ 100, 100 }, 100);
    ring1.set_color(Graph_lib::Color::cyan);
    Graph_lib::Circle ring2(Graph_lib::Point{ 225, 225 }, 100);
    ring2.set_color(Graph_lib::Color::yellow);
    Graph_lib::Circle ring3(Graph_lib::Point{ 350, 100 }, 100);
    ring3.set_color(Graph_lib::Color::black);
    Graph_lib::Circle ring4(Graph_lib::Point{ 475, 225 }, 100);
    ring4.set_color(Graph_lib::Color::green);
    Graph_lib::Circle ring5(Graph_lib::Point{ 600, 100 }, 100);
    ring5.set_color(Graph_lib::Color::red);

    win.attach(ring1);
    win.attach(ring2);
    win.attach(ring3);
    win.attach(ring4);
    win.attach(ring5);

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