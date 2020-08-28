// Define functions n(), s(), e(), w(), center(), ne(), se(), sw(), and nw().Each takes a Rectangle argumentand returns
// a Point.These functions define “connection points” onand in the rectangle.For example, nw(r) is the northwest(top-left) 
// corner of a Rectangle called r.

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

namespace Graph_lib { // should be placed inside Graph.cpp, only here for github
    Point n(const Rectangle &r) {
        return Point{ r.point(0).x + r.width() / 2, r.point(0).y };
    }

    Point e(const Rectangle &r) {
        return Point{ r.point(0).x + r.width(), r.point(0).y + r.height() / 2 };
    }

    Point s(const Rectangle &r) {
        return Point{ r.point(0).x + r.width() / 2, r.point(0).y + r.height() };
    }

    Point w(const Rectangle &r) {
        return Point{ r.point(0).x, r.point(0).y + r.height() / 2 };
    }

    Point center(const Rectangle& r) {
        return Point{ r.point(0).x + r.width() / 2, r.point(0).y + r.height() / 2 };
    }

    Point ne(const Rectangle &r) {
        return Point{ r.point(0).x + r.width(), r.point(0).y };
    }

    Point se(const Rectangle &r) {
        return Point{ r.point(0).x + r.width(), r.point(0).y + r.height() };
    }

    Point sw(const Rectangle &r) {
        return Point{ r.point(0).x, r.point(0).y + r.height() };
    }

    Point nw(const Rectangle &r) {
        return r.point(0);
    }

}

int main()
try {
    // create window
    Graph_lib::Point ls{ 100,0 };
    Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 4" };

    // testing co-ordinates
    Graph_lib::Rectangle r{ Graph_lib::Point{100,100}, 300, 100 };
    r.set_color(Graph_lib::Color::black);
    win.attach(r);

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
