// Write a program that reads the data from raw_temps.txt created in exercise 2 into a vector and then calculates the
// mean and median temperatures in your data set. Call this program temp_stats.cpp.

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

struct Reading{
    Reading()
        : hour{-1}, temperature{-9999}, unit{'x'} {};// ensures not initialised with data that could be valid
    int hour;
    double temperature;
    char unit;
};

std::ostream& operator<<(std::ostream& os, const Reading& r){
    return os << "(" << r.hour << "," << r.temperature << r.unit << ")"; 
}

std::istream& operator>>(std::istream& is, Reading& r){
    int x;
    double y;
    char ch1, ch2, u, ch3;

    is >> ch1 >> x >> ch2 >> y >> u>> ch3;
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

std::vector<Reading> get_readings_f(const std::string file_name){
    std::ifstream ifs{file_name};
    if(!ifs) throw std::runtime_error("could not open output file");

    std::vector<Reading> reads_in;
    for(Reading r; ifs >> r;){
        if(r.unit == 'f'){
            r.temperature = (r.temperature - 32)/1.8;
            r.unit = 'c';
        }

        reads_in.push_back(r);
    }

    return reads_in;
}

double find_mean_reading(const std::vector<Reading> r){
    double sum{0};

    for(int i=0; i < r.size(); i++){
        sum += r[i].temperature; 
    }

    return sum/r.size(); // gives mean
}

double find_median_reading(const std::vector<Reading> r){
    std::vector<double> temps;
    double med{0};

    for(int i=0; i<r.size(); i++){
        temps.push_back(r[i].temperature); // make vector of temperatures to easily sort
    }
    std::sort(temps.begin(), temps.end());

    if(temps.size() % 2 == 0){
        med = (temps[temps.size()/2] + temps[temps.size()/2-1])/2;
    }
    else{
        med = temps[temps.size()/2];
    }

    return med;
}

int main(){
    std::vector<Reading> readings = get_readings_f("raw_temps.txt");
    double mean{0}, median{0};


    mean = find_mean_reading(readings);
    median = find_median_reading(readings);
    
    std::cout << "mean temp:\t" << mean << "\tmedian temp:\t" << median << std::endl;
    return 0;
}
