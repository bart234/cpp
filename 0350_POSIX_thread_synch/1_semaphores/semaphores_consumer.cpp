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

    //sem_unlink(SEMAPHORE_PRODUCER_ID.c_str());
    //sem_unlink(SEMAPHORE_CONSUMER_ID.c_str());
    
    semaphore_producer = sem_open(SEMAPHORE_PRODUCER_ID.c_str(),O_CREAT,0660,0);    
    semaphore_consumer = sem_open(SEMAPHORE_CONSUMER_ID.c_str(),O_CREAT,0660,1);
    //no error check if semaphore_producer==-1 perror("text") exit(EXIT_FAILURE)

    //----------------------------------DATA CONSUMER------------------------------------------------------            
    file_descriptor = shm_open(SHM_MAIN_SHMM_ID.data(), O_RDONLY, 0700);    
    //no error check

    shm_address = mmap(NULL,BLOCK_SIZE_IN_SHM, PROT_READ, MAP_SHARED, file_descriptor, 0);
    //no error check

    array<char,1024> buffer_for_readed_value;
    
    sem_wait(semaphore_consumer);

    memcpy(buffer_for_readed_value.data(), shm_address, buffer_for_readed_value.size());
    if(strlen(buffer_for_readed_value.data()) !=0)
        cout<<"PID: :"<<getpid()<< " consumed: "<< buffer_for_readed_value.data()<<endl;


    sem_post(semaphore_producer);
    exit(EXIT_SUCCESS);

}