//#pragma once

#include "Account.h"



class Checking_Account: public Account
{
friend std::ostream &operator<<(std::ostream &os, const Checking_Account &acc);

protected:
    double account_withdraw_fee{default_withdraw_fee_CheckingA};
    
private:
    static constexpr double  default_withdraw_fee_CheckingA =1.5;

public:
    //Checking_Account();
    Checking_Account(double balance, std::string acc_name);
    //deposit -inherited
    bool withdraw(double ammount);
    //get_balance - inherited
};


Checking_Account::Checking_Account(double balance,std::string acc_name):
                Account{balance,acc_name}
                {};
/*
Checking_Account::Checking_Account():
            Checking_Account{
                cosntElements_Account::default_new_ac_balance,
                cosntElements_Account::default_acc_name}
                {};
*/
bool Checking_Account::withdraw(double ammount)
{
    //if((this->in_balance-(ammount+account_withdraw_fee))<0)
    //{
    //    std::cout<<cosntElements_AccountCh::display_withdraw_fee_not_covered<<std::endl;
    //    return false;}
    //else{        
        return  Account::withdraw(ammount+account_withdraw_fee);
    //}

}

std::ostream &operator<<(std::ostream &os, const Checking_Account &acc)
{
    os<<"Account name:(Ch) '"<<acc.in_acc_name   <<"', balance: "<<acc.in_balance<<" Withdraw fee: "<< acc.account_withdraw_fee<<std::endl;
    return os;
}

