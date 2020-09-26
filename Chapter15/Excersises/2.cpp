// Define a class Fct that is just like Function except that it stores its constructor arguments. Provide Fct with “reset”
// operations, so that you can use it repeatedly for different ranges, different functions, etc.

#include "Graph.h"
#include "Simple_window.h"
#include <iostream>
#include <cmath>
#include <functional>

namespace Graph_lib {

    class Funct : public Shape {
    public:
        Funct(std::function<double(double)> f, double r1, double r2, Point xy, int count, double xscale, double yscale);

        void reset_func(std::function<double(double)> y);
        void reset_r(double begin, double end);
        void reset_origin(Point p);
        void reset_count(int c);

    private:
        std::function<double(double)> func;
        double r_b, r_e, x_scale, y_scale;
        Point orig; 
        int counter;
        void update();
    };

    Funct::Funct(std::function<double(double)> f, double r1, double r2, Point xy, int count = 100, double xscale = 25, double yscale = 25)
        : func{f}, r_b{ r1 }, r_e{ r2 }, counter{ count }, x_scale{ xscale }, y_scale{ yscale }
    {
        if (r2 - r1 <= 0) error("bad graphing range");
        if (count <= 0) error("non-positive graphing count");
        double dist = (r2 - r1) / count;
        double r = r1;
        for (int i = 0; i < count; ++i)
        {
            add(Point(xy.x + int(r * xscale), xy.y - int(f(r) * yscale)));
            r += dist;
        }
    }

    void Funct::reset_func(std::function<double(double)> y) {
        func = y;
        update();
    }

    void Funct::reset_r(double begin, double end) {
        if (r_e - r_b <= 0) error("bad graphing range");
        r_b = begin;
        r_e = end;
        update();
    }

    void Funct::reset_origin(Point p) {
        orig = p;
        update();
    }

    void Funct::reset_count(int c) {
        if (c <= 0) error("non-positive graphing count");
        counter = c;
        update();
    }

    void Funct::update() {
        this->clear();
        double dist = (r_e - r_b) / counter;
        double r = r_b;
        for (int i = 0; i < counter; ++i)
        {
            add(Point(orig.x + int(r * x_scale), orig.y - int(func(r) * y_scale)));
            r += dist;
        }
    }

}

double one(double x) { return 1; }
double square(double x) { return x * x; }

int main()
try {

    Graph_lib::Simple_window win{ Graph_lib::Point{100,0}, 600,600, "Excersise 2" };

    Graph_lib::Axis x{ Graph_lib::Axis::Orientation::x, Graph_lib::Point{300,300}, 400, 10, "1 == 20 pixels" };
    x.move(-400 / 2, 0);
    x.set_color(Graph_lib::Color::red);
    x.label.move(400 / 2, 0);
    Graph_lib::Axis y{ Graph_lib::Axis::Orientation::y, Graph_lib::Point{300,300}, 400, 10, "1 == 20 pixels" };
    y.move(0, 400 / 2);
    y.set_color(Graph_lib::Color::red);

    Graph_lib::Funct t{ one, -10, 10, Graph_lib::Point{300,300}, 100, 20, 20 };
    t.set_color( Graph_lib::Color::black );
    
    win.attach(x);
    win.attach(y);
    win.attach(t);
    win.wait_for_button();

    win.detach(t);
    t.reset_origin(Graph_lib::Point{ 300,350 });
    t.reset_r(-10, 20);
    win.attach(t);
    win.wait_for_button();

    win.detach(t);
    t.reset_func(square);
    t.reset_origin(Graph_lib::Point{ 300,300 });
    t.reset_r(-10, 10);
    win.attach(t);
    win.wait_for_button();

    return 0;
}
catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}