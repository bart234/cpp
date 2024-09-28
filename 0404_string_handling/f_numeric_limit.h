#ifndef _SOURCE_H
#include "_source.h"
#endif

#include <limits>

//https://www.quora.com/Why-is-the-size-of-an-int-in-C-4-bytes-on-most-systems 
//Joydip Datta
//What does it meant by saying size of int is 2 bytes in a 16 bit computer in C language?


namespace f_numeric_limit
{
    void run_numeric_limit_f()
    {
        std::cout<<std::numeric_limits<int>::min()<< " min for int  size of:"<< sizeof(int)<<std::endl;
        std::cout<<std::numeric_limits<int>::max()<< " max for int  size of:"<< sizeof(int)<<std::endl;

        std::cout<<std::numeric_limits<double>::min()<< " min for double  size of:"<< sizeof(double)<<std::endl;
        std::cout<<std::numeric_limits<double>::max()<< " max for double  size of:"<< sizeof(double)<<std::endl;

        std::cout<<std::numeric_limits<float>::min()<< " min for float  size of:"<< sizeof(float)<<std::endl;
        std::cout<<std::numeric_limits<float>::max()<< " max for float  size of:"<< sizeof(float)<<std::endl;

        int test1 = 123123123123; 
        std::cout<<"size of:"<< sizeof(test1)<<std::endl;
    }
}