
#ifndef SOURCES_H
#define SOURCES_H
#include "sources.h"
#endif


namespace ena_dis_in_diff_threads_semaphores_while_l
{
    //copy of namespace sem_vs_mutex but modified
    //pthread_mutex_t my_mutex;
    sem_t my_semaphore;
    int my_resource{};

    void work(){
        my_resource++;
        cout<<"My resource is: "<<my_resource<<endl;
    }

    void* some_work_2_semaphore_wait_here(void* args){   
        while(1){
            sem_wait(&my_semaphore);
            //critical section
            work();
        }        
    }

    void* some_work_2_semaphore_post_here(void* args){  
        while(1){
            cout<<"sem_post - thread"<<endl;
            sem_post(&my_semaphore);
            sleep(3);
        }
        
    }

    void run_me_common_semaphore()
    {
        unsigned th_number{6};
        pthread_t th_arr[th_number];

        sem_init(&my_semaphore,0,1);
        for(int i =0; i<th_number;i++){
            if(i%2==0){
                if ( pthread_create(&th_arr[i],NULL,&some_work_2_semaphore_wait_here,NULL) != 0)
                    perror("Thread creation failed");              
            }else{
                if ( pthread_create(&th_arr[i],NULL,&some_work_2_semaphore_post_here,NULL) != 0)            
                    perror("Thread creation failed");            
            }
                      
        }

        for(int i =0; i<th_number;i++){
            pthread_join(th_arr[i],NULL);
        }

        //pthread_mutex_destroy(&my_mutex);
    }

}