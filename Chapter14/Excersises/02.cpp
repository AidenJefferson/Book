// Try to copy a Shape. What happens?

// This cannot be done as the '=' operator for the shape class is set to 'delete'. To get around this we could create '=' operators for each shape (maybe?)

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
   
    Graph_lib::Simple_window win{ Graph_lib::Point{100,0}, 800,600, "Excersise 1" };

    Graph_lib::Circle c{ Graph_lib::Point{100,100}, 100 };
    Graph_lib::Circle c2{ Graph_lib::Point{400,300}, 200 };

    c = c2;

    win.attach(c);
    win.attach(c2);

    win.wait_for_button();
    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
