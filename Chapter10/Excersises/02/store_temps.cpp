// Write a program that creates a file of data in the form of the temperature Reading type defined in §10.5. For testing, fill
// the file with at least 50 “temperature readings.” Call this program store_temps.cpp and the file it creates
// raw_temps.txt.

#include <iostream>
#include <fstream>
#include <vector>
#include <random>

struct Reading{
    Reading()
        : hour{-1}, temperature{-9999} {};// ensures not initialised with data that could be valid
    int hour;
    double temperature;
};

std::ostream& operator<<(std::ostream& os, Reading& r){
    return os << "(" << r.hour << "," << r.temperature << ")"; 
}

std::istream& operator>>(std::istream& is, Reading& r){
    int x;
    double y;
    char ch1, ch2, ch3;

    is >> ch1 >> x >> ch2 >> y >> ch3;
    if(!is){
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }
    if(ch1!='(' || ch2!=',' || ch3!=')') throw std::runtime_error("bad input from stream");
    
    r.hour = x;
    r.temperature = y;
    return is;
}

std::vector<Reading> create_N_random_readings(int N){
    std::vector<Reading> rand_r;
    Reading r;

    for(int i=0; i<N; i++){
        r.hour = ((rand() % 23));
        r.temperature = ((rand() % 100) - 30);
        rand_r.push_back(r);
    }

    return rand_r;
}

void output_readings_f(std::vector<Reading>& r, std::string s){
    std::ofstream ofs{s};
    if(!ofs) throw std::runtime_error("couldnt open output file");

    for(Reading x : r){
        ofs << x << std::endl;
    }
}

int main(){
    try{
        std::vector<Reading> readings = create_N_random_readings(50);

        output_readings_f(readings, "raw_temps.txt");

        return 0;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    catch(...){
        std::cerr << "unknown error" << std::endl;
    }
}
