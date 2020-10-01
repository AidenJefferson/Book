// 1. Make a completely new project with linker settings for FLTK(as described in Appendix D).
// 2. Using the facilities of Graph_lib, type in the line - drawing program from §16.5 and get it to run.
// 3. Modify the program to use a pop - up menu as described in §16.7 and get it to run.
// 4. Modify the program to have a second menu for choosing line styles and get it to run.

#include "GUI.h"

namespace Graph_lib {

    struct Lines_window : Window {
        Lines_window(Point xy, int w, int h, const string& title);
        Open_polyline lines;
    private:
        Button next_button; // add (next_x,next_y) to lines
        Button quit_button;
        Button colours_button;
        Button styles_button;

        Menu colours_menu;
        Menu styles_menu;

        In_box next_x;
        In_box next_y;
        Out_box xy_out;

        void next();
        void quit();

        void red_pressed() { lines.set_color(Color::red); colour_changed(); redraw(); }
        void blue_pressed() { lines.set_color(Color::blue); colour_changed(); redraw(); }
        void black_pressed() { lines.set_color(Color::black); colour_changed(); redraw(); }
        void colours_pressed() { colours_button.hide(); colours_menu.show(); }
        void colour_changed() { colours_menu.hide(); colours_button.show(); }
        
        void dot_pressed() { lines.set_style(Line_style::dot); style_changed(); redraw(); }
        void solid_pressed() { lines.set_style(Line_style::solid); style_changed(); redraw(); }
        void dash_pressed() { lines.set_style(Line_style::dash); style_changed(); redraw(); }
        void dad_pressed() { lines.set_style(Line_style::dashdot); style_changed(); redraw(); }
        void dadd_pressed() { lines.set_style(Line_style::dashdotdot); style_changed(); redraw(); }
        void styles_pressed() { styles_button.hide(); styles_menu.show(); }
        void style_changed() { styles_menu.hide(); styles_button.show(); }

    };

    Lines_window::Lines_window(Point xy, int w, int h, const string& title)
        : Window{ xy,w,h,title },
        next_button{ Point{x_max() - 150,0}, 70, 20, "Next point", [](Address, Address pw) {reference_to<Lines_window>(pw).next(); } },
        quit_button{ Point{x_max() - 70,0}, 70, 20, "Quit", [](Address, Address pw) {reference_to<Lines_window>(pw).quit(); } },
        colours_button{ Point{x_max() - 120,40}, 120, 20, "Change Colour", [](Address, Address pw) {reference_to<Lines_window>(pw).colours_pressed(); } },
        colours_menu{ Point{x_max() - 120, 40}, 120, 20, Menu::vertical, "Change Colour" },
        styles_button{ Point{x_max() - 120, 60}, 120, 20, "Change Line Style", [](Address, Address pw) {reference_to<Lines_window>(pw).styles_pressed(); } },
        styles_menu{ Point{x_max() - 120, 60}, 120, 20, Menu::vertical, "Change Line Style" },
        next_x{ Point{x_max() - 310,0}, 50, 20, "next x:" },
        next_y{ Point{x_max() - 210,0}, 50, 20, "next y:" },
        xy_out{ Point{100,0}, 100, 20, "current (x,y):" }
    {
        attach(next_button);
        attach(quit_button);
        attach(colours_button);
        attach(styles_button);
        attach(next_x);
        attach(next_y);
        attach(xy_out);
        lines.set_color(Color::black);
        attach(lines);
        colours_menu.attach(new Button{ Point{0,0}, 0, 0, "Red", [](Address, Address pw) { reference_to<Lines_window>(pw).red_pressed(); } });
        colours_menu.attach(new Button{ Point{0,0}, 0, 0, "Blue", [](Address, Address pw) { reference_to<Lines_window>(pw).blue_pressed(); } });
        colours_menu.attach(new Button{ Point{0,0}, 0, 0, "Black", [](Address, Address pw) { reference_to<Lines_window>(pw).black_pressed(); } });
        attach(colours_menu);
        colours_menu.hide();
        styles_menu.attach(new Button{ Point{0,0},0,0,"Dot", [](Address,Address pw) { reference_to<Lines_window>(pw).dot_pressed(); } });
        styles_menu.attach(new Button{ Point{0,0},0,0,"Solid", [](Address,Address pw) { reference_to<Lines_window>(pw).solid_pressed(); } });
        styles_menu.attach(new Button{ Point{0,0},0,0,"Dash", [](Address,Address pw) { reference_to<Lines_window>(pw).dash_pressed(); } });
        styles_menu.attach(new Button{ Point{0,0},0,0,"Dash-Dot", [](Address,Address pw) { reference_to<Lines_window>(pw).dad_pressed(); } });
        styles_menu.attach(new Button{ Point{0,0},0,0,"Dash-Dot-Dot", [](Address,Address pw) { reference_to<Lines_window>(pw).dadd_pressed(); } });
        attach(styles_menu);
        styles_menu.hide();
    }

    void Lines_window::quit() {
        hide(); // curious FLTK idiom to delete window
    }

    void Lines_window::next() {
        int x = next_x.get_int();
        int y = next_y.get_int();

        lines.add(Point{ double(x),double(y) });

        // update current position readout:
        ostringstream ss;
        ss << '(' << x << ',' << y << ')';
        xy_out.put(ss.str());
        redraw();
    }

}

int main()
try {
    Graph_lib::Lines_window win {Graph_lib::Point{100,100},600,400,"lines"};
    return Graph_lib::gui_main();
}
catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}