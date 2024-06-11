#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>  


namespace semaphores
{
    namespace semaphores_on_phthread
    {     
        sem_t my_semaphore;

        void* my_function2(void *arg)
        {
            //wait
            sem_wait(&my_semaphore);
            std::cout<<"Enter"<<std::endl;
            std::cout<<arg<<std::endl;
            //printf("Enter '%s' ",a);                     //#include <stdio.h>  

            sleep(4);

            std::cout<<"\nexiting\n"<<std::endl;
            sem_post(&my_semaphore);
            
        }

        void run_me_semaphores_1()
        {
            sem_init(&my_semaphore,0,1);

            pthread_t t1;
            pthread_t t2;
            std::string a{"1"};
            std::string b{"2"};
            pthread_create(&t1, NULL, my_function2,&a);
            pthread_create(&t2, NULL, my_function2,&b);

            pthread_join(t1,NULL);
            pthread_join(t2,NULL);

            sem_destroy(&my_semaphore);
        }

        
       
    }

    namespace semaphores_logic_1
    {

        sem_t my_semaphore;
        std::vector<int> viki{};

        void my_process_to_produce()
        {
            
        }

        void my_proces_to_consume()
        {

        }

        void run_my()
        {

        }

    }

}