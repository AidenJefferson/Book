// Define a class Immobile_Circle, which is just like Circle but can’t be moved.

#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib {
    struct Immobile_Circle : public Circle {
    public:
        using Circle::Circle;
        void move(int dx, int dy) { return; }
    };
}

int main()
try {
    using namespace Graph_lib;

    Simple_window win{ Point{100,0}, 800, 600, "Excersise 4" };

    Immobile_Circle c{ Point{100,100}, 100 };
    c.set_color(Color::black);
    Circle c2{ Point{100,100}, 100 };
    c2.set_color(Color::black);

    c.move(100, 100);
    c2.move(100, 100);
    
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
