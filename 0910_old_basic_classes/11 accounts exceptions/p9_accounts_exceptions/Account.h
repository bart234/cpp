#pragma once

#include "I_Account.h"

class Account:public I_Account
{
    protected:
        std::string acc_name;
        double balance;

    
    public:
        Account(std::string account_name, double start_balance);
        virtual ~Account()=default;

        virtual void deposit(double d)=0;    
        virtual void print(std::ostream &os)const;

        void print_balance();

};

Account::Account(std::string account_name, double start_balance):
        acc_name{account_name},balance{start_balance}{};

//cant be use - it is virtual cls
void Account::print_balance()
{std::cout<<"My balance is: "<< this->balance<<std::endl;}

//cant be use - it is virtual cls
void Account::print(std::ostream &os) const
{os<<"Acc: "<< this->acc_name << ", balance: "<<this->balance;}
