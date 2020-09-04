// Define a Striped_circle using the technique from Striped_rectangle

// NOTE: this problem was solved using the formula for a chord of a circle at https://en.wikipedia.org/wiki/Circular_segment
// c = 2*R*(1-(d/R))^0.5

#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib {
    struct Striped_circle : public Circle {
    public:
        using Circle::Circle;
        void draw_lines() const override;
    };

    void Striped_circle::draw_lines() const {
        if (fill_color().visibility())
        {	// fill
            fl_color(fill_color().as_int());
            double chord{ 0 };
            for (int i = 0; i < radius(); i += 2) {
                chord = 2 * radius() * sqrt(1 - pow(((i *1.0) / (radius() * 1.0)), 2));
                fl_line(center().x - chord / 2 + 1, center().y - i, center().x + chord / 2 - 1, center().y - i);
                fl_line(center().x - chord / 2 + 1, center().y + i, center().x + chord / 2 - 1, center().y + i);
            } 
            fl_color(color().as_int());	// reset color
        }

        if (color().visibility())
        {
            fl_color(color().as_int());
            fl_arc(point(0).x, point(0).y, radius() + radius(), radius() + radius(), 0, 360);
        }
    }
}

int main()
try {
    using namespace Graph_lib;

    Simple_window win{ Point{100,0}, 800, 600, "Excersise 5" };

    Striped_circle c{ Point{400,300}, 100 };
    c.set_color(Color::black);
    c.set_fill_color(Color::blue);

    win.attach(c);
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
