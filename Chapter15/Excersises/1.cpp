// Here is another way of defining a factorial function :
//      int fac(int n) { return n > 1 ? n * fac(n–1) : 1; } // factorial n!
// It will do fac(4) by first deciding that since 4 > 1 it must be 4 * fac(3), and that’s obviously 4 * 3 * fac(2), which again is
// 4 * 3 * 2 * fac(1), which is 4 * 3 * 2 * 1. Try to see that it works.A function that calls itself is said to be recursive.The
// alternative implementation in §15.5 is called iterative because it iterates through the values(using while).Verify that the
// recursive fac() worksand gives the same results as the iterative fac() by calculating the factorial of 0, 1, 2, 3, 4, up until
// and including 20. Which implementation of fac() do you prefer, and why ?

// The "better" way is the function fac due to it being more easier to read and understand what is going on.

#include <iostream>

int fac(int n) {
    int ans{ 1 };

    if (n > 1) {
        for (int i = n; i > 0; i--) {
            ans *= i;
        }
        return ans;
    }
    else return ans;
}

int fact(int n) { return n > 1 ? n * fac(n-1) : 1; } // factorial n!

int main()
try {

    std::cout << fac(5) << "\t" << fact(5) << std::endl;
    
    return 0;
}
catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}
