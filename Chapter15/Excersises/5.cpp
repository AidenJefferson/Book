// “Animate” (as in §15.5) the series 1–1/3+1/5–1/7+1/9–1/11+ . . . . It is known as Leibniz’s series and converges to
// pi / 4.

// note: changed Function constructor to take std::function<double(double)> instead of 'Fct'.

#include "Graph.h"
#include "Simple_window.h"
#include <cmath>

double leibniz(double n) {

    double ans{ 1.0 };
    bool negative{ true };
    double den{ 3.0 };

    if (n <= 1) return ans;
    for (int i = 1; i < n; i++) {
        if (negative == true)
            ans -= 1.0 / den;
        else
            ans += 1.0 / den;
        den += 2;
        negative = !negative;
    }

    return ans;
}

int main()
try {
    using namespace Graph_lib;
    Simple_window win{ Point{100,0}, 600,600, "Excersise 5" };

    for (int n = 0; n < 50; n++) {

        Function lib{ [n](double x) { return leibniz(n); } , double(-10), double(10), Point{300,300}, 100, double(25), double(25) };
        lib.set_color(Color::black);
        win.attach(lib);
        win.wait_for_button();
        win.detach(lib);
    }    

    return 0;
}
catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}