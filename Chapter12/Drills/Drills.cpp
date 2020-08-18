// 1.   Get an empty Simple_window with the size 600 by 400 and a label My window compiled, linked, and run. Note that
//      you have to link the FLTK library as described in Appendix D; #include Graph.h and Simple_window.h in your
//      code and include Graph.cpp and Window.cpp in your project.
// 
// 2.   Now add the examples from §12.7 one by one, testing between each added subsection example.
// 
// 3.   Go through and make one minor change(e.g., in color, in location, or in number of points) to each of the subsection
//      examples.

#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    using namespace Graph_lib;

    // Open empty window
    Point tl{ 100, 100 };
    Simple_window window{ tl, 800, 600 , "My Window" };
    
    window.wait_for_button();

    // Draw x & y axis on a window
    Axis xaxis{ Axis::x, Point{20,400}, 500, 20, "x axis" }; 
    xaxis.set_color(Color::red); 
    window.attach(xaxis); 
    Axis yaxis{ Axis::y, Point{20,400}, 300, 15, "y axis" };
    yaxis.set_color(Color::red); 
    window.attach(yaxis);

    window.set_label("My Axis");
    window.wait_for_button(); 

    // Graph a function
    Function sine{ sin,0,10,Point{20,400},40,50,50 }; 
    sine.set_color(Color::green);
    window.attach(sine);
    window.set_label("Function Plot");
    window.wait_for_button();

    // Create a polygon
    Graph_lib::Polygon poly; 
    poly.add(Point{ 300,200 });
    poly.add(Point{ 350,100 });
    poly.add(Point{ 400,200 });
    poly.set_color(Color::blue);
    poly.set_style(Line_style::dashdotdot);
    window.attach(poly);
    window.set_label("My Polygon");
    window.wait_for_button();

    // Create rectangle
    Graph_lib::Rectangle r{ Point{400,400}, 100, 50 };
    r.set_fill_color(Color::yellow); // color the inside of the rectangle
    poly.set_style(Line_style(Line_style::dash, 4));
    window.attach(r);
    window.set_label("My Rectangle");
    window.wait_for_button();

    // Create text
    Text t{ Point{150,150}, "Hello, graphical world!" };
    window.attach(t);
    window.set_label("My Text");
    window.wait_for_button();
    t.set_font(Font::times_bold);
    t.set_font_size(20);
    window.set_label("My Text (Bold)");
    window.wait_for_button();

    // Create image
    Image ii{ Point{200,100},"Natalie.jpg" };
    window.attach(ii);
    window.set_label("Canvas #10");
    window.wait_for_button();


    
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}