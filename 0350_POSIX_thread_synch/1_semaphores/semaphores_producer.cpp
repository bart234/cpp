#include "my_sources.h"


int main()
{
    std::string SEMAPHORE_PRODUCER_ID =     "/test_shm_prod";
    std::string SEMAPHORE_CONSUMER_ID =     "/test_shm_cons";
    std::string SHM_MAIN_SHMM_ID =          "/test_shm";
    uint BLOCK_SIZE_IN_SHM =                1024;   
    sem_t* sem_1{nullptr};
    sem_t* sem_2{nullptr};

    int resized_shm_size    =0;
    int file_descriptor     =0;
    void *shm_address       =NULL;

    sem_1 = sem_open(SEMAPHORE_PRODUCER_ID.c_str(),0);    
    sem_2 = sem_open(SEMAPHORE_CONSUMER_ID.c_str(),0);
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
    std::cout<<"Producer wait: sem_proucer, post:sem_consumer"<<endl;
    //sem_wait(semaphore_producer);
    std::vector<std::string> viki{"alfa","beta","gamma","delta"};
    //loop{
    for(auto &el: viki)
    {
        sem_wait(sem_2);
        //string_view data_to_process {"abba beta gamma delta tzeta"};
        string_view data_to_process = el;
        memcpy(shm_address, data_to_process.data(), data_to_process.size()); 
        //this is copy function (adress_in, from, how_many_bytes_to_copy)
        std::cout<<"I saved some data into shmem"<<endl;
        sem_post(sem_1);
    }

    sem_close(sem_1);
    sem_close(sem_2);
    //we unlock semaphoree so other process can 

    //resized_shm_size= munmap(shm_address, BLOCK_SIZE_IN_SHM);
    //no error check
    
    //file_descriptor = shm_unlink(SHM_MAIN_SHMM_ID.data());
    //no error check

    exit(EXIT_SUCCESS);
}