#ifndef SOURCES_H
#define SOURCES_H
#include "sources.h"
#endif

namespace sem_vs_mutex
{
    pthread_mutex_t my_mutex;
    sem_t my_semaphore;
    int my_resource{};

    void work(){
        my_resource++;
        cout<<"My resource is: "<<my_resource<<endl;
    }


    void* some_work_1_mutex(void *args){
        pthread_mutex_lock(&my_mutex);
            //critical section
            work();
        pthread_mutex_unlock(&my_mutex);
    }


    void* some_work_2_semaphore(void* args){   
        sem_wait(&my_semaphore);
            //critical section
            work();
        sem_post(&my_semaphore);
    }

    void run_me_common_mutex()
    {
        unsigned th_number{5};
        pthread_t th_arr[th_number];

        pthread_mutex_init(&my_mutex,NULL);
        for(int i =0; i<th_number;i++){
            if ( pthread_create(&th_arr[i],NULL,&some_work_1_mutex,NULL) != 0)
            {
                perror("Thread creation failed");
            }            
        }

        for(int i =0; i<th_number;i++){
            pthread_join(th_arr[i],NULL);}

        pthread_mutex_destroy(&my_mutex);
    }

    void run_me_common_semaphore()
    {
        unsigned th_number{5};
        pthread_t th_arr[th_number];

        sem_init(&my_semaphore,0,1);
        for(int i =0; i<th_number;i++){
            if ( pthread_create(&th_arr[i],NULL,&some_work_2_semaphore,NULL) != 0)
            {
                perror("Thread creation failed");
            }            
        }

        for(int i =0; i<th_number;i++){
            pthread_join(th_arr[i],NULL);
        }

        pthread_mutex_destroy(&my_mutex);
    }
}