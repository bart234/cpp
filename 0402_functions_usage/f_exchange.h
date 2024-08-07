#include <iostream>
#include <utility>

/*
exchange - replace value with new value and return old value

*/

namespace f_exchange
{
    void run_me_like_swap()
    {
        int a{22};
        int b{1};
        std::cout<<"Before: a:"<<a<<" b:"<<b<<std::endl;
        int return_from_ex {std::exchange(a,b)};                //std::exchange(<returned value>, <new value>)
        std::cout<<"After: a:"<<a<<" b:"<<b<<std::endl;
        std::cout<<"Return value: "<<return_from_ex<<std::endl;
    }

}