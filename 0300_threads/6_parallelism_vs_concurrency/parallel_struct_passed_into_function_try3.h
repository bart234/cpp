#ifndef SOURCES_H
#define SOURCES_H
#include "sources.h"
#endif

    namespace  parallel_struct_passed_into_function_try3
    {

        struct my_args2{
            int ref_result_save_here;
            int i_start_place;
            int sum_num_of_el;
        };

        void *f_to_sum_part_of_arr3(void *arg)
        {             
            int temp{};
            struct my_args2 *my_temp_struct;
            my_temp_struct =(my_args2*)arg;
            //sleep(1);
            for(int i=my_temp_struct->i_start_place;i<my_temp_struct->i_start_place+my_temp_struct->sum_num_of_el;i++){
                temp+=arr[i];
            }
            //return value
            my_temp_struct->ref_result_save_here=temp;
            
        } 

        void run_me_race_condition_on_struct_passed_into_thread()
        {
            //todo: fix me - data race? during debug both thread gather data, but after compile,
            //1th thread 
            //there is a ref to my_args2 - it is race condition to save parameters - it will doesnt work
            
            //int globalSum{};
            int arr_int[2]{};
            int th_number{2};
            pthread_t th_arr[th_number];                       
            my_args2 my_args_2[2]{};

            for(int i=0;i<2;i++){     
                my_args_2[i].ref_result_save_here=0;
                my_args_2[i].i_start_place=i*5;
                my_args_2[i].sum_num_of_el=5;
                //only one arg can be pass through threac_creation or pass it by one struct with all your args
                pthread_create(&th_arr[i],NULL,&f_to_sum_part_of_arr3,&my_args_2[i]);
                arr_int[i]=my_args_2[i].ref_result_save_here;
                std::cout<<"For i="<<i<<" result is: "<<my_args_2[i].ref_result_save_here<<std::endl;
            }

            for(int i =0;i<th_number;i++){pthread_join(th_arr[i],NULL);}

            //for(int i =0;i<th_number;i++){delete arr_int[i];}
            //for(auto &el:result_viki){globalSum+=el;}
            //std::cout<<globalSum<<std::endl;
        }    
    }