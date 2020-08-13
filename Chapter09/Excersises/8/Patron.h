// Create a Patron class for the library. The class will have a user’s name, library card number, and library fees (if
// owed). Have functions that access this data, as well as a function to set the fee of the user. Have a helper function that
// returns a Boolean (bool) depending on whether or not the user owes a fee.

#include <string>

namespace Library{

    class Patron{
        public:
        Patron();
        Patron(std::string n, int cn, double f);

        std::string name() const {return Name;};
        int card_number() const {return Card_Number;};
        double fees() const {return Fees;};

        void set_fee(double fee);

        private:
        std::string Name;
        int Card_Number;
        double Fees;
    };
    
    bool fee_owed(Patron& p);
    std::ostream& operator<<(std::ostream& os, Patron& p);

}
