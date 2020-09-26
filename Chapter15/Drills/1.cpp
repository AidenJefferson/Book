// Function graphing drill :
//      1.  Make an empty 600 - by - 600 Window labeled “Function graphs.”
//      2.  Note that you’ll need to make a project with the properties specified in the “installation of FLTK” note from the course
//          website.
//      3.  You’ll need to move Graph.cpp and Window.cpp into your project.
//      4.  Add an x axis and a y axis each of length 400, labeled “1 = = 20 pixels” and with a notch every 20 pixels.The axes
//          should cross at(300, 300).
//      5.  Make both axes red.
//
// In the following, use a separate Shape for each function to be graphed :
//      1.  Graph the function double one(double x) { return 1; } in the range[–10, 11] with(0, 0) at(300, 300) using 400 points
//          and no scaling(in the window).
//      2.  Change it to use x scale 20 and y scale 20.
//      3.  From now on use that range, scale, etc. for all graphs.
//      4.  Add double slope(double x) { return x / 2; } to the window.
//      5.  Label the slope with a Text "x/2" at a point just above its bottom left end point.
//      6.  Add double square(double x) { return x * x; } to the window.
//      7.  Add a cosine to the window(don’t write a new function).
//      8.  Make the cosine blue.
//      9.  Write a function sloping_cos() that adds a cosine to slope() (as defined above) and add it to the window.
//

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

constexpr int win_size = 600;
constexpr int axis_length = 400;
constexpr int notch_num = 400 / 20;
constexpr int center_x = 300;
constexpr int center_y = 300;
constexpr int n_points = 400;
constexpr int xy_scale = 20;

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
try {
    Graph_lib::Simple_window win{ Graph_lib::Point{100,0}, win_size, win_size, "Function Graphs" };

    Graph_lib::Axis x{ Graph_lib::Axis::Orientation::x, Graph_lib::Point{center_x,center_y}, axis_length, notch_num, "1 == 20 pixels" };
    x.move(-axis_length / 2, 0);
    x.set_color(Graph_lib::Color::red);
    x.label.move(axis_length / 2, 0);
    Graph_lib::Axis y{ Graph_lib::Axis::Orientation::y, Graph_lib::Point{center_x,center_y}, axis_length, notch_num, "1 == 20 pixels" };
    y.move(0, axis_length / 2);
    y.set_color(Graph_lib::Color::red);

    // one
    Graph_lib::Function One{ one, -10, 11, Graph_lib::Point{center_x, center_y}, n_points, xy_scale, xy_scale };
    One.set_color(Graph_lib::Color::black);
    Graph_lib::Text One_label{ Graph_lib::Point{One.point(0).x, One.point(0).y - 5 }, "one" };
    One_label.set_color(Graph_lib::Color::black);

    // slope
    Graph_lib::Function Slope{ slope, -10, 11, Graph_lib::Point{center_x, center_y}, n_points, xy_scale, xy_scale };
    Slope.set_color(Graph_lib::Color::black);
    Graph_lib::Text Slope_label{ Graph_lib::Point{Slope.point(0).x - 5, Slope.point(0).y - 5 }, "x/2" };
    Slope_label.set_color(Graph_lib::Color::black);

    // square
    Graph_lib::Function Square{ square, -10, 11, Graph_lib::Point{center_x, center_y}, n_points, xy_scale, xy_scale };
    Square.set_color(Graph_lib::Color::black);
    Graph_lib::Text Square_label{ Graph_lib::Point{center_x + 5, center_y + 10 }, "x^2" };
    Square_label.set_color(Graph_lib::Color::black);

    // cos
    Graph_lib::Function Cos{ cos, -10, 11, Graph_lib::Point{center_x, center_y}, n_points, xy_scale, xy_scale };
    Cos.set_color(Graph_lib::Color::blue);
    Graph_lib::Text Cos_label{ Graph_lib::Point{Cos.point(0).x - 5, Cos.point(0).y - 5 }, "cos" };
    Cos_label.set_color(Graph_lib::Color::blue);

    // sloping_cos
    Graph_lib::Function Sloping_cos{ sloping_cos, -10, 11, Graph_lib::Point{center_x, center_y}, n_points, xy_scale, xy_scale };
    Sloping_cos.set_color(Graph_lib::Color::dark_green);
    Graph_lib::Text Sloping_cos_label{ Graph_lib::Point{Sloping_cos.point(0).x - 30, Sloping_cos.point(0).y + 15 }, "sloping cos" };
    Sloping_cos_label.set_color(Graph_lib::Color::dark_green);

    win.attach(x);
    win.attach(y);
    win.attach(One);
    win.attach(One_label);
    win.attach(Slope);
    win.attach(Slope_label);
    win.attach(Square);
    win.attach(Square_label);
    win.attach(Cos);
    win.attach(Cos_label);
    win.attach(Sloping_cos);
    win.attach(Sloping_cos_label);
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
