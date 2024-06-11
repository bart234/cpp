#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <string>

class Account
{
friend std::ostream& operator <<(std::ostream & os, const Account &acc);
private:
    static constexpr double default_balance_ammount_for_A = 0.0;    
    static constexpr const char *display_when_lack_of_funds ="Insufficient funds";
    static constexpr const char *default_acc_name ="Unnamed account";
    static constexpr const char *display_when_ammount_lt_zero ="Inproperly money ammount";

protected:
    double in_balance;
    std::string in_acc_name;
    
public:
    Account();
    Account(double balance, std::string acc_name);
    bool deposit(double ammount);
    bool withdraw(double ammount);

    double get_balance(){return this->in_balance;};
};

Account::Account():Account{
                    default_balance_ammount_for_A,  
                    default_acc_name}
                    {}
Account::Account(   double balance=default_balance_ammount_for_A,
                    std::string acc_name=default_acc_name):
                        in_balance{balance},in_acc_name{acc_name}
                    {};
bool Account::deposit(double ammount)
{
    if(ammount<0)
    {
        std::cout<<display_when_ammount_lt_zero<<std::endl;
        return false;}
    else{
        this->in_balance+=ammount;
        return true;}
}

bool Account::withdraw(double ammount)
{
    if(this->in_balance<ammount)
    {
        std::cout<<display_when_lack_of_funds<<std::endl;
        return false;}
    else{
        this->in_balance-=ammount;
        return true;}
}

std::ostream& operator <<(std::ostream&os, const Account &acc)
{   os<<"Account name:" <<acc.in_acc_name <<", Account balance: "<<acc.in_balance;
    return os;
}

#endif