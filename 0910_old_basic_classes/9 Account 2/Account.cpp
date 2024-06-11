#include "Account.h"


//Account outside functions
bool Account::withdraw(double amount){
    if ((balance - amount) >=0){
        balance -= amount;
        return true;}
    else{
        return false;
    }
}

bool Account::deposit(double amount){
    balance += amount;
    return true;
}

void Account::set_name(std::string n){
    name = n;
}

std::string Account::get_name(){
    return name;
}


