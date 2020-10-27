// Make a window(based on My_window) with a 4 - by - 4 checkerboard of square buttons. When pressed, a button
// performs a simple action, such as printing its coordinates in an output box, or turns a slightly different color (until another
// button is pressed).

#include "GUI.h"
#include "My_window.h"

namespace Graph_lib {

    struct Four_window : public My_window {
    public:
        Four_window(Point p, double w, double h, const string& title);

    private:
        Button print_coord; // button that prints its coordinates to output box
        Button swap_1; // button that changes colour
        Button swap_2; // button that changes colour
        Button increase_int; // increases an int in an output box


        Out_box int_display;
        Out_box coords_display;

        void print_pressed();
        void swap_pressed();
        void increase_pressed();

        int value;
    };

    Four_window::Four_window(Point p, double w, double h, const string& title)
        : My_window{ p,w,h,title }, value{ 0 },
        print_coord{ Point{100,100}, 150,40, "Print Co-ordinates", [](Address, Address pw) { reference_to<Four_window>(pw).print_pressed(); } },
        swap_1{ Point{250,100}, 150,40, "Swap", [](Address, Address pw) { reference_to<Four_window>(pw).swap_pressed(); } },
        swap_2{ Point{100,140}, 150,40, "Me", [](Address, Address pw) { reference_to<Four_window>(pw).swap_pressed(); } },
        increase_int{ Point{250,140}, 150,40, "Increase Int", [](Address, Address pw) { reference_to<Four_window>(pw).increase_pressed(); } },
        int_display{ Point{100, 200}, 70, 20, "Int:"},
        coords_display{ Point{320,200}, 70, 20, "Co-ordinates"}
    {
        attach(print_coord);
        attach(swap_1);
        attach(swap_2);
        attach(increase_int);
        attach(int_display);
        int_display.put(0);
        attach(coords_display);
        coords_display.put("(0,0)");

    }

    void Four_window::print_pressed() {
        stringstream ss;
        ss << '(' << print_coord.loc.x << ',' << print_coord.loc.y << ')';
        coords_display.put(ss.str());
        redraw();
    }

    void Four_window::swap_pressed() {
        string place_hold;
        place_hold = swap_1.label;
        swap_1.label = swap_2.label;
        swap_2.label = place_hold;
        redraw();
    }

    void Four_window::increase_pressed() {
        value++;
        int_display.put(value);
        redraw();
    }
}

int main()
try {
    Graph_lib::Four_window win{ Graph_lib::Point{100,0}, 600, 400, "Excersise 2" };
    return Graph_lib::gui_main();
}
catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}