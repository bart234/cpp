
#include <iostream>
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
//todo: add class person as a basic element in to account
//TODO: make person shared ptr - can have many accounts
//TODO: restrict person to have only 1 account per kind of acc
//TODO:add overriding  + and - to remove and add ammount
//TODO: write move anc copy constructor to improve performance
//TODO: prepare util class to manage mass testing 



using namespace std;

int main()

{
    //Trust_Account t1();
    Trust_Account t2(50,1.5,"Trust Bart's acc");
    cout<<0<<endl;
    cout<<t2<<endl;
    cout<<1<<endl;
    if(t2.deposit(6000.0))
        {
        cout<<t2<<endl;}
    cout<<2<<endl;
    if(t2.deposit(100.0))
        {
        cout<<t2<<endl;}
cout<<3<<endl;
    if(t2.withdraw(10))
        {
        cout<<t2<<endl;}
cout<<4<<endl;
    if(t2.withdraw(50))
        {
        cout<<t2<<endl;}
    

    std::cout<<"----------------------------"<<std::endl;
/*
    
    Checking_Account a3{1000.0,"Bart's Acc"};    
    cout<<a3<<endl;

    
    if(a3.deposit(-10.0))
        cout<<a3<<endl;
    
    if(a3.deposit(100.0))
        cout<<a3<<endl;

    if(a3.withdraw(1000))
        cout<<a3<<endl;

    if(a3.withdraw(50))
        cout<<a3<<endl;

    std::cout<<"----------------------------"<<std::endl;

    Savings_Account a1{1000.0,5.0};    
    cout<<a1<<endl;

    if(a1.deposit(-10.0))
        cout<<a1<<endl;

    if(a1.withdraw(1000))
        cout<<a1<<endl;

    if(a1.withdraw(50))
        cout<<a1<<endl;
    
    std::cout<<"----------------------------"<<std::endl;
        Savings_Account a1_1{1000.0,5.0,"Ola's account"};    
    cout<<a1_1<<endl;

    if(a1_1.deposit(-10.0))
        cout<<a1_1<<endl;

    if(a1_1.withdraw(1000))
        cout<<a1_1<<endl;

    if(a1_1.withdraw(50))
        cout<<a1_1<<endl;
    
    std::cout<<"----------------------------"<<std::endl;
    Account a2{1000.0,"Bart's Acc"};    
    cout<<a2<<endl;

    if(a2.deposit(-10.0))
        cout<<a2<<endl;
    
    if(a2.deposit(100.0))
        cout<<a2<<endl;

    if(a2.withdraw(1000))
        cout<<a2<<endl;

    if(a2.withdraw(50))
        cout<<a2<<endl;    
   
*/
    return 0;
}