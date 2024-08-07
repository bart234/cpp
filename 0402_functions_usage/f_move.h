#include <iostream>

using namespace std;

namespace f_move
{
    void run_me_swap_made_by_move()
    {
        string a{"Abba"};
        string b{"Beta"};

        string c{std::move(a)};

        a = std::move(b);
        b = std::move(c);
    }

    void run_me_swap_made_by_move_ptr()
    {
        string *a = new string("Abba");
        string *b = new string ("Beta");

        cout<<"Before"<<endl;
        cout<<"a: " <<*a<<" --- "<<&a<<endl;
        cout<<"b: " <<*b<<" --- "<<&b<<endl;
        string *c{std::move(a)};

        a = std::move(b);
        b = std::move(c);

        cout<<"After"<<endl;
        cout<<"a: " <<*a<<" --- "<<&a<<endl;
        cout<<"b: " <<*b<<" --- "<<&b<<endl;

        delete a;
        a = nullptr;
        delete b;
        b = nullptr;

        c= nullptr;
    }

}
