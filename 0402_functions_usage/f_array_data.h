
//array.data() - return a porinter to the first element of array
//cout<<
#include "iostream"
#include "cstring"
#include "array"

namespace f_array_data
{
    void run_me()
    {
        const char* cstr = "test string";       //equiwalent of std::string but in old way
        std::array<char,12> my_arr;             
        std::memcpy(my_arr.data(),cstr,10);     //copy to, copy from, length to copy from
        std::cout<<my_arr.data()<<std::endl;
    }
}
