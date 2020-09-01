// Draw a circle. Move a mark around on the circle (let it move a bit each time you hit the “Next” button).

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

namespace Graph_lib { // changed how the 'move()' funtion works for the Mark class.
    void Mark::move(double x, double y) {
        set_point(0, Point{ x,y });
    }
}

constexpr double PI = 3.14159;

int main()
try {
	// create window
    Graph_lib::Simple_window win{ Graph_lib::Point{100,100}, 800, 600, "Excersise 12" };

    // create circle
    Graph_lib::Point center{ 400,300 };
    Graph_lib::Circle c{ center, 150 };
    c.set_color(Graph_lib::Color::black);
    win.attach(c);
    
    Graph_lib::Mark m{ Graph_lib::Point{center.x + c.radius(), center.y}, 'X' };

    double angle{ 2 * PI };
    double x{ 0 };
    double y{ 0 };
  
    for (double i = 0; i < angle; i += 0.1) {
        
        x = center.x + c.radius() * cos(i);
        y = center.y + c.radius() * sin(i);
   
        m.move(x, y);
        win.attach(m);
        win.wait_for_button();
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
