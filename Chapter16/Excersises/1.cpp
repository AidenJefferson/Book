// Make a My_window that’s a bit like Simple_window except that it has two buttons, next and quit.

#include "GUI.h"

namespace Graph_lib {

    struct My_window : public Window {
    public:
        My_window(Point p, double w, double h, const string& title);
    private:
        Button next_button;
        Button quit_button;

        void next();
        void quit();
    };

    My_window::My_window(Point p, double w, double h, const string& title)
        : Window{ p,w,h,title },
        next_button{ Point{x_max() - 140, 0}, 70, 20, "Next", [](Address, Address pw) { reference_to<My_window>(pw).next(); } },
        quit_button{ Point{x_max() - 70, 0}, 70, 20, "Quit", [](Address, Address pw) { reference_to<My_window>(pw).quit(); } }
    {
        attach(next_button);
        attach(quit_button);
    }

    void My_window::next() {
        return;
    }

    void My_window::quit() {
        hide();
    }
    
}

int main()
try {
    Graph_lib::My_window win{ Graph_lib::Point{100,0}, 800, 600, "Excersise 1" };
    return Graph_lib::gui_main();
}
catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}