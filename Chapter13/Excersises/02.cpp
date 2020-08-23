// Draw a box with rounded corners.Define a class Box, consisting of four linesand four arcs.

#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib { // should be placed in Graph.h & Graph.cpp, only placed here for github.
    struct Box : Shape {
    public:
        Box(Point p, int ww, int hh, int c_r)
            : w{ ww }, h{ hh }, cr{ c_r }
        {
            add(p);
        }

        int width() const { return w; }
        int height() const { return h; }
        int corner_rad() const { return cr; }

        void draw_lines() const;

    private:
        int w, h, cr; // width, height, corner radius
    };

    void Box::draw_lines() const {

        // top-left, top-right, bottom-left, bottom-right of a non-curved rectangle
        Point tl{ point(0).x, point(0).y };
        Point tr{ point(0).x + w, point(0).y }; 
        Point br{ point(0).x + w, point(0).y + h };
        Point bl{ point(0).x, point(0).y + h };

        if (fill_color().visibility())
        {
            fl_color(fill_color().as_int());
            fl_pie(tr.x - 2 * cr, tr.y, cr + cr, cr + cr, 0, 90);
            fl_pie(br.x - 2 * cr, br.y - 2 * cr, cr + cr, cr + cr, 270, 0);       
            fl_pie(bl.x, bl.y - 2 * cr, cr + cr, cr + cr, 180, 270);
            fl_pie(tl.x, tl.y, cr + cr, cr + cr, 90, 180);
            
            fl_rectf(tl.x, tl.y + cr, cr, h - 2 * cr);
            fl_rectf(tr.x - cr, tr.y + cr, cr, h - 2 * cr);
            fl_rectf(tl.x + cr, tl.y, w - 2 * cr, h); // centre rect filled
        }

        if (color().visibility())
        {
            fl_color(color().as_int());
            fl_line(tl.x + cr, tl.y, tr.x - cr, tr.y);
            fl_arc(tr.x - 2 * cr, tr.y, cr + cr, cr + cr, 0, 90);
            fl_line(tr.x, tr.y + cr, br.x, br.y - cr);
            fl_arc(br.x - 2 * cr, br.y - 2 * cr, cr + cr, cr + cr, 270, 0);
            fl_line(br.x - cr, br.y, bl.x + cr, bl.y);
            fl_arc(bl.x, bl.y - 2*cr, cr + cr, cr + cr, 180, 270);
            fl_line(bl.x, bl.y - cr, tl.x, tl.y + cr);
            fl_arc(tl.x, tl.y, cr + cr, cr + cr, 90, 180);
        }     
    }
}

int main()
try {
    // create window
    Graph_lib::Point ls{ 100,0 };
    Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 2" }; 

    Graph_lib::Box test_box{ Graph_lib::Point{100,100}, 200, 200, 20};
    test_box.set_color(Graph_lib::Color::blue);
    test_box.set_fill_color(Graph_lib::Color::red);

    win.attach(test_box);
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