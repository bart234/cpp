#pragma once
#include "Account.h"
#ifndef _SAV_ACCOUNT_H_
#define __SAV_ACCOUNT_H_


class Savings_Account: public Account
{
    friend std::ostream &operator<<(std::ostream &os,const Savings_Account &acc);
protected:
    double in_int_rate;
private:
    static constexpr double default_balance_ammount_for_SavingA =0.0;
    static constexpr double default_intrest_rate_for_SavingA =0.0;
    static constexpr const char *default_acc_name ="Savings acc unnamed";
    static constexpr const char *display_when_int_rate_didnt_set ="Error: intrest rate did not set!";

public:
    Savings_Account();
    Savings_Account(double balance, double int_rate);
    Savings_Account(double balance, double int_rate,std::string acc_name);
    bool deposit(double ammount);
    //withdraw - inherited
    //get_balance - inherited
};

Savings_Account::Savings_Account(double balance, double int_rate,std::string acc_name):
                Account(balance,acc_name),in_int_rate{int_rate}{};

Savings_Account::Savings_Account(double balance, double int_rate=default_intrest_rate_for_SavingA):
                Account(balance,default_acc_name),in_int_rate{int_rate}{};

Savings_Account::Savings_Account():
                Account{
                    default_balance_ammount_for_SavingA,
                    default_acc_name}, in_int_rate{default_intrest_rate_for_SavingA}{};


bool Savings_Account::deposit(double amount)
{
    if(this->in_int_rate ==0.0)
    {   
        std::cout<<display_when_int_rate_didnt_set<<std::endl;
        return false;}
    else
    {
        amount = (amount+this->in_int_rate/100);
        return Account::deposit(amount);}
}


std::ostream &operator<<(std::ostream &os, const Savings_Account &acc)
{
    os<<"Account name:(S) '"<<acc.in_acc_name   <<"', balance: "<<acc.in_balance<<" Interest rate: "<< acc.in_int_rate;
    return os;
}

#endif