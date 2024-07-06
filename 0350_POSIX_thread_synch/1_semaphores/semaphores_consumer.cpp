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

    sem_unlink(SEMAPHORE_PRODUCER_ID.c_str());
    sem_unlink(SEMAPHORE_CONSUMER_ID.c_str());
    
    sem_1 = sem_open(SEMAPHORE_PRODUCER_ID.c_str(),O_CREAT,0660,0);    
    sem_2 = sem_open(SEMAPHORE_CONSUMER_ID.c_str(),O_CREAT,0660,1);
    //no error check if semaphore_producer==-1 perror("text") exit(EXIT_FAILURE)

    //----------------------------------DATA CONSUMER------------------------------------------------------            
    //file_descriptor = shm_open(SHM_MAIN_SHMM_ID.data(), O_RDONLY, 0700);    
    file_descriptor = shm_open(SHM_MAIN_SHMM_ID.data(), O_CREAT | O_RDWR, 0700);      
    //no error check
    if(file_descriptor ==-1)
    {
        perror("file descriptior didnt load anything, probably shm is not created");        
        exit(EXIT_FAILURE);
    }

    shm_address = mmap(NULL,BLOCK_SIZE_IN_SHM, PROT_READ, MAP_SHARED, file_descriptor, 0);
    //no error check

    array<char,1024> buffer_for_readed_value{};
    cout<<"Consumer wait: sem_consumer"<<endl;
    //sem_wait(semaphore_consumer);
    

    /* what that loop do:
    - it loop over and over ,it dont have break now
    - function mamcpy will copy data from buffer -it will contain data saved in shmm 
    - that data will be save bit by bit in char array ,
    - we need info how much we should read from shmm- here we will read our buffer max size (1024)
    
     */
    //here:  sem_1: 0 , sem_2: 1
    while(true)
    {   
        //now it will failed - no data there- we need semaphore
        sem_wait(sem_1); //-- on sem_prod thread

            if(shm_address==MAP_FAILED)
            {
                //perror("file descriptior didnt load anything, probably shm is not created"); 
                sleep(1);
                perror("sleep 1s out");    
            }else{
                memcpy(buffer_for_readed_value.data(), shm_address, buffer_for_readed_value.size());
                //no error check 
                
                if(strlen(buffer_for_readed_value.data()) !=0)
                {
                    cout<<"PID: :"<<getpid()<< " consumed: "<< buffer_for_readed_value.data()<<endl;
                }
            }

        sem_post(sem_2);
        

    }
    

    sem_unlink(SEMAPHORE_PRODUCER_ID.data());
    sem_unlink(SEMAPHORE_CONSUMER_ID.data());


    //we have to clear shmm 
    //resized_shm_size= munmap(shm_address, BLOCK_SIZE_IN_SHM);
    //no error check

    file_descriptor = shm_unlink(SHM_MAIN_SHMM_ID.data());
    //no error check

    cout<<"Producer wait: sem_producer"<<endl;
    //sem_post(semaphore_producer);
    

    exit(EXIT_SUCCESS);
}
