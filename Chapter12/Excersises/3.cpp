// Draw your initials 150 pixels high. Use a thick line. Draw each initial in a different color

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    // create window area
    Graph_lib::Point ls{100, 100};
    Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 2" };
    
    // create Initials
    Graph_lib::Text first(Graph_lib::Point{ 50, 200 }, "A");
    Graph_lib::Text last(Graph_lib::Point{ 150, 200 }, "J");
    first.set_color(Graph_lib::Color::green);
    last.set_color(Graph_lib::Color::cyan);
    first.set_font_size(150);
    last.set_font_size(150);
    first.set_style(Graph_lib::Line_style::solid);
    last.set_style(Graph_lib::Line_style::solid);

    win.attach(first);
    win.attach(last);
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