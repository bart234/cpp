#ifndef SOURCES_H
#define SOURCES_H
#include "sources.h"
#endif

namespace parallel_struct_passed_based_on_yt_done
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