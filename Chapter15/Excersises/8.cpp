// Here is a collection of heights in centimeters together with the number of people in a group of that height (rounded to the
// nearest 5cm): (170, 7), (175, 9), (180, 23), (185, 17), (190, 6), (195, 1). How would you graph that data ? If you can’t think
// of anything better, do a bar graph. Remember to provide axes and labels. Place the data in a file and read it from that file.

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

// create data storage
struct Data {
    int height;
    int persons;
};

std::istream& operator>>(std::istream& is, Data& d) {
    char ch1, ch2, ch3;
    int h, p;
    is >> ch1 >> h >> ch2 >> p >> ch3;
    if (!is || ch1 != '(' || ch2 != ',' || ch3 != ')') {
        is.setstate(std::ios_base::failbit);
        return is;
    }
    else {
        d.height = h;
        d.persons = p;
    }

    return is;
}

int main()
try {
    using namespace Graph_lib;

    ifstream ifs("data.txt");
    if (!ifs) throw std::runtime_error("could not open file");

    Simple_window win(Point{ 100,0 }, 800, 600, "Excersie 6");
   
    Bar_graph g{ Point{400,300}, 30, 200, 6, 200 / 5, "Heights(cm)" };
    g.set_color(Color::black);
   
    for (Data d; ifs >> d;) {
        g.add_data(d.persons, to_string(d.height));
        std::cout << d.persons << "," << to_string(d.height) << std::endl;
    }


    win.attach(g);
    win.wait_for_button();

    return 0;
}
catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}