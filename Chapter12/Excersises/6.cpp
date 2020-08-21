// What happens when you draw a Shape that doesn’t fit inside its window? What happens when you draw a Window
// that doesn’t fit on your screen ? Write two programs that illustrate these two phenomena

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    // create window too large for screen
    Graph_lib::Point ls{100, 100};
    Graph_lib::Simple_window win{ ls, 3000, 2000, "Excersise 6" };

    // create shape too large for window
    Graph_lib::Rectangle rect(Graph_lib::Point{ 0,0 }, 200, 2000);
    rect.set_fill_color(Graph_lib::Color::red);

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