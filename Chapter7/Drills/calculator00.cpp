/*
Simple calculator program, the grammer:

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
Number:
    floating-point-literal
*/

#include<iostream>
#include<stdexcept>

class Token
{
    public:
        char kind;
        double value;
        Token(char ch)
            :kind(ch), value(0){}
        Token(char ch, double val)
            :kind(ch), value(val){}
};

class Token_stream
{
    public:
        Token_stream();
        Token get();
        void putback(Token t);
    private:
        bool full;
        Token buffer;
};

Token_stream::Token_stream()
    :full(false), buffer(0){}

void Token_stream::putback(Token t)
{
    if(full) 
        throw std::runtime_error("putback() into a full buffer");
    buffer=t;
    full=true;
}

Token Token_stream::get()
{
    if (full)
    {
        full=false;
        return buffer;
    }

    char ch;
    std::cin>>ch;
    switch(ch)
    {
        case ';':
        case 'q': 
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(ch);
        case'.':
        case'0': case'1': case'2': case'3': case'4':
        case'5': case'6': case'7': case'8': case'9':
        {
           std::cin.putback(ch);
           double val;
           std::cin>>val;
           return Token('8', val);
        }
        default: throw std::runtime_error("Bad Token");
    }
}

Token_stream ts;
double primary();
double term();
double expression();

int main()
    try
    { 
        double val=0;

        std::cout << "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers. (press 'q' to quit and ';' to enter expression)" << std::endl;

        while(std::cin)
        {
            Token t=ts.get();
            if(t.kind=='q') break;
            if(t.kind==';') std::cout<<"="<<val<<std::endl;
            else ts.putback(t);
            val=expression();
        }
    }
    catch (std::exception& e)
    {
        std::cerr<<e.what()<<std::endl;
        return 1;
    }
    catch(...)
    {
        std::cerr<<"exception \n"<<std::endl; 
        return 2;
    }

double primary()
{
    Token t=ts.get();
    switch(t.kind)
    {
        case'(':
        {
            double d=expression();
            t=ts.get();
            if(t.kind!=')') throw std::runtime_error("')' expected");
            return d;
        }
        case '8':
            return t.value;
        default:
            throw std::runtime_error("primary expected!");
    }
}

double term()
{
    double left=primary();
    Token t=ts.get();
    while(true)
    {
        switch(t.kind)
        {
            case '*':
                left*=primary();
                t=ts.get(); 
                break;
            case '/':
            {
                double d=primary();
                if(d==0) throw std::runtime_error("Divide by zero!");
                left/=d;
                t=ts.get(); 
                break;           
            }
            default: 
                ts.putback(t);
                return left;
        }
    }
}

double expression()
{
    double left=term();
    Token t=ts.get();
    while(true)
    {
        switch(t.kind)
        {
            case '+':
                left+=term();
                t=ts.get();
                break;
            case '-':
                left-=term();
                t=ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}
