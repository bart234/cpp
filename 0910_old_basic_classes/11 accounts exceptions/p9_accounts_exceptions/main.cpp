#include "Acc_util.h"

//TODO: add exception classes to catch it input ammmount in add or in constructor is less then 0
//      make  that ex classes inherit from  std::excepion and override .what funciton to prin info
int main()
{
    std:shared_ptr<Account> c{new Saving_Account};
    c->deposit(1000);
    //cout<<*c<<endl;

    std::shared_ptr<Account> d{new Checking_Account{"Abba",12.4}};

    d->deposit(1000);
    //cout<<*d<<endl;

    Acc_util ut;
    ut.viki.push_back(c);
    ut.viki.push_back(d);
    ut.print_info();


    return 0;
}