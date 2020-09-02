// 6.   Define a class D2 derived from D1 and override pvf() in D2. Make an object of class D2 and invoke f(), vf(), and
//      pvf() for it.

#include "Simple_window.h"
#include "Graph.h"

class B1 {
public:
    virtual void pvf() const = 0; // 5 - EXPLAIN: class has now become abstract type so cannot be used, only inheritted from with the addition 
    virtual void vf() const {    //              of a new pvf() function override.
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

class D2 : public D1 {
public:
    void pvf() const override {
        cout << "D2::pvf()" << endl;
    }
};

int main()
try {
    
    D2 d2;
    d2.pvf();
    d2.vf();
    d2.f();

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
