#ifndef SOURCES_H
#define SOURCES_H
#include "sources.h"
#endif


//paralleism - there is no resource race

namespace parraleism_base_algorythm
{      
    void f_to_sum_part_of_arr(int& save_result_here, int start_place, int sum_num_of_el)
    {
        int temp{};
        for(int i=start_place;i<start_place+sum_num_of_el;i++){
            temp+=arr[i];
        }
        save_result_here=temp;
    } 

    void run_me()
    {
        int globalSum{};
        std::vector<int> result_viki{};

        for(int i=0;i<2;i++){
            result_viki.push_back(0);
            f_to_sum_part_of_arr(result_viki[i],i*5,5);
            std::cout<<"For i="<<i<<" result is: "<<result_viki[i]<<std::endl;
        }
        for(auto &el:result_viki){globalSum+=el;}
        std::cout<<globalSum<<std::endl;
    }
}