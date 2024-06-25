#include "my_sources.h"


using namespace std;

namespace semaphores
{
    namespace semaphores_on_phthread
    {     
        sem_t my_semaphore;

        void* my_function_arg_as_ref(void *arg)
        {
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

    namespace semaphores_on_shm_and_diffrent_threads
    {
        string_view SHM_MAIN_SHMM_ID              = "/test_shm";
        string_view SEMAPHORE_PRODUCER_ID         = "/test_shm_prod";
        string_view SEMAPHORE_CONSUMER_ID         = "/test_shm";

        constexpr auto SHM_SIZE = 1024;

        sem_t* semaphore_producer;
        sem_t* semaphore_consumer;

        /*
        Process fork-ing to simulate two application: one produce data, second consume it
        -main fork creating child and going into PRODUCE part - because  child_pid >0
        -child_pid, do not create another,  child_pid have in their instance  variable child_pid ==0 and it going into CONSUME
        */

        void process_creator()
        {
            int resized_shm_size    =0;
            int file_descriptor     =0;
            void *shm_address       =NULL;
            int child_pid           =fork();

            if(child_pid==0)
            {
                //----------------------------------DATA CONSUMER------------------------------------------------------            
                file_descriptor = shm_open(SHM_MAIN_SHMM_ID.data(), O_RDONLY, 0700);    
                //no error check

                shm_address = mmap(NULL,SHM_SIZE, PROT_READ, MAP_SHARED, file_descriptor, 0);
                //no error check

                array<char, SHM_SIZE> buffer_for_readed_value;
                
                sem_wait(semaphore_consumer);

                memcpy(buffer_for_readed_value.data(), shm_address, buffer_for_readed_value.size());
                if(strlen(buffer_for_readed_value.data()) !=0)
                    cout<<"PID: :"<<getpid()<< " consumed: "<< buffer_for_readed_value.data()<<endl;


                sem_post(semaphore_producer);
                exit(EXIT_SUCCESS);


            
            }else if (child_pid > 0){
                //----------------------------------DATA PRODUCER------------------------------------------------------
                //we create and add information into shmm , and consumer will to read it

                // we create file - shmm and pointer to shmm (raw ptr) at location, with privilages to RDWR and file privilages 0700
                // file_descriptor is a int because it keeps pointer to that place 
                file_descriptor = shm_open(SHM_MAIN_SHMM_ID.data(), O_CREAT | O_RDWR, 0700);      
                //no error check

                resized_shm_size = ftruncate(file_descriptor, SHM_SIZE);                            //we specify size of that shmm region by truncate it to 1024 (SHM_SIZE)
                //no error check

                //we  make that memory region shared,
                //we specify max size (SHM_SIZE), 
                shm_address= mmap(NULL, SHM_SIZE, PROT_WRITE, MAP_SHARED, file_descriptor, 0);      
                //no error check

                //we hold up semaphore(could be mutex) at producer to be sure we save data_to_process 
                sem_wait(semaphore_producer);

                string_view data_to_process {"Some data to do something with that"};

                memcpy(shm_address, data_to_process.data(), data_to_process.size()); //this is copy function (adress_in, from, how_many_bytes_to_copy)

                sem_post(semaphore_consumer);
                //we unlock semaphoree so other process can 

                waitpid(child_pid, NULL, 0);
                
                resized_shm_size= munmap(shm_address, SHM_SIZE);
                //no error check
                
                file_descriptor = shm_unlink(SHM_MAIN_SHMM_ID.data());
                //no error check

            }else{

            }

            exit(EXIT_SUCCESS);
        }

        void run_me_shm_fork_one_producer_one_consumer()
        {
            /*
            sem_post(A) - increment and unlock (A will run), 
            sem_wait(B)- decrement and stop (B will wait)
            both processes star in same time, semaphores are use to set them in line, first producer, then consumer
            we set producer to 1 (so it can run first), same time consumer have sem_wait(sem_consumer) mean it -- that flag
                    PRODUCER                                        CONSUMER
                sem_post(semaphore_producer);                                                       - (prod-> 1)        hey producer, you can produce
                                                                sem_wait(semaphore_consumer);       - (consume -> 0)    hey consumer, wait a while, we dont have data for you
                sem_wait(semaphore_producer);                                                       - (prod -> 0)       we set flag to stop, ( here both flags are 0)
                    data save                                                                       - 
                sem_post(semaphore_consumer);                                                       - (consume -> 1) run consumer process
                                                                    data read                       - data are consumed
                                                                sem_post(semaphore_producer);       - (prod - 1) producer can produce it again

    
                    waitpid(child_pid, NULL, 0);                
            */
            
            //create sem identificator by name, return adress of new sem
            semaphore_producer=sem_open(SEMAPHORE_PRODUCER_ID.data(), O_CREAT, 0644, 0); 
            semaphore_consumer=sem_open(SEMAPHORE_CONSUMER_ID.data(), O_CREAT, 0644, 0);

            sem_post(semaphore_producer); // increment semaphores => 1
            process_creator();
            sem_close(semaphore_producer);
            sem_close(semaphore_consumer);
            sem_unlink(SEMAPHORE_PRODUCER_ID.data());
            sem_unlink(SEMAPHORE_CONSUMER_ID.data());
            
        }

    }
}