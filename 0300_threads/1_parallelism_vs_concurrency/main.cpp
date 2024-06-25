#include <iostream>
#include <pthread.h>
#include <mutex>
#include <sys/wait.h>
#include <vector>
#include <stdlib.h>

#define THREAD_NUM 2

namespace parraleism_vs_concurency
{
    int arr[15] = {1,21,22,1,12,45,2,434,2,4};
    //paralleism - there is no resource race

    namespace base_algorythm
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
    namespace base_algorythm_with_parallel_threads
    {      
        void* f_to_sum_part_of_arr(int& save_result_here, int start_place, int sum_num_of_el)
        {
            int temp{};
            for(int i=start_place;i<start_place+sum_num_of_el;i++){
                temp+=arr[i];
            }
            save_result_here=temp;
        } 

        struct my_args{
            int& ref_result_save_here;
            int i_start_place;
            int sum_num_of_el;
            my_args(int &a, int b,int c):ref_result_save_here{a},i_start_place{b},sum_num_of_el{c}{};
        };

        void* f_to_sum_part_of_arr2(my_args marg)
        {
            int temp{};
            for(int i=marg.i_start_place;i<marg.i_start_place+marg.sum_num_of_el;i++){
                temp+=arr[i];
            }
            marg.ref_result_save_here=temp;
        } 
    }

    namespace  parallel_struct_passed_into_function
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
            
            for(int i=my_temp_struct->i_start_place;i<my_temp_struct->i_start_place+my_temp_struct->sum_num_of_el;i++){
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

    namespace  parallel_pthread_struct_passed_into_function
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
            
            for(int i=my_temp_struct->i_start_place;i<my_temp_struct->i_start_place+my_temp_struct->sum_num_of_el;i++){
                temp+=arr[i];
            }
            my_temp_struct->ref_result_save_here=temp;
            
        } 

        void run_me_race_condition_on_struct_passed_into_thread()
        {
            //todo: fix me - data race? during debug both thread gather data, but after compile,
            //1th thread 
            //there is a ref to my_args2 - it is race condition to save parameters - it will doesnt work
            
            int globalSum{};
            int arr_int[2]{};
            int th_number{2};
            pthread_t th_arr[th_number];                       
            my_args2 my_args_2{};

            for(int i=0;i<2;i++){     
                my_args_2.ref_result_save_here=0;
                my_args_2.i_start_place=i*5;
                my_args_2.sum_num_of_el=5;
                //only one arg can be pass through threac_creation or pass it by one struct with all your args
                pthread_create(&th_arr[i],NULL,&f_to_sum_part_of_arr3,&my_args_2);
                arr_int[i]=my_args_2.ref_result_save_here;
                std::cout<<"For i="<<i<<" result is: "<<arr_int[i]<<std::endl;
            }

            for(int i =0;i<th_number;i++){pthread_join(th_arr[i],NULL);}

            //for(int i =0;i<th_number;i++){delete arr_int[i];}
            //for(auto &el:result_viki){globalSum+=el;}
            //std::cout<<globalSum<<std::endl;
        }    
    }

    namespace  last_one_fix
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

    namespace copyt_from_yt_to_analize_raw
    {
        void *worker(void *arg)
        {
            int index = *(int*)arg;
            int sum =0;
            sleep(1);
            for(int j=0;j<5;j++){
                sum+=arr[index+j];
            }
            printf("Local sum at worker: %d \n",sum);
            *(int*)arg=sum;
            return arg;
        }

        int main()  
        {
            
            pthread_t th_list[THREAD_NUM];
            int i;
            for(i=0; i<THREAD_NUM;i++){
                int *a = new int;
                *a=i*5;
                if(pthread_create(&th_list[i],NULL,&worker,a)){perror("Failed to create thread");}
            }
            int globalSum=0;
            
            for(i=0; i<THREAD_NUM;i++){
               
                int*r;
                if(pthread_join(th_list[i],(void**) &r) !=0){perror("Failed to join thread");}
                globalSum +=*r;
                free(r);
            }
            printf("Global sum %d", globalSum);
            //delete a;
        }
    }

    namespace copyt_from_yt_to_analize_switch_to_struct
    {

        struct my_args2{
            int ref_result_save_here;
            int i_start_place;
            int sum_num_of_el;
        };

        void *worker(void *arg)
        {
            //raw//int index = *(int*)arg;
                    //mid//my_args2 a_2_in = *(my_args2*)arg;
                    //mid//a_2_in.i_start_place;
            int int_from_struct = (*(my_args2*)arg).i_start_place;
            int sum =0;
            sleep(1);
            for(int j=0;j<5;j++){
                //sum+=arr[index+j];
                sum += arr[int_from_struct+j];
            }
            printf("Local sum at worker: %d \n",sum);
            //raw//*(int*)arg=sum;
            //raw//return arg;.
            (*(my_args2*)arg).ref_result_save_here=sum;
            return arg;
        }

        int main()  
        {
            pthread_t th_list[THREAD_NUM];
            int i;
            for(i=0; i<THREAD_NUM;i++){
                my_args2 *a_2= new my_args2;
                a_2->i_start_place=i*5;
                //int *a = new int;
                //*a=i*5;
                if(pthread_create(&th_list[i],NULL,&worker,a_2)){perror("Failed to create thread");}
            }
            int globalSum=0;
            
            for(i=0; i<THREAD_NUM;i++){
               
               //new
                my_args2 *return_obj; 
                //raw//int*r;
                
                if(pthread_join(th_list[i],(void**) &return_obj) !=0){perror("Failed to join thread");}
                //neww
                int get_value_from_return_obj;
                get_value_from_return_obj = (*return_obj).ref_result_save_here;
                globalSum +=get_value_from_return_obj;
                //raww//globalSum +=*r;
                free(return_obj);
            }
            printf("Global sum %d", globalSum);
            //delete a;
        }
    }

}

int main()
{
    //parraleism_vs_concurency::base_algorythm::run_me();
    //parraleism_vs_concurency::base_algorythm_with_parallel_threads::run_me();
    //parraleism_vs_concurency::parallel_struct_passed_into_function::run_me();
    //parraleism_vs_concurency::parallel_pthread_struct_passed_into_function::run_me_race_condition_on_struct_passed_into_thread();
    //parraleism_vs_concurency::last_one_fix::run_me_race_condition_on_struct_passed_into_thread();
    //parraleism_vs_concurency::copyt_from_yt_to_analize_raw::main();
    
    // sum from object correctly restored during switch
    /* done:main task was to pass many values to thread and return it
            many values was made by create struct and pass it into thread as void*arg and recast 
            returned value was aquire by return that void*arg, and recast int struct and extract value
    */
    parraleism_vs_concurency::copyt_from_yt_to_analize_switch_to_struct::main();
}