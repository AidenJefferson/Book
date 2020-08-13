// Write three functions swap_v(int,int), swap_r(int&,int&), and swap_cr(const int&, const int&). Each should
// have the body:
//
//  { int temp; temp = a, a=b; b=temp; }
//
// where a and b are the names of the arguments.
//
// Try calling each swap like this
//      int x = 7;
//      int y =9;
//      swap_?(x,y); // replace ? by v, r, or cr
//      swap_?(7,9);
//      const int cx = 7;
//      const int cy = 9;
//      swap_?(cx,cy);
//      swap_?(7.7,9.9);
//      double dx = 7.7;
//      double dy = 9.9;
//      swap_?(dx,dy);
//      swap_?(7.7,9.9);
//
// Which functions and calls compiled, and why? After each swap that compiled, print the value of the arguments after the
// call to see if they were actually swapped. If you are surprised by a result, consult §8.6.

#include <iostream>

void swap_v(int a,int b){ // function will not swap the variables called due to being passed by value.
    { int temp; temp = a, a=b; b=temp; }
}
void swap_r(int& a,int& b){
    { int temp; temp = a, a=b; b=temp; }
}
/* // function did not compile due to assignment of const reference.
 * void swap_cr(const int& a, const int& b){
 *     { int temp; temp = a, a=b; b=temp; }
 * }
 */

int main(){
    int x = 7;
    int y =9;
    swap_v(x,y); // replace ? by v, r, or cr
    swap_v(7,9);
    const int cx = 7;
    const int cy = 9;
    swap_v(cx,cy);
    swap_v(7.7,9.9);
    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx,dy);
    swap_v(7.7,9.9);
}
