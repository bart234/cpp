#include <iostream>
/*
    here we can keep previous version and new one
    preprocessor will take what we want to take
    "sum_me" - is used without "version_1 /2" namespace  because it is as inline

*/

#define LIB_VERSION_2

namespace my_count_function
{
    #ifdef LIB_VERSION_1
    inline namespace version_1
    {
        int sum_me(int a, int b){
            std::cout<<"Code v1"<<std::endl;
            return a+b;
        };
    }
    #endif

    #ifdef LIB_VERSION_2
    inline namespace version_2
    {
        int sum_me(int a, int b){
            std::cout<<"Code v2"<<std::endl;
            return a+b+2;
        };
    }
    #endif
}

int main()
{   
    // int this place inline namespace is ommited, and sum is used from active version
    std::cout<<my_count_function::sum_me(1,2)<<std::endl;
}