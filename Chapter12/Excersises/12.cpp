// A superellipse is a two-dimensional shape defined by the equation:
//
// Look up superellipse on the web to get a better idea of what such shapes look like. Write a program that draws “starlike”
// patterns by connecting points on a superellipse.Take a, b, m, n, and N as arguments. Select N points on the superellipse
// defined by a, b, m, and n.Make the points equally spaced for some definition of “equal.” Connect each of those N
// points to one or more other points(if you like you can make the number of points to which to connect a point another
// argument or just use N–1, i.e., all the other points).

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

    Graph_lib::Closed_polyline star;
    star.add(star_ordered.point(4));
    star.add(star_ordered.point(2));
    star.add(star_ordered.point(0));
    star.add(star_ordered.point(3));
    star.add(star_ordered.point(1));
    star.set_color(Graph_lib::Color::black);

    win.attach(poly);
    win.attach(star);

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