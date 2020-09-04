// Define an abstract class and try to define an object of that type. What happens ?

// The class cannot be built itself, it can only be inheritted from to create another class (as long as the virtual function(s) are overridden).

#include "Simple_window.h"
#include "Graph.h"

class Abstract {
public:
    Abstract(int f, int s)
        : first{ f }, second{ s }
    {
    }

    virtual void print() const =0;

private:
    int first;
    int second;
};

int main()
try {
   
    Abstract test{ 100 , 200};

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
