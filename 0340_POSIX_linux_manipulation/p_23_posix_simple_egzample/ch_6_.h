#ifndef SOURCES_H
#define SOURCES_H
#include "sources.h"

//each thread has its own copy of all object with automatic storage duration - the stack objects
namespace chapter_6_cocurrent_sys_programing
{  
    struct Account
    {
        private:
        unsigned balance;
        std::string owner;

        public:
        Account(std::string_view the_owner, unsigned the_ammount) noexcept:balance{the_ammount},owner{the_owner}{};

        std::string GetBalance() const 
        {
            return "Current account baalnce of " + owner + " is "+ std::to_string(balance)+'\n';
        }
    
        Account& operator+=(unsigned amount) noexcept
        {
            cout<<"Acc: " + owner + " Balance before +=: "<<balance<<endl;        
            auto temp{balance};
            
            std::this_thread::sleep_for(1ms);
            balance =temp+amount;
            cout<<"Acc: " + owner + " Balance after +=: "<<balance<<endl;   
            return *this;
        }

        Account& operator -=(unsigned amount) noexcept
        {
            cout<<"Acc: " + owner + " Balance before -=: "<<balance<<endl;
            auto temp{balance};
            balance = temp-amount;
            cout<<"Acc: " + owner + " Balance after -=: "<<balance<<endl;
            return *this;
        }

        
    };
    void TransferMoney(unsigned ammount, Account &from, Account &to)
        {
            from-=ammount;
            to+=ammount;
        }

    void eg_1_data_race_on_variable()
    {
        cout<<"Run data race:"<<endl;
        Account bill("Bill",100);
        Account alex("Alex",50);

        std::thread first_transfer([&](){TransferMoney(10,bill,alex);});
        std::thread second_transfer([&](){TransferMoney(20,bill,alex);});
        first_transfer.join();
        second_transfer.join();

        std::this_thread::sleep_for(100ms);
        cout<<bill.GetBalance()<<endl;
        
        cout<<alex.GetBalance()<<endl;

        cout<<"End data race"+'\n';
    }

      void run_me()
    {
        cout<<"-------------ch6_start----------------"<<endl;
        eg_1_data_race_on_variable();
        cout<<"-------------ch6_end----------------"<<endl;
    }
    
}
#endif