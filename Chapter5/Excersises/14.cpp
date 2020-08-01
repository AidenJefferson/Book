// Read (day-of-the-week,value) pairs from standard input. For example:
//
//      Tuesday 23 Friday 56 Tuesday –3 Thursday 99
// 
// Collect all the values for each day of the week in a vector<int>. Write out the values of the seven day-of-the-week
// vectors. Print out the sum of the values in each vector. Ignore illegal days of the week, such as Funday, but accept
// common synonyms such as Mon and monday. Write out the number of rejected values.

#include <iostream>
#include <vector>
#include <string>

int main(){
    try{
        std::string day;
        int sum{0}, rejections{0};
        std::vector<int> mon, tue, wed, thur, fri, sat, sun;
        
        std::cout << "Please enter a day of the week followed by a score. (use Ctrl-D to stop)" << std::endl;

        while(std::cin >> day >> sum){
            if(day == "Monday" || day == "Mon" || day == "monday" || day == "mon")
                mon.push_back(sum);
            else if(day == "Tuesday" || day == "Tue" || day == "tuesday" || day == "tue")
                tue.push_back(sum);
            else if(day == "Wednesday" || day == "Weds" || day == "wednesday" || day == "weds")
                wed.push_back(sum);
            else if(day == "Thursday" || day == "Thurs" || day == "thursday" || day == "thurs")
                thur.push_back(sum);
            else if(day == "Friday" || day == "Fri" || day == "friday" || day == "fri")
                fri.push_back(sum);
            else if(day == "Saturday" || day == "Sat" || day == "saturday" || day == "sat")
                sat.push_back(sum);
            else if(day == "Sunday" || day == "Sun" || day == "sunday" || day == "sun")
                sun.push_back(sum);
            else rejections++;
        }
        
        std::cout << "The values you entered are as follows:" << std::endl << std::endl;
        
        std::cout << "Monday" << std::endl;
        for(int i=0; i<mon.size(); i++){
            std::cout << mon[i] << std::endl;
        }
        std::cout << "Tuesday" << std::endl;
        for(int i=0; i<tue.size(); i++){
            std::cout << tue[i] << std::endl;
        }
        std::cout << "Wednesday" << std::endl;
        for(int i=0; i<wed.size(); i++){
            std::cout << wed[i] << std::endl;
        }
        std::cout << "Thursday" << std::endl;
        for(int i=0; i<thur.size(); i++){
            std::cout << thur[i] << std::endl;
        }
        std::cout << "Friday" << std::endl;
        for(int i=0; i<fri.size(); i++){
            std::cout << fri[i] << std::endl;
        }
        std::cout << "Saturday" << std::endl;
        for(int i=0; i<sat.size(); i++){
            std::cout << sat[i] << std::endl;
        }
        std::cout << "Sunday" << std::endl;
        for(int i=0; i<sun.size(); i++){
            std::cout << sun[i] << std::endl;
        }
        return 0;
    }
    catch(std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "Unknown error." << std::endl;
    }
}
