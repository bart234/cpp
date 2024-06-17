#include "my_sources.h"


int main()
{
    std::string SEMAPHORE_PRODUCER_ID =     "/test_shm_prod";
    std::string SEMAPHORE_CONSUMER_ID =     "/test_shm_cons";
    std::string SHM_MAIN_SHMM_ID =          "/test_shm";
    uint BLOCK_SIZE_IN_SHM =                1024;   
    sem_t* semaphore_producer{nullptr};
    sem_t* semaphore_consumer{nullptr};

    int resized_shm_size    =0;
    int file_descriptor     =0;
    void *shm_address       =NULL;

    sem_unlink(SEMAPHORE_PRODUCER_ID.c_str());
    sem_unlink(SEMAPHORE_CONSUMER_ID.c_str());
    
    semaphore_producer = sem_open(SEMAPHORE_PRODUCER_ID.c_str(),O_CREAT,0660,0);    
    semaphore_consumer = sem_open(SEMAPHORE_CONSUMER_ID.c_str(),O_CREAT,0660,1);
    //no error check if semaphore_producer==-1 perror("text") exit(EXIT_FAILURE)

    //---------------------------------------------------------------------------------

    file_descriptor = shm_open(SHM_MAIN_SHMM_ID.data(), O_CREAT | O_RDWR, 0700);      
    //no error check

    resized_shm_size = ftruncate(file_descriptor, BLOCK_SIZE_IN_SHM);                            //we specify size of that shmm region by truncate it to 1024 (SHM_SIZE)
    //no error check

    //we  make that memory region shared,
    //we specify max size (SHM_SIZE), 
    shm_address= mmap(NULL, BLOCK_SIZE_IN_SHM, PROT_WRITE, MAP_SHARED, file_descriptor, 0);      
    //no error check

    //we hold up semaphore(could be mutex) at producer to be sure we save data_to_process 
    sem_wait(semaphore_producer);

        string_view data_to_process {"Some data to do something with that"};

        memcpy(shm_address, data_to_process.data(), data_to_process.size()); //this is copy function (adress_in, from, how_many_bytes_to_copy)

    sem_post(semaphore_consumer);
    //we unlock semaphoree so other process can 
    resized_shm_size= munmap(shm_address, BLOCK_SIZE_IN_SHM);
    //no error check
    
    file_descriptor = shm_unlink(SHM_MAIN_SHMM_ID.data());
    //no error check

    exit(EXIT_SUCCESS);
}