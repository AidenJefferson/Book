//  Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the Polygon red and the lines of the Rectangle
//  blue.

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    // create window area
    Graph_lib::Point ls{100, 100};
    Graph_lib::Simple_window win{ ls, 750, 200, "Excersise 1" };
    
    // create Reactangle
    Graph_lib::Rectangle rect(Graph_lib::Point{ 50,50 }, 300, 100);
    rect.set_color(Graph_lib::Color::blue);
    win.attach(rect);

    // create Polygon
    Graph_lib::Polygon poly;
    poly.add(Graph_lib::Point(400, 50));
    poly.add(Graph_lib::Point(700, 50));
    poly.add(Graph_lib::Point(700, 150));
    poly.add(Graph_lib::Point(400, 150));
    poly.set_color(Graph_lib::Color::red);
    win.attach(poly);

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