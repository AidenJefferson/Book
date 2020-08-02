// Modify the calculator program from Chapter 7 to make the input stream an explicit parameter (as shown in §8.5.8),
// rather than simply using cin. Also give the Token_stream constructor (§7.8.2) an istream& parameter so that when
// we figure out how to make our own istreams (e.g., attached to files), we can use the calculator for those. Hint: Don’t try
// to copy an istream.

/*
    Simple calculator
    This program implements a basic expression calculator.
    Input from std::cin; output to std::cout.
    The grammar for input is:
    Calculation:
        Statement
        Print
        Quit
        Help
        Calculation Statement
    Statement:
        Declaration
        Expression
    Declaration:
        "let" Name "=" Expression
        "const" name "=" Expression
    Name:
        letter
        letter Sequence
    Sequence:
        letter
        digit
        "_"
        letter Sequence
        digit Sequence
        "_" Sequence
    Print:
        ";"
    Quit:
        "quit"
    Help
        "help"
    Expression:
        Term
        Expression "+" Term
        Expression "-" Term
    Term:
        Primary
        Term "*" Primary
        Term "/" Primary
        Term "%" Primary
    Primary:
        Number
        "(" Expression ")"
        "-" Primary
        "+" Primary
        "sqrt(" Expression ")"
        "pow(" Expression "," Integer ")"
        Name
        Name "=" Expression
    Number:
        floating-point-literal
    Input comes from std::cin through the Token_stream called ts.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Token {
public:
	char kind;      // what kind of token
	double value;   // for numbers: a value
	std::string name;    // for variables and functions: a name
	Token(char ch) :kind(ch), value(0) { }                  // make a Token from a char
	Token(char ch, double val) :kind(ch), value(val) { }    // make a Token from a char and a double
    Token(char ch, std::string n) :kind(ch), name(n) { }         // make a Token from a char and a string
};

// stream of tokens
class Token_stream {
public:
    Token_stream();         // make a Token_stream that reads from std::cin
	Token get();            // get a Token
    void putback(Token t);  // put a Token back
    void ignore(char c);    // discard characters up to and including a c
private:
	bool full;          // is there a Token in the buffer?
	Token buffer;       // here is where we keep a Token put back using putback()

};

// constructor
Token_stream::Token_stream()
    :full(false), buffer(0) { }  // no Token in buffer

const char let = 'L';           // declaration token
const char con = 'C';           // constant token
const char quit = 'q';          // t.kind==quit means that t is q quit Token
const char help = 'h';          // help token
const char print = ';';         // t.kind==print means that t is a print Token
const char number = '8';        // t.kind==number means that t is a number Token
const char name = 'a';          // name token
const char square_root = 's';   // square root token
const char power = 'p';         // power function token
const std::string declkey = "let";   // declaration keyword
const std::string conkey = "const";  // constant keyword
const std::string sqrtkey = "sqrt";  // keyword for square root
const std::string powkey = "pow";    // keyword for power function
const std::string quitkey = "quit";  // keyword to quit
const std::string helpkey = "help";  // keyword for help

void error(std::string s){
    throw std::runtime_error(s);
}

// read characters from std::cin and compose a Token
Token Token_stream::get()
{
	if (full) { // check if we already have a Token ready
        full = false;
        return buffer;
    }

	char ch;
    std::cin.get(ch);    // note that std::cin.get() does NOT skip whitespace
    while (isspace(ch)) {
        if (ch == '\n') return Token(print); // if newline detected, return print Token
        std::cin.get(ch);
    }

	switch (ch) {
    //case 'H':
    //    return Token(help);
    //case help:
    //case quit:
    case print:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
    case '%':
    case '=':
    case ',':
		return Token(ch);   // let each character represent itself
	case '.':   // a floating-point-literal can start with a dot
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':   // numeric literal
	{	std::cin.putback(ch);    // put digit back into the input stream
		double val;
		std::cin >> val;         // read a floating-point number
		return Token(number,val);
	}
	default:
		if (isalpha(ch)) {
			std::string s;
			s += ch;
			while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')) s+=ch;
			std::cin.putback(ch);
            if (s == declkey) return Token(let);            // declaration keyword
            if (s == conkey) return Token(con);             // constant keyword
            if (s == sqrtkey) return Token(square_root);    // square root keyword
            if (s == powkey) return Token(power);           // power function keyword
            if (s == helpkey) return Token(help);           // help keyword
            if (s == quitkey) return Token(quit);           // quit keyword
			return Token(name,s);
		}
		error("Bad token");
	}
}

// put Token back into Token stream
void Token_stream::putback(Token t)
{
    if (full) error("putback() into full buffer");
    buffer = t;     // copy t to buffer
    full = true;    // buffer is now full
}

// ignore Tokens up to specific kind
void Token_stream::ignore(char c)
// c represents the kind of Token
{
    // first look in buffer:
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

    // now search input:
	char ch = 0;
	while (std::cin>>ch)
		if (ch==c) return;
}

// -----------------------------------------------------------------------

// type for (name,value) pairs
class Variable {
public:
	std::string name;
	double value;
    bool is_const;
	Variable(std::string n, double v, bool b) :name(n), value(v), is_const(b) { }
};

// type for var_table and associated functions
class Symbol_table {
public:
    double get(std::string s);                           // return the value of the Variable named s
    void set(std::string s, double d);                   // set the Variable named s to d
    bool is_declared(std::string var);                   // is var already in var_table?
    double declare(std::string var,double val,bool b);   // add (var,val) to var_table
private:
    std::vector<Variable> var_table; // vector of Variables
};



// return the value of the Variable named s
double Symbol_table::get(std::string s)
{
	for (int i = 0; i<var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	error("get: undefined variable");
}

// set the Variable named s to d
void Symbol_table::set(std::string s, double d)
{
	for (int i = 0; i<var_table.size(); ++i)
		if (var_table[i].name == s) {
            if (var_table[i].is_const) error("string is a constant");
			var_table[i].value = d;
			return;
		}
	error("set: undefined variable");
}

// is var already in var_table?
bool Symbol_table::is_declared(std::string var)
{
	for (int i = 0; i<var_table.size(); ++i)
		if (var_table[i].name == var) return true;
	return false;
}

// add (var,val) to var_table
double Symbol_table::declare(std::string var, double val, bool b)
{
    if (is_declared(var)) error("variable declared twice");
    var_table.push_back(Variable(var,val,b));
    return val;
}

// -----------------------------------------------------------------------

Symbol_table st;        // provides get(), set(), is_declared() and declare()
double expression(Token_stream& ts);    // declaration so that primary() can call expression(Token_streamexpression() ts)

// -----------------------------------------------------------------------

// simple power function
// handles only integers >= 0 as exponents
double my_pow(double base, int expo)
{
    if (expo == 0) {
        if (base == 0) return 0;    // special case: pow(0,0)
        return 1;                   // something to power of 0
    }
    double res = base;              // corresponds to power of 1
    for (int i = 2; i<=expo; ++i)   // powers of 2 and more
        res *= base;
    return res;
}

// deal with numbers, unary +/-, parentheses, sqrt, pow, names and assignments
// calls expression()
double primary(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':   // handle '(' expression ')'
	{	double d = expression(ts);
		t = ts.get();
		if (t.kind != ')') error("')' expected");
        return d;
	}
	case '-':
		return - primary(ts);
    case '+':
        return primary(ts);
	case number:
		return t.value;
    case name:
    {   Token t2 = ts.get();    // check next token
        if (t2.kind == '=') {   // handle name '=' expression
            double d = expression(ts);
            st.set(t.name,d);
            return d;
        }
        else {  // not an assignment
            ts.putback(t2);
            return st.get(t.name);
        }
    }
    case square_root:   // handle 'sqrt(' expression ')'
    {   t = ts.get();
        if (t.kind != '(') error("'(' expected");
        double d = expression(ts);
        if (d < 0) error("Square roots of negative numbers... nope!");
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return sqrt(d);
    }
    case power: // handle 'pow(' expression ',' integer ')'
    {   t = ts.get();
        if (t.kind != '(') error("'(' expected");
        double d = expression(ts);
        t = ts.get();
        if (t.kind != ',') error("',' expected");
        t = ts.get();
        if (t.kind != number) error("second argument of 'pow' is not a number");
        int i = int(t.value);
        if (i != t.value) error("second argument of 'pow' is not an integer");
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return my_pow(d,i);
    }
	default:
		error("primary expected");
	}
}

// -----------------------------------------------------------------------

// deal with *, / and %
// calls primary()
double term(Token_stream& ts)
{
	double left = primary(ts);
    Token t = ts.get(); // get the next token from Token_stream

	while (true) {
		switch(t.kind) {
		case '*':
			left *= primary(ts);
            t = ts.get();
			break;
		case '/':
		{	double d = primary(ts);
			if (d == 0) error("divide by zero");
			left /= d;
            t = ts.get();
			break;
		}
        case '%':
        {   double d = primary(ts);
            int i1 = int(left);
            if (i1 != left) error("left-hand operand of % not int");
            int i2 = int(d);
            if (i2 != d) error("right-hand operand of % not int");
            if (i2 == 0) error("%: divide by zero");
            left = i1%i2;
            t = ts.get();
            break;
        }
		default:
			ts.putback(t);  // put t back into the Token_stream
			return left;
		}
	}
}

// -----------------------------------------------------------------------

// deal with + and -
// calls term()
double expression(Token_stream& ts)
{
	double left = term(ts);   // read and evaluate a Term
    Token t = ts.get();     // get the next Token from the Token stream

	while (true) {
		switch(t.kind) {
		case '+':
			left += term(ts); // evaluate Term and add
            t = ts.get();
			break;
		case '-':
			left -= term(ts); // evaluate Term and subtract
            t = ts.get();
			break;
        case '=':
            error("use of '=' outside of a declaration");
		default:
			ts.putback(t);  // put t back into the token stream
			return left;    // finally: no more + or -; return the answer
		}
	}
}

// -----------------------------------------------------------------------

// assume we have seen "let" or "const"
// handle: name = expression
// declare a variable called "name" with the initial value "expression"
double declaration(bool b, Token_stream ts)
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	std::string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of variabl");

	double d = expression(ts);
    st.declare(var_name,d,b);
	return d;
}

// -----------------------------------------------------------------------

// handles declarations and expressions
double statement(Token_stream& ts)
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration(false, ts);
    case con:
        return declaration(true, ts);
	default:
		ts.putback(t);
		return expression(ts);
	}
}

// -----------------------------------------------------------------------

// clean input after error
void clean_up_mess(Token_stream& ts)
{
	ts.ignore(print);
}

// -----------------------------------------------------------------------

// print help instructions
void print_help()
{
    std::cout << "Instructions: enter expressions, there are\n";
    std::cout << "a few functions, you can declare variables using\n";
    std::cout << "the 'let' keyword and constants with the 'const'\n";
    std::cout << "keyword.\n";
}

const std::string prompt = "> ";
const std::string result = "= "; // used to indicate that what follows is a result

// expression evaluation loop
void calculate(Token_stream& ts)
{
	while (std::cin)
    try {
		std::cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get(); // first discard all "prints"
        if (t.kind == help) print_help();   // print help instructions
        else {
            if (t.kind == quit) return;
            ts.putback(t);
            std::cout << result << statement(ts) << std::endl;
        }
	}
	catch(std::exception& e) {
		std::cerr << e.what() << std::endl;   // write error message
		clean_up_mess(ts);
	}
}

// -----------------------------------------------------------------------

int main()
try
{
    // predefine names:
    st.declare("pi",3.1415926535,true);
    st.declare("e",2.7182818284,true);
    st.declare("k",1000,true);
	
	Token_stream ts;

	calculate(ts);

	return 0;
}
catch (std::exception& e) {
	std::cerr << "exception: " << e.what() << std::endl;
	char c;
	while (std::cin>>c && c!=';') ;
	return 1;
}
catch (...) {
	std::cerr << "exception\n";
	char c;
	while (std::cin>>c && c!=';');
	return 2;
}
