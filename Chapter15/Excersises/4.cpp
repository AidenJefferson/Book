// Graph a sine(sin()), a cosine(cos()), the sum of those(sin(x) + cos(x)), and the sum of the squares of those
// (sin(x)* sin(x) + cos(x) * cos(x)) on a single graph. Do provide axes and labels.

#include "Graph.h"
#include "Simple_window.h"
#include <cmath>

constexpr int win_size = 600;
constexpr int axis_length = 400;
constexpr int notch_num = 400 / 20;
constexpr int center_x = 300;
constexpr int center_y = 300;
constexpr int n_points = 400;
constexpr int xy_scale = 20;

double sum(double x) { return sin(x) + cos(x); }
double sum_square(double x) { return sin(x)*sin(x) + cos(x)*cos(x); }

int main()
try {
    Graph_lib::Simple_window win{ Graph_lib::Point{100,0}, win_size, win_size, "Excersise 4" };

    Graph_lib::Axis x{ Graph_lib::Axis::Orientation::x, Graph_lib::Point{center_x,center_y}, axis_length, notch_num, "1 == 20 pixels" };
    x.move(-axis_length / 2, 0);
    x.set_color(Graph_lib::Color::red);
    x.label.move(axis_length / 2, 0);
    Graph_lib::Axis y{ Graph_lib::Axis::Orientation::y, Graph_lib::Point{center_x,center_y}, axis_length, notch_num, "1 == 20 pixels" };
    y.move(0, axis_length / 2);
    y.set_color(Graph_lib::Color::red);

    // sin
    Graph_lib::Function Sin{ sin, -10, 11, Graph_lib::Point{center_x, center_y}, n_points, xy_scale, xy_scale };
    Sin.set_color(Graph_lib::Color::black);
    Graph_lib::Text Sin_label{ Graph_lib::Point{100, 120 }, "sin" };
    Sin_label.set_color(Graph_lib::Color::black);

    // cos
    Graph_lib::Function Cos{ cos, -10, 11, Graph_lib::Point{center_x, center_y}, n_points, xy_scale, xy_scale };
    Cos.set_color(Graph_lib::Color::blue);
    Graph_lib::Text Cos_label{ Graph_lib::Point{100, 140 }, "cos" };
    Cos_label.set_color(Graph_lib::Color::blue);
    
    // sum
    Graph_lib::Function Sum{ sum, -10, 11, Graph_lib::Point{center_x, center_y}, n_points, xy_scale, xy_scale };
    Sum.set_color(Graph_lib::Color::green);
    Graph_lib::Text Sum_label{ Graph_lib::Point{100, 160 }, "cos + sin" };
    Sum_label.set_color(Graph_lib::Color::green);

    // sum
    Graph_lib::Function Sum_square{ sum_square, -10, 11, Graph_lib::Point{center_x, center_y}, n_points, xy_scale, xy_scale };
    Sum_square.set_color(Graph_lib::Color::dark_yellow);
    Graph_lib::Text Sum_square_label{ Graph_lib::Point{100, 180 }, "cos^2 + sin^2" };
    Sum_square_label.set_color(Graph_lib::Color::dark_yellow);

    win.attach(x);
    win.attach(y);
    win.attach(Sin);
    win.attach(Sin_label);
    win.attach(Cos);
    win.attach(Cos_label);
    win.attach(Sum);
    win.attach(Sum_label);
    win.attach(Sum_square);
    win.attach(Sum_square_label);
 
    win.wait_for_button();

    return 0;
}
catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}