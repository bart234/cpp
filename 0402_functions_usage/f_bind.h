#include <iostream>
#include <functional>
#include <memory>

//it is bind function test and usage
// functon which can launch function and args of that fuction from bind function
// we can use placeholders like _1 _2 _3 to make "expectation" of arg during use that binded form
// how to build: std::bind(<function_name>, arg1-raw value or placeholder, arg2-...)
//               can have 0 arg (all can be const numbers) or many args

using namespace std::placeholders; //it allow to get acces to variable _1, _2, _3...
using namespace std;

namespace bind_test
{
    double my_div(double a, double b){return a/b;}

    struct My2d
    {
        private:
        unsigned a,b;

        public:
        My2d(unsigned _a,unsigned _b):a{_a},b{_b}{};

        unsigned multiple(){return a*b;};
        void printMe(){cout<<"This is printMe function on numbers: " +std::to_string(a) + " and " + std::to_string(b)<<endl;;};

    };

    void simple_f_args_bind()
    {
        
        auto return_f = std::bind(my_div,10,5);
        cout<<"Return function with arg from bind: "+std::to_string(return_f())+'\n';

        auto return_bind_half_args = std::bind(my_div,_1,2);
        //double v1= 6;
        cout<<"Return function with one arg -return_f(v1)- from bind: "+std::to_string(return_bind_half_args(6))+'\n';

        auto return_bind_switch_arg=std::bind(my_div,_2,_1);
        double v2=12;
        cout<<"Return function with two switched arg -std::bind(my_div,_2,_1)- from bind: "+std::to_string(return_bind_switch_arg(2,v2))+'\n';
    }

    void bind_object_and_its_action()
    {
        // std::bind creating object which is reusable for other objects
        My2d d2d{2,3};
        My2d d2d_2{10,22};
        auto r_1 = std::bind(&My2d::printMe,_1);   
        //here bind launch My2d::printMe function without any args
        r_1(d2d);
        r_1(d2d_2);
    }
};