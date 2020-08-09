// Modify the store_temps.cpp program from exercise 2 to include a temperature suffix c for Celsius or f for Fahrenheit
// temperatures. Then modify the temp_stats.cpp program to test each temperature, converting the Celsius readings to
// Fahrenheit before putting them into the vector.

#include <iostream>
#include <fstream>
#include <vector>
#include <random>

struct Reading{
    Reading()
        : hour{-1}, temperature{-9999}, unit{'x'} {};// ensures not initialised with data that could be valid
    int hour;
    double temperature;
    char unit;
};

std::ostream& operator<<(std::ostream& os, Reading& r){
    return os << "(" << r.hour << "," << r.temperature << r.unit << ")"; 
}

std::istream& operator>>(std::istream& is, Reading& r){
    int x;
    double y;
    char ch1, ch2, u, ch3;

    is >> ch1 >> x >> ch2 >> y >> u >> ch3;
    if(!is){
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }
    if(ch1!='(' || ch2!=',' || ch3!=')') throw std::runtime_error("bad input from stream");
    if(u!='c' && u!='f') throw std::runtime_error("bad unit from input stream");
    r.hour = x;
    r.temperature = y;
    r.unit = u;
    return is;
}

std::vector<Reading> create_N_random_readings(int N){
    std::vector<Reading> rand_r;
    Reading r;

    for(int i=0; i<N; i++){
        r.hour = ((rand() % 23));
        r.temperature = ((rand() % 100) - 30);
        if(rand() % 2 == 1) r.unit = 'c';
        else r.unit ='f';
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
