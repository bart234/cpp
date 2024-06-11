#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account{
    private:
        //atrr
        std::string name;
        double balance {0.0}; 
        
    public:   
        //meth
        //declared in line
        void set_balance(double bal){balance = bal;}
        double get_balance() {return balance;}
        
        //method will be declared outside class
        //prototypes
        void set_name(std::string n);
        std::string get_name();
        
        bool deposit(double amount);
        bool withdraw(double amount);
};

#endif // _ACCOUNT_H_
