#ifndef _SOURCE_H
#include "_source.h"
#endif

//#include <string>

namespace f_numeric_to_string
{
    void run_me_stoi_str_to_int()
    {
        std::cout<<"std::stoi('42') -> "<<std::stoi("42")<<std::endl;
        std::cout<<"std::stoi('101010',nullptr,2) -> "<<std::stoi("101010",nullptr,2)<< " binary system"<<std::endl;
        std::cout<<"std::stoi('052',nullptr,8) -> "<<std::stoi("052",nullptr,8)<< " octal system"<<std::endl;
        std::cout<<"std::stoi('0x2A',nullptr,16) -> "<<std::stoi("0x2A",nullptr,16)<<" hex system"<<std::endl;
    }

    void run_me_standard_to_string()
    {
        std::cout<<"std::to_string(42) -> "<<std::to_string(42)<<std::endl;
        std::cout<<"std::to_string(42.4) -> "<<std::to_string(42.4)<<std::endl;
        std::cout<<"std::to_string(42L) -> "<<std::to_string(42L)<<std::endl;
        std::cout<<"std::to_string(42.0) -> "<<std::to_string(42.0)<<std::endl;
        std::cout<<"std::to_string(42.0L) -> "<<std::to_string(42.0L)<<std::endl;
    }

}