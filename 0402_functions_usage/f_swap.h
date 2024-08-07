#include <iostream>
#include <utility>

using namespace std;

namespace f_swap
{

    void run_me()
    {
        std::string *a = new std::string("abba");

        std::string *b = new std::string("beta");

        std::string *c {nullptr};
        cout<<"Before:"<<endl;
        cout<<"a: " <<*a<<" --- "<<&a<<endl;
        cout<<"b: " <<*b<<" --- "<<&b<<endl;

        c=a;
        a=b;
        b=c;
        
        cout<<"After"<<endl;
        cout<<"a: " <<*a<<" --- "<<&a<<endl;
        cout<<"b: " <<*b<<" --- "<<&b<<endl;


        delete a;
        a = nullptr;
        delete b;
        b = nullptr;
         
        c = nullptr;
    }

    void run_me_swap()
    {
        std::string *a = new std::string("abba");

        std::string *b = new std::string("beta");

        cout<<"Before:"<<endl;
        cout<<"a: " <<*a<<" --- "<<&a<<endl;
        cout<<"b: " <<*b<<" --- "<<&b<<endl;

        std::swap(*a,*b);
        
        cout<<"After"<<endl;
        cout<<"a: " <<*a<<" --- "<<&a<<endl;
        cout<<"b: " <<*b<<" --- "<<&b<<endl;

        delete a;
        a = nullptr;
        delete b;
        b = nullptr;
    }
    void run_me_swap_ptrs()
    {
        std::string *a = new std::string("abba");

        std::string *b = new std::string("beta");

        cout<<"Before:"<<endl;
        cout<<"a: " <<*a<<" --- "<<&a<<endl;
        cout<<"b: " <<*b<<" --- "<<&b<<endl;

        std::swap(a,b);
        
        cout<<"After"<<endl;
        cout<<"a: " <<*a<<" --- "<<&a<<endl;
        cout<<"b: " <<*b<<" --- "<<&b<<endl;

        delete a;
        a = nullptr;
        delete b;
        b = nullptr;
    }
}