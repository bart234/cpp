#ifndef SOURCES_H
#define SOURCES_H
#include "sources.h"
#endif
namespace  parallel_struct_passed_into_function_try1
{
    struct my_args2{
        int ref_result_save_here;
        int i_start_place;
        int sum_num_of_el;
    };

    void* f_to_sum_part_of_arr3(void *arg)
    {             
        int temp{};
        struct my_args2 *my_temp_struct;
        my_temp_struct =(my_args2*)arg;
        
        for(int i=my_temp_struct->i_start_place;
            i<my_temp_struct->i_start_place+my_temp_struct->sum_num_of_el;
            i++)
        {
            temp+=arr[i];
        }
        my_temp_struct->ref_result_save_here=temp;            
    } 

    void run_me()
    {
        int globalSum{};
        std::vector<int> result_viki{};
        int *arr_int[2]{};
        int th_number{2};
        //pthread_t th_arr[th_number];            

        for(int i=0;i<2;i++){                
            my_args2 my_args_2{};
            my_args_2.ref_result_save_here=0;
            my_args_2.i_start_place=i*5;
            my_args_2.sum_num_of_el=5;
            //only one arg can be pass through threac_creation or pass it by one struct with all your args
            //pthread_create(&th_arr[i],NULL,&f_to_sum_part_of_arr3,my_args_1);
            f_to_sum_part_of_arr3(&my_args_2);
            std::cout<<"For i="<<i<<" result is: "<<my_args_2.ref_result_save_here<<std::endl;
        }

        for(int i =0;i<th_number;i++){delete arr_int[i];}
        //for(auto &el:result_viki){globalSum+=el;}
        //std::cout<<globalSum<<std::endl;
    }  
}