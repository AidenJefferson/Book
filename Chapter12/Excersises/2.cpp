// Draw a 100-by-30 Rectangle and place the text “Howdy!” inside it

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    // create window area
    Graph_lib::Point ls{100, 100};
    Graph_lib::Simple_window win{ ls, 200, 100, "Excersise 1" };
    
    // create Reactangle
    Graph_lib::Rectangle rect(Graph_lib::Point{ 20,20 }, 100, 30);
    rect.set_color(Graph_lib::Color::blue);
    win.attach(rect);

    // create Text
    Graph_lib::Text t(Graph_lib::Point{ 50, 40 }, "Howdy!");
    t.set_color(Graph_lib::Color::black);
    win.attach(t);

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