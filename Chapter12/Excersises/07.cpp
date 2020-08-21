// Draw a two-dimensional house seen from the front, the way a child would: with a door, two windows, and a roof with a
// chimney.Feel free to add details; maybe have “smoke” come out of the chimney.

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    // create window too large for screen
    Graph_lib::Point ls{100, 100};
    Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 7" };

    // create house
    Graph_lib::Rectangle house(Graph_lib::Point{ 50,50 }, 700, 500);
    house.set_color(Graph_lib::Color::black);
    Graph_lib::Rectangle door(Graph_lib::Point{ 325,250 }, 150, 300);
    door.set_color(Graph_lib::Color::black);
    Graph_lib::Rectangle window_l(Graph_lib::Point{ 88+50,250 }, 100, 100);
    window_l.set_color(Graph_lib::Color::black);
    Graph_lib::Rectangle window_r(Graph_lib::Point{ 700-88-50,250 }, 100, 100);
    window_r.set_color(Graph_lib::Color::black);

    win.attach(house);
    win.attach(door);
    win.attach(window_l);
    win.attach(window_r);

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