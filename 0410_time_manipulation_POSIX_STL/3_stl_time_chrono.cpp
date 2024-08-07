

/* STL std::chrono
- part of stl
- standarized -on other platform work this same
- type safety - it contain diff kinds of clocks, mesurment 
- can be mixed with low lvl clocks like timespec
- provide time aritmetics, conversion between units, literals, type deduction, lambdas
- can be use in other stl functions

#include <chrono>
clock with diffrent epoch:
- std::chrono::system_clock - RTC (adjustable)
- std::chrono::steady_clock - steady monotonic clock (unaffected for system adjust)
- std::chrono::high_resolution_clock - hrt 

duration:
- std::chrono:duration - class for time intervals, define "tick" and keep number of that ticks - like hours,min,secs
    (like: std::chrono::seconds, ::hours, ::months)

conversions: std::chrono:duration_cast - conversion between durations and std::chrono::time_point_cast
std::chrono::now() - return current time point
calsndars
time_zones

*/

#include <chrono>
#include <iostream>

using namespace std;

//Unfortunately, std::chrono doesn't provide an implementation of operator<< for std::chrono::duration types until C++20.
//g++ -std=c++2a -Wall 3_stl_time_chrono.cpp -o main.exe
//even in c20 there is a problem

static const auto LOOP_LIMIT{40000};
void function_to_delay();
using namespace std::chrono;

namespace simple_mesurment
{
    

    void mesurement_1_simple()
    {
        const auto start_clock{steady_clock::now()};
        function_to_delay();
        const auto end_clock{steady_clock::now()};

        //it mesure in nanosec
        const auto dur{(end_clock-start_clock)};

        //we convert it into what we want
        auto my_mesurment_in_ms{duration_cast<microseconds>(dur)};
        milliseconds my_mesurment_in_mlsec{duration_cast<milliseconds>(dur)};
        seconds my_mesurment_in_sec{duration_cast<seconds>(dur)};

        std::cout<<"Execution time: "<< dur.count()<<std::endl;
        std::cout<<"Execution time: "<< my_mesurment_in_ms.count()<<std::endl;
        std::cout<<"Execution time: "<< my_mesurment_in_mlsec.count()<<std::endl;
        std::cout<<"Execution time: "<< my_mesurment_in_sec.count()<<std::endl;

        seconds rounded_msecs{round<seconds>(my_mesurment_in_mlsec)};
        std::cout<<"Execution time round up: "<< rounded_msecs.count()<<std::endl;
        //c++20 std::cout<<"Execution time round up: "<< rounded_msecs<<std::endl;


    };

    void mesurement_2_ratio_mechanic()
    {
        
        //stable variable equal to 6min
        constexpr std::chrono::duration<int,std::ratio<1>>      six_min_as_360_seconds{360};
        constexpr std::chrono::duration<double,std::ratio<3600>>six_min_as_one_of_ten_hour{1};
        constexpr std::chrono::minutes                          six_min_as_min_variable{6};
        constexpr auto                                          six_min_from_literal_in_deduction{6min};

        std::cout<<six_min_as_360_seconds.count()<<endl;
        std::cout<<six_min_as_one_of_ten_hour.count()<<endl;
        std::cout<<six_min_as_min_variable.count()<<endl;
        std::cout<<six_min_from_literal_in_deduction.count()<<endl;

        //c++20        
        //std::cout<<six_min_as_360_seconds<<endl;            //-> 360s
        //std::cout<<six_min_as_one_of_ten_hour<<endl;        //-> 0.1h
        //std::cout<<six_min_as_min_variable<<endl;           //-> 6min
       //std::cout<<six_min_from_literal_in_deduction<<endl; //-> 6min
        
       

    
    };
};

namespace utility
{
    void linux_epoch()
    {
        time_point<system_clock>linux_epoch;
        //format require
        //std::cout<<format("start date: {0:%F}T{0:%R%z}.", linux_epoch);
    };

    void date_int_into_time()
    {
        std::chrono::year y{2024};
        month m{8};
        day d{22};
        //<< no match
        //cout<<y<<endl;
    }
}


int main()
{
    //simple_mesurment::mesurement_1_simple();
    // simple_mesurment::mesurement_2_ratio_mechanic();
    utility::linux_epoch();
}











void function_to_delay()
{
    for(auto i =0;i<LOOP_LIMIT;i++){
        for(auto a =0;a<LOOP_LIMIT;a++){
            
        }        
    }
}
