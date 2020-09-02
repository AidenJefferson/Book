// 1.   Define a class B1 with a virtual function vf() and a non - virtual function f(). Define both of these functions within class
//      B1. Implement each function to output its name(e.g., B1::vf()). Make the functions public. Make a B1 object and call
//      each function.

#include "Simple_window.h"
#include "Graph.h"

class B1 {
public:
    virtual void vf() const {    
        cout << "B1::vf()" << endl;
    }
    void f() const {
        cout << "B1::f()" << endl;
    }
};

int main()
try {
    
    B1 b;
    b.vf();
    b.f();

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
