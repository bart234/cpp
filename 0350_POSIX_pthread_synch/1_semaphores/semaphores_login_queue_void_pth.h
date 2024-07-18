#ifndef MY_SOURCES_H
#define MY_SOURCES_H
#include "my_sources.h" 

using namespace std;

sem_t my_semaphore;

namespace semaphores_login_queue_void_pth
{   
    void* user_login_logic(void * args)
    {
        cout<<"User place in queue: "<<*(int*)args<<endl;
        sem_wait(&my_semaphore);

            cout<<"User: "<<*(int*)args<<" is playing"<<endl;
            std::srand(std::time(nullptr));
            sleep(rand()%5+1);              //user plays for random time            
            cout<<"\tUser: "<<*(int*)args<<" logged out"<<endl;

        sem_post(&my_semaphore);
        free(args);
    }

    void run_me_semaphores_login_queue()
    {
        unsigned th_number =16;         //we have 16 users trying to play
        pthread_t th_shelf[th_number];  // where we keep out threads :)

        sem_init(&my_semaphore,0,4);  //<--- only 4 ppl at once can log in, rest have to w8 to free slot


        int f;
        for(f=0;f<th_number;f++)
        {
            int *f_int_ptr = new int{f};
            pthread_create(&th_shelf[f],NULL,&user_login_logic,f_int_ptr);
            
        }

        for(f=0;f<th_number;f++)
        {
            pthread_join(th_shelf[f],NULL);
        }
    }
}

#endif