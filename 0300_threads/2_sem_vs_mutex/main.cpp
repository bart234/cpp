#include <iostream>
#include <mutex>
#include <semaphore.h>
#include <sys/wait.h>

using namespace std;

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

namespace enable_disable_in_diff_threads_semaphores
{
    //copy of namespace sem_vs_mutex but modified
    pthread_mutex_t my_mutex;
    sem_t my_semaphore;
    int my_resource{};

    void work(){
        my_resource++;
        cout<<"My resource is: "<<my_resource<<endl;
    }

    void* some_work_2_semaphore_wait_here(void* args){   
        sem_wait(&my_semaphore);
            //critical section
            work();
    }

    void* some_work_2_semaphore_post_here(void* args){  
        cout<<"sem_post - thread"<<endl;
        sem_post(&my_semaphore);
    }

    void run_me_common_semaphore()
    {
        unsigned th_number{6};
        pthread_t th_arr[th_number];

        sem_init(&my_semaphore,0,1);
        for(int i =0; i<th_number;i++){
            if(i%2==0){
                if ( pthread_create(&th_arr[i],NULL,&some_work_2_semaphore_wait_here,NULL) != 0)
                    perror("Thread creation fcout");              
            }else{
                if ( pthread_create(&th_arr[i],NULL,&some_work_2_semaphore_post_here,NULL) != 0)            
                    perror("Thread creation failed");            
            }
                      
        }

        for(int i =0; i<th_number;i++){
            pthread_join(th_arr[i],NULL);
        }

        pthread_mutex_destroy(&my_mutex);
    }

}

namespace ena_dis_in_diff_threads_semaphores_while_l
{
    //copy of namespace sem_vs_mutex but modified
    pthread_mutex_t my_mutex;
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

        pthread_mutex_destroy(&my_mutex);
    }

}

int main()
{
    //both are out of race condition and are synchronized
    //sem_vs_mutex::run_me_common_mutex();
    //sem_vs_mutex::run_me_common_semaphore();

    //it is not free of race condition

    /* semaphor is changes in another thread, not in same after use resource
    */
    //enable_disable_in_diff_threads_semaphores::run_me_common_semaphore();

    /*here semaphor is change in diffrent thread, but here recource is relesed after 1 second
    and it is not race free, it launch 4 threads at once
    */
    ena_dis_in_diff_threads_semaphores_while_l::run_me_common_semaphore();

    /*
    mutex - have concept of ownership, and it expect to be closed in same thread, if you dont -> undefined bhw
    semaphores - you can set wait and post in diffrent threads - more primitive then mutex
    */
}