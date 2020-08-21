// Define a Roman_int class for holding Roman numerals (as ints) with a << and >>. Provide Roman_int with an
// as_int() member that returns the int value, so that if r is a Roman_int, we can write cout << "Roman" << r << "
// equals " << r.as_int() << '\n';.

#include <string>

class Roman_int{
    public:
    Roman_int(std::string n);
    Roman_int()
        : numeral{"I"} {};

    std::string get_numeral() const {return numeral;};
    void set_numeral(std::string s);
    int as_int();

    private:
    std::string numeral;

};

bool is_valid(std::string s);
