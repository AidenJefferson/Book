// Find a way to add color to the lines from the previous exercise. Make some lines one color and other lines another color
// or other colors.


#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

constexpr double PI = 3.14519;

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

Graph_lib::Closed_polyline superelipse(double a, double b, double n) {
    Graph_lib::Closed_polyline poly;
    Graph_lib::Point p;
   
    for (double i = 0; i < 2 * PI; i += 0.1) {
        p.x = pow(abs(cos(i)), 2 / n) * a*sgn(cos(i)) + 400;
        p.y = pow(abs(sin(i)), 2 / n) * b*sgn(sin(i)) + 300;

        poly.add(p);
    }

    poly.set_color(Graph_lib::Color::black);
    return poly;
}

int main()
try {
    // create window too large for screen
    Graph_lib::Point ls{ 100, 100 };
    Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 11" };

    // create super elipse
    Graph_lib::Closed_polyline poly = superelipse(200, 300, 2);

    // create lines
    int N = poly.number_of_points() / 4;

    Graph_lib::Closed_polyline star_ordered;
    star_ordered.set_color(Graph_lib::Color::black);
    for (int i = 0; i < poly.number_of_points(); i+=N) {
            star_ordered.add(poly.point(i));
    }

    Graph_lib::Line line1{ star_ordered.point(4), star_ordered.point(2) };
    line1.set_color(Graph_lib::Color::red);
    Graph_lib::Line line2{ star_ordered.point(2), star_ordered.point(0) };
    line2.set_color(Graph_lib::Color::blue);
    Graph_lib::Line line3{ star_ordered.point(0), star_ordered.point(3) };
    line3.set_color(Graph_lib::Color::green);
    Graph_lib::Line line4{ star_ordered.point(3), star_ordered.point(1) };
    line4.set_color(Graph_lib::Color::yellow);
    Graph_lib::Line line5{ star_ordered.point(1), star_ordered.point(4) };
    line5.set_color(Graph_lib::Color::magenta);

    win.attach(poly);
    win.attach(line1);
    win.attach(line2);
    win.attach(line3);
    win.attach(line4);
    win.attach(line5);

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