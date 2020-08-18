// Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    // create window area
    Graph_lib::Point ls{100, 100};
    Graph_lib::Simple_window win{ ls, 150, 150, "Excersise 4" };
    
    // create Tic-Tac-Toe Board
    Graph_lib::Rectangle one(Graph_lib::Point{ 0,0 }, 50, 50);
    one.set_fill_color(Graph_lib::Color::white);
    Graph_lib::Rectangle two(Graph_lib::Point{ 50,0 }, 50, 50);
    two.set_fill_color(Graph_lib::Color::red);
    Graph_lib::Rectangle three(Graph_lib::Point{ 100,0 }, 50, 50);
    three.set_fill_color(Graph_lib::Color::white);
    Graph_lib::Rectangle four(Graph_lib::Point{ 0,50 }, 50, 50);
    four.set_fill_color(Graph_lib::Color::red);
    Graph_lib::Rectangle five(Graph_lib::Point{ 50,50 }, 50, 50);
    five.set_fill_color(Graph_lib::Color::white);
    Graph_lib::Rectangle six(Graph_lib::Point{ 100,50 }, 50, 50);
    six.set_fill_color(Graph_lib::Color::red);
    Graph_lib::Rectangle seven(Graph_lib::Point{ 0,100 }, 50, 50);
    seven.set_fill_color(Graph_lib::Color::white);
    Graph_lib::Rectangle eight(Graph_lib::Point{ 50,100 }, 50, 50);
    eight.set_fill_color(Graph_lib::Color::red);
    Graph_lib::Rectangle nine(Graph_lib::Point{ 100,100 }, 50, 50);
    nine.set_fill_color(Graph_lib::Color::white);

    win.attach(one);
    win.attach(two);
    win.attach(three);
    win.attach(four);
    win.attach(five);
    win.attach(six);
    win.attach(seven);
    win.attach(eight);
    win.attach(nine);

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