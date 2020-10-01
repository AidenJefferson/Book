// Elaborate the bar graph class to allow labeling of the graph itself and its individual bars. Allow the use of color.

#include "Graph.h"
#include "Simple_window.h"

namespace Graph_lib {

    struct Bar_graph : public Shape {
    public:
        Bar_graph(Point p, int height, int width, int x_notches, int y_notches, string y_label);

        void add_data(double val, string label) { data.push_back(val); x_labels.push_back(label); }
        void draw_lines() const;
        void set_color(Color c) { Shape::set_color(c); x.set_color(c); y.set_color(c); }

    private:
        vector<double> data;
        vector<string> x_labels;
        Axis x, y;
        int h, w;
    };

    Bar_graph::Bar_graph(Point p, int height, int width, int x_notches, int y_notches, string y_label)
        : h{ height }, w{ width },
        x{ Axis::Orientation::x, p, width, x_notches, " " },
        y{ Axis::Orientation::y, p, height, y_notches, y_label }
    {
        add(p);
        y.label.move(-35, h / 2);
    }

    void Bar_graph::draw_lines() const {

        // draw x & y axis
        x.draw_lines();
        y.draw_lines();

        double bar_width = w / double(data.size());

        
        if (fill_color().visibility())
        {	// fill
            fl_color(fill_color().as_int());
             for (int i = 0; i < data.size(); i++) {
                fl_rectf(point(0).x + i * bar_width, point(0).y - data[i], bar_width + 1, data[i] + 1);
            }
            fl_color(color().as_int());	// reset color
        }

        if (color().visibility())
        {	// edge on top of fill
            fl_color(color().as_int());

            // draw bars
            for (int i = 0; i < data.size(); i++) {
                fl_rect(point(0).x + i * bar_width, point(0).y - data[i], bar_width + 1, data[i] + 1);
            }

            // draw labels
            Vector_ref<Text> labs;
            for (int i = 0; i < data.size(); i++) {
                labs.push_back(new Text{ Point{point(0).x + bar_width / 2.0 + i * bar_width, point(0).y + 15}, x_labels[i] });
                labs[labs.size() - 1].set_color(color());
                labs[labs.size() - 1].draw_lines();
            }

        }
    }
}

int main()
try {
    using namespace Graph_lib;

    Simple_window win(Point{ 100,0 }, 1000, 1000, "Excersie 6");

    Bar_graph t{ Point{200,550}, 400, 500, 4, 10, "Random Data" };
    t.set_color(Color::black);
    t.add_data(50, "first");
    t.add_data(70, "second");
    t.add_data(40, "third");
    t.add_data(150, "fourth");
    t.set_fill_color(Color::blue);

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