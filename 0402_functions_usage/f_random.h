#ifndef _SOURCE_H
#include "_source.h"
#endif

#include <random>
#include <chrono>

/*
    1th: we need some engine to generate random numers like std::random_device my_dev{}
    2nd: generate random seed from engine auto my_generator_ssed = std::mt19937{ my_dev()}      //19937bits  - i is internal storage size
    3th: hey create me generator to create numbers between 1-6 
            auto my_1_6_gen = std::uniform_int_distribution<>{1,6};
        - there is variety of class distribution - it convert engine output into statistical distribution 
        - like uniform: uniform_int_distribution ... bernoulli: geometric_distribution... poisson... normal.. samplin 
    4th: put seed int generator and make numbers
    --- use function from engine  to generate numbers --

    availible engines:
    random_device                   - it suppose to return pseudo random numbers
    linear_congruential_engine      - medium fast , small storage for internal usage
    mersenne_twister_engine         - slowest, greathest storage duration,  but produce longest not reapiting sequence of pseudo-numbers
    substract_with_carry_engine     -fase even on machines with lack of arithemtic instruction at procesor,require larger storage   

*/

namespace f_random
{
    void print_my_generator(auto &generator_with_seed);

    void run_me_random_with_seed_from_time()
    {
        auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        auto generator_with_time_seed = std::mt19937{static_cast<unsigned int>(seed)};
        print_my_generator(generator_with_time_seed);

    }

    void run_me_random_gen_basic_1_to_6()
    {
        std::random_device my_dev{};
        auto my_seed = std::mt19937{ my_dev()};
        auto my_1_6_generator = std::uniform_int_distribution<>{1,6};

        for(int a =0;a<10;a++)
        {
            std::cout<< std::to_string(my_1_6_generator(my_seed))<<" ";
        }
    }

    void print_my_generator(auto &generator_with_seed)
    {
        auto my_1_6_generator = std::uniform_int_distribution<>{1,6};
        for(int a =0;a<10;a++)
        {
            std::cout<< std::to_string(my_1_6_generator(generator_with_seed))<<" ";
        }
    }
}