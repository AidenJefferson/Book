// Define a class Pseudo_window that looks as much like a Window as you can make it without heroic efforts. It
// should have rounded corners, a label, and control icons.Maybe you could add some fake “contents, ” such as an image.It
// need not actually do anything.It is acceptable(and indeed recommended) to have it appe

#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib {

    struct Pseudo_window : public Shape {
    public:
        Pseudo_window(Point p, int width, int height, string title)
            : w{ width }, h{ height }, t{ title }
        {
            add(p);
        }

        void draw_lines() const override;
    private:
        int w;
        int h;
        string t;
    };

    void Pseudo_window::draw_lines() const {
        double cr = w / 10;

        Point tl{ point(0).x, point(0).y };
        Point tr{ point(0).x + w, point(0).y };
        Point br{ point(0).x + w, point(0).y + h };
        Point bl{ point(0).x, point(0).y + h };

        if (fill_color().visibility())
        {
            fl_color(fill_color().as_int());
            fl_pie(tr.x - 2 * cr, tr.y, cr + cr, cr + cr, 0, 90);
            fl_pie(tl.x, tl.y, cr + cr, cr + cr, 90, 180);

            fl_rectf(tl.x + cr, tl.y, w - 2 * cr, cr);
        }

        if (color().visibility())
        {
            // draw box
            fl_color(color().as_int());
            fl_line(tl.x + cr, tl.y, tr.x - cr, tr.y);
            fl_arc(tr.x - 2 * cr, tr.y, cr + cr, cr + cr, 0, 90);
            fl_line(tr.x, tr.y + cr, br.x, br.y - cr);
            fl_arc(br.x - 2 * cr, br.y - 2 * cr, cr + cr, cr + cr, 270, 0);
            fl_line(br.x - cr, br.y, bl.x + cr, bl.y); 
            fl_arc(bl.x, bl.y - 2 * cr, cr + cr, cr + cr, 180, 270);
            fl_line(bl.x, bl.y - cr, tl.x, tl.y + cr);
            fl_arc(tl.x, tl.y, cr + cr, cr + cr, 90, 180);
        }
    }
}

int main()
try {
    Graph_lib::Simple_window win{ Graph_lib::Point{100,0}, 600, 600, "Excersise 10" };
    Graph_lib::Pseudo_window p{ Graph_lib::Point{100,100}, 400, 400, "Test" };
    p.set_color(Graph_lib::Color::black);
    p.set_fill_color(Graph_lib::Color::blue);

    win.attach(p);
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
