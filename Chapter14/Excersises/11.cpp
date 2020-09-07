// Define a Binary_tree class derived from Shape. Give the number of levels as a parameter(levels == 0 means no
// nodes, levels == 1 means one node, levels == 2 means one top node with two sub - nodes, levels == 3 means one top node
// with two sub - nodes each with two sub - nodes, etc.). Let a node be represented by a small circle. Connect the nodes by
// lines(as is conventional). P.S. In computer science, trees grow downward from a top node(amusingly, but logically,
// often called the root).

#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib {

    void Circle::move(int dx, int dy) { // changed the way circle uses 'move()' from shape.
        set_point(0, Point{ dx*1.0,dy*1.0 });
    }

    struct Binary_tree : public Shape {
    public:
        Binary_tree(Point p, int levels);

        void draw_lines() const override;
        void set_color(Color c);
        void set_fill_color(Color c);

    private:
        Vector_ref<Circle> nodes;
        int l;
    };

    Binary_tree::Binary_tree(Point p, int levels) 
        : l{ levels }
    {
        add(p);
        int num_nodes{ 1 };
        int num_nodes_per_layer{ 2 };
        if (levels > 1) {
            for (int i = 1; i < levels; i++) {
                num_nodes += num_nodes_per_layer;
                num_nodes_per_layer *= 2;
            }
        }

        // creates the amount of nodes needed
        for (int i = 0; i < num_nodes; i++) {
            nodes.push_back(new Circle{ Point{point(0).x, point(0).y }, 5 });
        }

        int layer{ 1 }; // amount of nodes per line
        
        // moves nodes to correct place
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < layer ; j++) {
                if (i != 0) {
                    double shift = i * 50;
                    double step = 2 * shift / (layer-1);
                    double startx = nodes[0].point(0).x - shift;
                    double starty = nodes[0].point(0).y + shift;

                    nodes[layer - 1 + j].move(startx + j * step, starty);
                }
            }
            layer *= 2;
        }
    }
    
    void Binary_tree::draw_lines() const {
        
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i].draw_lines();
        }
        int final_layer = (nodes.size() + 1) / 2;
        double count{ 1 };
        for (int i = 0; i < nodes.size() - final_layer; i++) {
            for (int j = count; j < count + 2; j++) {
                fl_line(nodes[i].center().x, nodes[i].center().y, nodes[j].center().x, nodes[j].center().y);
            }
            count += 2;
        }
    }

    void Binary_tree::set_color(Color c) {
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i].set_color(c);
        }
    };
    void Binary_tree::set_fill_color(Color c) {
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i].set_fill_color(c);
        }
    }
}

int main()
try {
    Graph_lib::Simple_window win{ Graph_lib::Point{100,0}, 600, 600, "Excersise 11" };

    Graph_lib::Binary_tree b{ Graph_lib::Point{300, 50}, 7 };
    b.set_color(Graph_lib::Color::black);
    b.set_fill_color(Graph_lib::Color::black);
    
    win.attach(b);
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
