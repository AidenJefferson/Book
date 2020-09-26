// Class definition drill :
//      1.  Define a struct Person containing a string name and an int age.
//      2.  Define a variable of type Person, initialize it with “Goofy” and 63, and write it to the screen(cout).
//      3.  Define an input(>> ) and an output(<< ) operator for Person; read in a Person from the keyboard(cin) and write it out
//          to the screen(cout).
//      4.  Give Person a constructor initializing name and age.
//      5.  Make the representation of Person private, and provide const member functions name() and age() to read the name
//          and age.
//      6.  Modify >> and << to work with the redefined Person.
//      7.  Modify the constructor to check that age is[0:150) and that name doesn’t contain any of the characters; : " ' [ ] * & ^
//          % $ # @ !.Use error() in case of error. Test.
//      8.  Read a sequence of Persons from input(cin) into a vector<Person>; write them out again to the screen(cout).Test
//          with correctand erroneous input.
//      9.  Change the representation of Person to have first_name and second_name instead of name. Make it an error not to
//          supply both a first and a second name. Be sure to fix >> and << also. Test.

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

class Person {
public:
    Person(std::string f_name, std::string s_name, int age)
        : fn{ f_name }, sn{ s_name }, a{ age }
    {
        if (age < 0 || age > 150) throw std::runtime_error("Invalid Age");
        for (int i = 0; i < fn.size(); i++) {
            if (ispunct(fn[i])) throw std::runtime_error("Invalid Name");
        }
        for (int i = 0; i < sn.size(); i++) {
            if (ispunct(sn[i])) throw std::runtime_error("Invalid Name");
        }
    }

    std::string first_name() const { return fn; }
    std::string second_name() const { return sn; }
    int age() const { return a; }

    void change_f_name(std::string s) {
        for (int i = 0; i < s.size(); i++) {
            if (ispunct(s[i])) throw std::runtime_error("Invalid First Name");
        }
        fn = s; 
    }

    void change_s_name(std::string s) {
        for (int i = 0; i < s.size(); i++) {
            if (ispunct(s[i])) throw std::runtime_error("Invalid Second Name");
        }
        sn = s;
    }
    
    void change_age(int val) { 
        if (val < 0 || val > 150) throw std::runtime_error("Invalid Age");
        else a = val; 
    }

private:
    std::string fn;
    std::string sn;
    int a;
};

std::ostream& operator<<(std::ostream& os, Person& p) {
    os << p.first_name() << " " << p.second_name() << " " << p.age() << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Person& p) {
    std::string s1, s2;
    int val;
    if (is >> s1 >> s2 >> val) {}
    else 
        return is;
    p.change_f_name(s1);
    p.change_s_name(s2);
    p.change_age(val);
    return is;
}

int main()
try {
    // 1
    //Person p{ "Goofy",63 };

    // 2
    //std::cout << p.n << ", " << p.a << std::endl;

    // 3
    //Person p;
    //std::cin >> p;
    //std::cout << p << std::endl;

    // 4
    //Person p{ "Aiden", 27 };
    //std::cin >> p;
    //std::cout << p << std::endl;

    // 5
    //std::vector<Person> people;
    //for (Person p; std::cin >> p;) {
    //    people.push_back(p);
    //}

    //for (Person p : people) {
    //    std::cout << p;
    //}

    // 6
    Person p{ "Aiden", "Jefferson", 27 };
    std::cout << p;


    return 0;
}
catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}
