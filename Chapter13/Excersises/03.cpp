// Define a class Arrow, which draws a line with an arrowhead.
//
// NOTE: this excersise was very tricky for me, I had to do a lot of reading online until I came accross the following:
// https://math.stackexchange.com/questions/2125690/find-coordinates-of-3rd-right-triangle-point-having-2-sets-of-coordinates-and-a

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

namespace Graph_lib { // should be placed in Graph.h & Graph.cpp, only placed here for github.

    struct Arrow : Shape {
    public:
        Arrow(Point p1, Point p2, int length) 
            : arrow_length{length}
        { 
            add(p1); add(p2); 
        }

        void draw_lines() const;
    
    private:
        int arrow_length;
    };

    void Arrow::draw_lines() const {

        Shape::draw_lines(); // draw line using shape
        
        // then draw the triangle
        double distance = sqrt(pow(point(1).x - point(0).x, 2) + pow(point(1).y - point(0).y, 2));

        Point arrow_base{ arrow_length / distance * point(0).x + (1 - arrow_length / distance) * point(1).x, arrow_length / distance * point(0).y + (1 - arrow_length / distance) * point(1).y };

        //(X3, Y3) = (X2 ± C(Y1−Y2)/L, Y2 ± C(X2−X1)/L)
        Point arrow_left{ arrow_base.x + arrow_length * (point(1).y - point(0).y) / distance , arrow_base.y - arrow_length * (point(1).x - point(0).x) / distance };
        Point arrow_right{ arrow_base.x - arrow_length * (point(1).y - point(0).y) / distance , arrow_base.y + arrow_length * (point(1).x - point(0).x) / distance };
    
        if (fill_color().visibility())
        {
            // fill
            fl_color(fill_color().as_int());
            fl_begin_complex_polygon();
            fl_vertex(point(1).x, point(1).y);
            fl_vertex(arrow_left.x, arrow_left.y);
            fl_vertex(arrow_right.x, arrow_right.y);
            fl_end_complex_polygon();
            fl_color(color().as_int());	
        }

        if (color().visibility())
        {
            fl_line(point(1).x, point(1).y, arrow_left.x, arrow_left.y);
            fl_line(arrow_left.x, arrow_left.y, arrow_right.x, arrow_right.y);
            fl_line(arrow_right.x, arrow_right.y, point(1).x, point(1).y);
        }
    }
}

int main()
try {
    // create window
    Graph_lib::Point ls{ 100,0 };
    Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 3" }; 

    Graph_lib::Arrow test_arrow{ Graph_lib::Point{100,100}, Graph_lib::Point{200,200}, 20 };
    test_arrow.set_color(Graph_lib::Color::blue);
    test_arrow.set_fill_color(Graph_lib::Color::red);

    win.attach(test_arrow);
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
