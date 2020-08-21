// 1.   Make an 800 - by - 1000 Simple_window.
//
// 2.   Put an 8 - by - 8 grid on the leftmost 800 - by - 800 part of that window(so that each square is 100 by 100).
//
// 3.   Make the eight squares on the diagonal starting from the top left corner red(use Rectangle).
// 
// 4.   Find a 200 - by - 200 - pixel image(JPEG or GIF) and place three copies of it on the grid(each image covering four
//      squares).If you can’t find an image that is exactly 200 by 200, use set_mask() to pick a 200 - by - 200 section of a larger
//      image.Don’t obscure the red squares.
// 
// 5.   Add a 100 - by - 100 image.Have it move around from square to square when you click the “Next” button.Just put
//      wait_for_button() in a loop with some code that picks a new square for your image.

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    // create window
    Graph_lib::Point ls{ 100,0 };
    Graph_lib::Simple_window win{ ls, 900, 700, "Chapter 13" }; // smaller size due to laptop resolution

    // make grid (700 by 700)
    int grid_size = 700;
    int grid_width = 100;
    int grid_height = 100;
    Graph_lib::Lines grid;
    for (int i = 0; i < grid_size+1; i += grid_width) {
        grid.add(Graph_lib::Point{ i,0 }, Graph_lib::Point{ i,grid_size });
        grid.add(Graph_lib::Point{ 0,i }, Graph_lib::Point{ grid_size,i });
    }
    grid.set_color(Graph_lib::Color::black);
    win.attach(grid);

    // make diagonal red
    Graph_lib::Vector_ref<Graph_lib::Rectangle> diags;
    for (int i = 0; i < grid_size / grid_width; i++) {
        diags.push_back(new Graph_lib::Rectangle{ Graph_lib::Point{i*grid_width,i*grid_height}, grid_width, grid_height });
        diags[diags.size()-1].set_fill_color(Graph_lib::Color::red);
        win.attach(diags[diags.size()-1]);
    }

    // place image
    Graph_lib::Image i1{ Graph_lib::Point{0,0},"image.jpg" };
    win.attach(i1);
    Graph_lib::Image i2{ Graph_lib::Point{500,0},"image.jpg" };
    win.attach(i2);
    Graph_lib::Image i3{ Graph_lib::Point{200,500},"image.jpg" };
    win.attach(i3);

    // place moving image
    Graph_lib::Image i4{ Graph_lib::Point{200,200}, "im.jpg" };
    for (int i = 0; i < 10; i++) {
        win.attach(i4);
        win.wait_for_button();
        int nx = grid_width * (rand() % 8); // new position
        int ny = grid_height * (rand() % 8);

        i4.move(nx - i4.point(0).x, ny - i4.point(0).y); // move to new position
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}