#include "sources.h"
constexpr auto MAX_SIZE = 50;



namespace shm_egz_one
{
    //moved into 0350.1
    string_view SHM_MAIN_SHMM_ID        = "/test_shm";
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
