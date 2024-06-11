#ifndef _SAVING_ACCOUNT_H_
#define _SAVING_ACCOUNT_H_
#include "Account.h"


class Saving_Account: public Account
{
private:
    static constexpr const char * default_account_name="Saving acc - unnamed";
    static constexpr double default_account_balance=0.0;
    static constexpr const char * account_type="Saving";
public:
    Saving_Account();
    Saving_Account(std::string account_name, double start_balance);
    virtual ~Saving_Account()=default;

    virtual void deposit(double d) override;
    virtual void print(std::ostream &os)const override;

    //inherited
    //print_balance
};

Saving_Account::Saving_Account(
    std::string account_name, double start_balance):
        Account{account_name,start_balance}{};

Saving_Account::Saving_Account():
        Saving_Account{default_account_name,default_account_balance}{};

void Saving_Account::deposit(double d)
{
    this->balance += d + d*0.01;
}    

void Saving_Account::print(std::ostream &os) const
{    os<<account_type<<": "<< this->acc_name << ", balance: "<<this->balance;}




#endif