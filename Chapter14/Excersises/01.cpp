// Define two classes Smileyand Frowny, which are both derived from class Circle and have two eyesand a mouth.
// Next, derive classes from Smiley and Frowny which add an appropriate hat to each.

#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib {
    struct Smiley : public Circle {
    public:
        using Circle::Circle;
        void draw_lines() const override;
    };

    void Smiley::draw_lines() const {
        Circle::draw_lines();

        double rad = this->radius();

        if (color().visibility())
        {
            fl_color(color().as_int());
            fl_arc(center().x - rad / 1.5, center().y - rad / 2.0, rad / 4.0 + rad / 4.0, rad / 4.0 + rad / 4.0, 0, 360); // left eye
            fl_arc(center().x + rad / 4.5, center().y - rad / 2.0, rad / 4.0 + rad / 4.0, rad / 4.0 + rad / 4.0, 0, 360); // right eye
            fl_arc(center().x - rad / 2.0, center().y - rad / 4.0, rad / 2.0 + rad / 2.0, rad / 2.0 + rad / 2.0, 180, 0); // smile
        }
    }

    struct Frowny : public Circle {
    public:
        using Circle::Circle;
        void draw_lines() const override;
    };

    void Frowny::draw_lines() const {
        Circle::draw_lines();

        double rad = radius();

        if (color().visibility())
        {
            fl_color(color().as_int());
            fl_arc(center().x - rad / 1.5, center().y - rad / 2.0, rad / 4.0 + rad / 4.0, rad / 4.0 + rad / 4.0, 0, 360); // left eye
            fl_arc(center().x + rad / 4.5, center().y - rad / 2.0, rad / 4.0 + rad / 4.0, rad / 4.0 + rad / 4.0, 0, 360); // right eye
            fl_arc(center().x - rad / 2.0, center().y, rad / 2.0 + rad / 2.0, rad / 2.0 + rad / 2.0, 0, 180); // smile
        }
    }
}

int main()
try {
   
    Graph_lib::Simple_window win{ Graph_lib::Point{100,0}, 800,600, "Excersise 1" };

    Graph_lib::Smiley s{ Graph_lib::Point{200,300}, 100 };
    s.set_color(Graph_lib::Color::black);
    s.set_fill_color(Graph_lib::Color::blue);
    win.attach(s);
    Graph_lib::Frowny f{ Graph_lib::Point{500,300}, 100 };
    f.set_color(Graph_lib::Color::black);
    f.set_fill_color(Graph_lib::Color::blue);
    win.attach(f);

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
