// 5.   Add a pure virtual function called pvf() to B1 and try to repeat 1–4.Explain the result.

#include "Simple_window.h"
#include "Graph.h"

class B1 {
public:
    virtual void pvf() const = 0; // 5 - EXPLAIN: class has now become abstract type so cannot be used, only inheritted from with the addition 
    virtual void vf() const {    //               of a new pvf() function override.
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
    void f() const { 
        cout << "D1::f()" << endl;
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
