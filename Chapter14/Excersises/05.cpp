// Define a Striped_rectangle where instead of fill, the rectangle is “filled” by drawing one - pixel - wide horizontal lines
// across the inside of the rectangle(say, draw every second line like that). You may have to play with the width of lines
// and the line spacing to get a pattern you like.

#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib {
    struct Striped_rectangle : public Rectangle {
    public:
        using Rectangle::Rectangle;
        void draw_lines() const override;
    };

    void Striped_rectangle::draw_lines() const {
        if (fill_color().visibility())
        {	// fill
            fl_color(fill_color().as_int());
            for (int i = 4; i < height(); i += 4) {
                fl_line(point(0).x + 1, point(0).y + i, point(0).x + width() - 1, point(0).y + i);
            }
            fl_color(color().as_int());	// reset color
        }

        if (color().visibility())
        {	// edge on top of fill
            fl_color(color().as_int());
            fl_rect(point(0).x, point(0).y, width(), height());
        }
    }
}

int main()
try {
    using namespace Graph_lib;

    Simple_window win{ Point{100,0}, 800, 600, "Excersise 5" };

    Striped_rectangle r{ Point{200,200}, 200, 200 };
    r.set_color(Color::black);
    r.set_fill_color(Color::blue);

    win.attach(r);
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
