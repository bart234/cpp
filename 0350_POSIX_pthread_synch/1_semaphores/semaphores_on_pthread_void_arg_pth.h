#ifndef MY_SOURCES_H
#define MY_SOURCES_H
#include "my_sources.h" 
#endif

using namespace std;


namespace semaphores_on_pthread_void_arg_pth
{     

    sem_t my_semaphore;

    void* my_function_arg_as_ref(void *arg)
    {   
        //arg - behind that we expect int, thats why we recast on int ptr
        //wait
        sem_wait(&my_semaphore);
        std::cout<<"This is thread: "<<*(int*)arg<<std::endl;
        sleep(4);

        std::cout<<"\nexiting\n"<<std::endl;
        sem_post(&my_semaphore);
        //free(arg);  - why ?why error and why is here
        //we dont need it here because args are passed by ref and they will be destroyed at upper f
    }

    void* my_function2_arg_as_ptr(void *arg)
    {
        //arg - behind in we expect int
        //wait
        sem_wait(&my_semaphore);
                //-----------------------critical section-----------------------
        std::cout<<"This is thread: "<<*(int*)arg<<" and going to sleep"<<std::endl;
        sleep(4);
        std::cout<<"\t"<<*(int*)arg<<": is woke up and exiting, realesing resource"<<std::endl;
                //--------------------end critical section end -----------------------
        sem_post(&my_semaphore);
        free(arg); // our args are ptrs, we need to destroy it
    }

    void run_me_semaphores_two_threads()
    {
        sem_init(&my_semaphore,0,1);

        pthread_t t1;
        pthread_t t2;
        int a{1};
        int b{2};
        pthread_create(&t1, NULL, &my_function_arg_as_ref,&a);
        pthread_create(&t2, NULL, &my_function_arg_as_ref,&b);

        pthread_join(t1,NULL);
        pthread_join(t2,NULL);

        sem_destroy(&my_semaphore);
    }

    void run_me_semaphore_mutiple_threads()
    {
        /*
        we star with semaphore = 1
        - step 1 - first thread ( 0 ) - is decremneting that value and aquire resource
        - step 1 - rest is waiting because semaphore is 0 
        - step 2 - th (0) finishing and setting flag to post(++) 
        - step 2 - another thread eg: 2 - i catching that flag, decrementing it and run
        - step 2 - th0(done), th2(is running), th-1,3,4 are waiting
        */
        unsigned th_number{5};
        sem_init(&my_semaphore,0,1); //<---- initial value of sem is 1
        pthread_t th[th_number];
        int i ;

        for(i =0;i<th_number;i++)
        {
            int *a = new int{i};
            pthread_create(&th[i], NULL, &my_function2_arg_as_ptr,a);
        }

        for(i =0;i<th_number;i++)
        {
            pthread_join(th[i],NULL);
        }
        sem_destroy(&my_semaphore);

    }

    void run_me_semaphore_multiple_threads_sem_eq_2()
    {
        /*
        we star with semaphore = 2
        - step 1 - threads 0 and 1 are first - are decremneting value and aquire resource
        - step 1 - both threads decrement it from 2 to 0, so both will run, and rest wait
        - step 1 - rest is waiting because semaphore is 0 
        - step 2 - th (0) finishing and setting flag to post(++) 
        - step 2 - another thread eg: 2 - i catching that flag, decrementing it and run
        - step 2 - th0(done), th2(is running), th-1,3,4 are waiting
        */
        unsigned th_number{5};
        sem_init(&my_semaphore,0,2); //<---- initial value of sem is 2
        pthread_t th[th_number];
        int i ;

        for(i =0;i<th_number;i++)
        {
            int *a = new int{i};
            pthread_create(&th[i], NULL, &my_function2_arg_as_ptr,a);
        }

        for(i =0;i<th_number;i++)
        {
            pthread_join(th[i],NULL);
        }
        sem_destroy(&my_semaphore);
    }
}
