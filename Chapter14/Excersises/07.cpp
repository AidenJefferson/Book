// Define a Striped_closed_polyline using the technique from Striped_rectangle(this requires some algorithmic
// inventiveness).

#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib {
    struct Striped_closed_polyline : public Closed_polyline {
    public:
        using Closed_polyline::Closed_polyline;
        void draw_lines() const override;
    };

    void Striped_closed_polyline::draw_lines() const {

        if (fill_color().visibility())
        {
            Point min{ point(0).x, point(0).y };
            Point max{ point(0).x, point(0).y };

            for (int i = 0; i < number_of_points(); i++) {
                if (point(i).x < min.x)
                    min.x = point(i).x;
                if (point(i).y < min.y)
                    min.y = point(i).y;
                if (point(i).x > max.x)
                    max.x = point(i).x;
                if (point(i).y > max.y)
                    max.y = point(i).y;
            }

            int width = max.x - min.x;
            int height = max.y - min.y;
            int count{ 0 };
            Point inter{ 0,0 };
            vector<Point> intersections;

            for (double i = 2; i < height; i += 2) {
                Point start{ point(0).x, point(0).y + i };
                Point end{ point(0).x + width, point(0).y + i };

                for (int j = 0; j < number_of_points() - 1; j++) {
                    if (line_segment_intersect(start, end, Point{ point(j).x, point(j).y }, Point{ point(j + 1).x, point(j + 1).y }, inter)) {
                  
                        if (count < 2)
                        {
                            intersections.push_back(inter);
                            count++;		
                        }
                    }
                }
                count = 0;
            }

            fl_color(fill_color().as_int());
            for (int i = 0; i < intersections.size(); i+=2) {
                fl_line(intersections[i].x, intersections[i].y, intersections[i+1].x, intersections[i+1].y);
            }
            fl_color(color().as_int());	// reset color
        }

        if (color().visibility()) {
            Shape::draw_lines();
        }
    }
}

int main()
try {
    using namespace Graph_lib;

    Simple_window win{ Point{100,0}, 800, 600, "Excersise 5" };

    Striped_closed_polyline c;
    c.set_color(Color::black);
    c.set_fill_color(Color::blue);

    c.add(Point{ 100,100 });
    c.add(Point{ 600,400 });
    c.add(Point{ 350,400 });
    c.add(Point{ 170,150 });
    c.add(Point{ 100,100 });


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
