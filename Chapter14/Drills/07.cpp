// 7.   Define a class B2 with a pure virtual function pvf(). Define a class D21 with a string data member and a member
//      function that overrides pvf(); D21::pvf() should output the value of the string. Define a class D22 that is just like D21
//      except that its data member is an int. Define a function f() that takes a B2& argument and calls pvf() for its argument.
//      Call f() with a D21 and a D22.

#include "Simple_window.h"
#include "Graph.h"

class B2 {
public:
    virtual void pvf() const = 0;
};

class D21 : public B2 {
public:
    D21(string s) : data{ s } {}
    void pvf() const override {
        cout << data << endl;
    }
private:
    string data;
};

class D22 : public B2 {
public:
    D22(int i) : data{ i } {}
    void pvf() const override {
        cout << data << endl;
    }
private:
    int data;
};

void f(B2& b) {
    b.pvf();
}

int main()
try {
    
    D21 d21{ "Testing" };
    D22 d22{ 7 };
    f(d21);
    f(d22);

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
