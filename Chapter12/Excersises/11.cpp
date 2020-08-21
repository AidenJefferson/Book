// Draw a series of regular polygons, one inside the other. The innermost should be an equilateral triangle, enclosed by a
// square, enclosed by a pentagon, etc.For the mathematically adept only : let all the points of each N - polygon touch sides
// of the(N + 1) - polygon.Hint : The trigonometric functions are found in <cmath>(§24.8, §B.9.2).

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

constexpr double PI = 3.14159;

Graph_lib::Polygon create_poly(int N, int radius) {
    double circ = 2 * PI * radius;
    double spacing = circ / N;
    double angle = spacing / circ * 2 * PI;

    Graph_lib::Polygon poly;

    for (int i = 0; i < N; i++) {
        int x = radius * cos(i*angle) + 400;
        int y = radius * sin(i*angle) + 300;
        poly.add(Graph_lib::Point{ x,y });
    }

    poly.set_color(Graph_lib::Color::black);
    return poly;
}

int main()
try {
    // create window too large for screen
    Graph_lib::Point ls{ 100, 100 };
    Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 11" };

    int radius = 0;
    vector<Graph_lib::Polygon> polys;

    // create polygons
    for (int i = 3; i < 20; i++) {
        radius = radius + 20;
        Graph_lib::Polygon p = create_poly(i, radius);
        polys.push_back(p);
    }
    
    for (int i = 0; i < 16; i++) {
        win.attach(polys[i]);
    }

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