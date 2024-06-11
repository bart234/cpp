#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"

class Checking_Account:public Account
{
private:
    /* data */
    static constexpr const char * default_account_name="Checking acc - unnamed";
    static constexpr double default_account_balance=0.0;
    static constexpr const char * account_type="Checking";
public:
    virtual void deposit(double d) override;
    //print_balance - ihnerited
    Checking_Account();
    Checking_Account(std::string account_name, double start_balance);
    virtual ~Checking_Account()=default;

    virtual void print(std::ostream &os)const;

};

Checking_Account::Checking_Account(
    std::string account_name, double start_balance):
        Account{account_name,start_balance}{};

Checking_Account::Checking_Account():
    Checking_Account{default_account_name,default_account_balance}{};

void Checking_Account::deposit(double d) 
    {
        this->balance +=d;
    };

void Checking_Account::print(std::ostream &os) const
{
    os<<account_type<<": "<< this->acc_name << ", balance: "<<this->balance;
}

#endif // _CHECKING_ACCOUNT_H_
