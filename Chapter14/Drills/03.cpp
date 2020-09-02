// 3.   Define a reference to B1(a B1&) and initialize that to the D1 object you just defined. Call vf() and f() for that reference.

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

class D1 : public B1 {
public:
    void vf() const override {
        cout << "D1::vf()" << endl;
    }
};

int main()
try {
    // 1
    B1 b;
    b.vf();
    b.f();

    // 2
    D1 d;
    d.vf();
    d.f();

    // 3
    B1& bref = d;
    bref.vf();
    bref.f();

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
