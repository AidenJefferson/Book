// Define a class Arc, which draws a part of an ellipse. Hint : fl_arc().

#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib { // Should be placed in Graph.h, placed here for github only.
    struct Arc : Shape {
    public:
        Arc(Point p, int rad, int angs, int ange)
            : r{ rad }, sa{ angs }, ea{ ange }
        {
            add(p);
        }
        
        int radius() const { return r; }
        int start_angle() const { return sa; }
        int end_angle() const { return ea; }

        void draw_lines() const;
        void change_angles(int start, int end);

    private:
        int r; // radius
        int sa; // starting angle
        int ea; // ending angle
    };

    void Arc::draw_lines() const {

        if (fill_color().visibility())
        {
            fl_color(fill_color().as_int());
            fl_pie(point(0).x, point(0).y, r - 1, r - 1, sa, ea);
            fl_color(color().as_int());	
        }

        if (color().visibility())
        {
            fl_color(color().as_int());
            fl_arc(point(0).x, point(0).y, r - 1, r - 1, sa, ea);
        }
    }

    void Arc::change_angles(int start, int end) {
        sa = start;
        ea = end;
    }
}

int main()
try {
    // create window
    Graph_lib::Point ls{ 100,0 };
    Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 1" }; 

    Graph_lib::Arc test_arc{ Graph_lib::Point{100,100}, 100, 0, 90 };
    test_arc.set_color(Graph_lib::Color::black);

    win.attach(test_arc);
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