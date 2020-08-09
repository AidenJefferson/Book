// 1.   Start a program to work with points, discussed in §10.4. Begin by defining the data type Point that has two coordinate
//      members x and y.
//
// 2.   Using the code and discussion in §10.4, prompt the user to input seven (x,y) pairs. As the data is entered, store it in a
//      vector of Points called original_points.
//
// 3.   Print the data in original_points to see what it looks like.
//
// 4.   Open an ofstream and output each point to a file named mydata.txt. On Windows, we suggest the .txt suffix to make
//      it easier to look at the data with an ordinary text editor (such as WordPad).
//
// 5.   Close the ofstream and then open an ifstream for mydata.txt. Read the data from mydata.txt and store it in a new
//      vector called processed_points.
//
// 6.   Print the data elements from both vectors.
//
// 7.   Compare the two vectors and print Something's wrong! if the number of elements or the values of elements differ.

#include <iostream>
#include <vector>
#include <fstream>

struct Point{
    Point()
        : x{0},y{0} {};
    Point(int xx, int yy)
        : x{xx}, y{yy} {};

    int x;
    int y;
};

std::ostream& operator<<(std::ostream& os, const Point& p){
    return os << '(' << p.x << ',' << p.y << ')';
}

std::istream& operator>>(std::istream& is, Point& p){
    int x{0}, y{0};
    char ch1, ch2, ch3;
    
    is >> ch1 >> x >> ch2 >> y >> ch3;
    if(!is){
        is.clear(std::ios_base::failbit);
        return is;
    }
    if(ch1!='(' || ch2!=',' || ch3!=')') throw std::runtime_error("bad entry");
    
    p.x = x;
    p.y = y;

    return is;
}

bool operator==(const Point& p1, const Point& p2){
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(const Point& p1, const Point& p2){
    return !(p1 == p2);
}

void print_point_vector(const std::vector<Point>& p, std::string title){
    std::cout << title << ":" << std::endl;
    for(int i=0; i<p.size(); i++){
        std::cout << p[i] << std::endl;
    }
}

void output_points_f(const std::vector<Point>& p, std::string file_name){
    std::ofstream ofname{file_name};
    if(!ofname) throw std::runtime_error("cannot open output file");

    for(int i=0; i<p.size();i++){
        ofname << p[i] << std::endl;
    }
}

std::vector<Point> input_points_f(std::string file_name){
    std::ifstream ifname{file_name};
    if(!ifname) throw std::runtime_error("cannot open input file.");

    std::vector<Point> input_points;

    for(Point p; ifname >> p;){
        input_points.push_back(p);
    }

    return input_points;
}

int main(){
    try{
        std::vector<Point> original_points(7);
        int x{0}, y{0};

        std::cout << "Please enter seven points below: (x,y)" << std::endl;
        for(int i=0; i < original_points.size(); i++){
            Point p;

            std::cin >> p;
            original_points[i] = p;
        }

        print_point_vector(original_points, "original");
        output_points_f(original_points, "mydata.txt");

        std::vector<Point> processed_points = input_points_f("mydata.txt");

        print_point_vector(processed_points, "processed");    
        
        if(processed_points != original_points){
            std::cout << "Whoops,something is not right." << std::endl;
        }

        return 0;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "unknown exception." << std::endl;
        return 2;
    }
}
