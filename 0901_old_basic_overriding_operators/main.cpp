#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::literals::chrono_literals;


namespace ovr_simple_move_ctor_and_move_op
{
    struct Abba
    {        
        std::string name;
        int age;
        std::string* numb{nullptr};

        Abba(std::string name_, int age_):
            name{name_},age{age_}
            {numb = &name;}
        
         //assign op
        Abba& operator=(const Abba& other_abba)
        {
            name =other_abba.name;
            age = other_abba.age;
            cout<<"copy assigned "<<endl;
            return *this;
        }

        //move op
        Abba& operator=(Abba&& other_abba)
        {   
            if(this!=&other_abba)
            {
                age=std::move(other_abba.age);
                name=std::move(other_abba.name);
                other_abba.name.clear();
            }
            cout<<"Move op"<<endl;
            return *this;
        }

        //move ctor
        Abba(Abba&& other_abba):age(std::move(other_abba.age))
        {
            name=std::move(other_abba.name);
            numb=&other_abba.name; //TODO: to fix that
            cout<<"Move ctor"<<endl;
        }

        void print_me(){cout<<"Print me f: " <<name<<"  "<<std::to_string(age)<<" "<<*numb<<endl;}
    };

    void run_me()
    {
        cout<<"Start"<<endl;
        Abba a("My name 1",22);        
        a.name="Kasia";

        Abba b("My second name 2",1);
        a.print_me();
                                            cout<<"assign: replace a: old from a: new from b, and replace 2nd "<<endl;
        a=b;                //assigning copy -  raw a is removing
        a.print_me();

        //Abba c(b);        //copy constructor - require ctor ovr
        //c.print_me();

        Abba d =std::move(a);   //move constructor - done
        d.print_me();

    }
}

namespace ovr_struct_op_with_threading_with_race_cond
{

    struct Account
    {
        private:
            std::string acc_owner;
            unsigned int balance;
        public:
            Account(std::string owner_, unsigned int amm_):
                    acc_owner{owner_},balance{amm_}
                    {};
            std::string getBalance()const
                    {return "Current acc bal: "+ acc_owner + " is "+std::to_string(balance);}

            Account &operator+=(int in_ammount) noexcept
            {
                cout<<"Balance before add dep: "<<std::to_string(balance)<<endl;
                auto temp{balance};
                std::this_thread::sleep_for(1ms);
                balance = temp + in_ammount;
                cout<<"Balance after add dep: "<<std::to_string(balance)<<endl;
                return *this;
            }

            Account &operator-=(int out_ammount) noexcept
            {
                cout<<"Balance before minus dep: "<<std::to_string(balance)<<endl;
                auto temp{balance};
                balance=balance-out_ammount;
                cout<<"Balance after minus dep: "<<std::to_string(balance)<<endl;
                return *this;
            }
    };

    void TransferMoney(unsigned ammount, Account& from, Account &to)
    {
        from -= ammount;
        to +=ammount;
    }

    int run_me()
    {
        Account bill("Bill",100);
        Account alex("Alex",50);

        TransferMoney(10,bill,alex);

        //error: static assertion failed: std::thread arguments must be invocable after conversion to rvalues
        //this is because you put as argument object, but it expect ref, use std::ref(obj)
        std::thread t1(TransferMoney,10,std::ref(bill),std::ref(alex));
        std::thread t2(TransferMoney,10,std::ref(bill),std::ref(alex));

        t1.join();
        t2.join();

        std::this_thread::sleep_for(200ms);
        
        cout<<bill.getBalance()<<endl;
        cout<<alex.getBalance()<<endl;


        return 0;
    }
}

int main()
{
    //ovr_struct_op_with_threading_with_race_cond::run_me();
    ovr_simple_move_ctor_and_move_op::run_me();

    return 0;
}