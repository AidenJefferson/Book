// Display an image on the screen, e.g., a photo of a friend. Label the image both with a title on the window and with a
// caption in the window.

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    // create window too large for screen
    Graph_lib::Point ls{100, 100};
    Graph_lib::Simple_window win{ ls, 800, 600, "Excersise 9" };

    // create image
    Graph_lib::Image img{ Graph_lib::Point{50, 50}, "Natalie.jpg"};
    Graph_lib::Text title{ Graph_lib::Point{ 300, 25}, "Image of Natalie." };
    title.set_font_size(25);
    title.set_color(Graph_lib::Color::black);

    win.attach(img);
    win.attach(title);
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