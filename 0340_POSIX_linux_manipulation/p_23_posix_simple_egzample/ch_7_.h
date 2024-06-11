#include "sources.h"
constexpr auto MAX_SIZE = 50;


namespace chapter_7_concurenncy_simple_and_linux_IPC
{  

    namespace egzample_of_posix_msg_queue
    {
        
        std::string QUEUE_NAME = "/test_queue";
        

        void readFromQueue()
        {
            cout<<"Writter starting"<<endl;

            mqd_t   mq = {0};           //type for mssg queue
            struct mq_attr attr = {0};  //struct for keeping mq parameters   
            attr.mq_flags =0;
            attr.mq_maxmsg =10;
            attr.mq_msgsize = MAX_SIZE;
            attr.mq_curmsgs = 0;

            array<char, MAX_SIZE> buffer__char_arr{};

            mq=mq_open(QUEUE_NAME.data(), O_CREAT | O_RDONLY, 0700, &attr);
            //mq_open - on opern correct return file descriptior
            //mq_open - on open failed return -1 and fullfill errno

            if(mq>-1){
                    for(;;){
                            //we read in loop chunk of data  specify by buffer arr created previously                        
                            //bytes_read it is t_size - number of readed chars
                            auto bytes_read = mq_receive(mq, buffer__char_arr.data(), buffer__char_arr.size(),NULL);
                                
                            if(bytes_read> 0){            //reading + printing - we not saving it
                                buffer__char_arr[bytes_read] ='\0'; //add  c-string ending at the end
                                cout<<" Recived: "<<buffer__char_arr.data()<< endl;
                            
                            }else if (bytes_read == -1){    //error
                                perror("readFromQueue:  recived msg failed");

                            }else{                          // end
                                cout<<"\n\n End of reading data"<<endl;
                                mq_close(mq);
                                break;
                            }




                    }//end for


            }else{

                cout<<"Reader: failed to laod queue"<<strerror(errno)<<endl;
            }

            // remove link to queue
            mq_unlink(QUEUE_NAME.data());


        }

        void writeInToQueue()
        {
            cout<<"Writting started"<<endl;

            //1th - check if queue is open - if no-> error
            //mq_open - on opern correct return file descriptior
            //mq_open - on open failed return -1
            mqd_t mq={0};

            mq=mq_open(QUEUE_NAME.data(), O_WRONLY, 0700, NULL);
            if(mq>-1){

                    //2nd - open and check file descriptior for open(work) on a mq object - here saved as test.dat 
                    int file_descriptior = open("mq_test.dat", O_RDONLY);
                    if(file_descriptior>0){

                            //3th - in that step  mq(exist), fd(is open) we can read data
                            //we create inner array and another buffer to read chars from message 
                            array<char, MAX_SIZE> inner_buffer{};
                            for(;;)
                            {                         
                                //4th - if we ahve something to process - read it, if not- close it      
                                auto bytes_to_send_to_queue = read(file_descriptior, inner_buffer.data(), inner_buffer.size());
                                
                                if(bytes_to_send_to_queue> 0){
                                        //we just wrtie - nothing else
                                                //check if we have 
                                                auto end_sending_check = mq_send(mq,inner_buffer.data(),inner_buffer.size(),0);
                                                if (end_sending_check == -1) { //-1 == error
                                                    cout<<"Sending ends on case  read >0: Send error"<<strerror(errno)<<endl;
                                                }
                                        //break;

                                }else if (bytes_to_send_to_queue == 0) { // here sending is end
                                        cout<<"Sending ends..."<<endl;
                                        
                                                //another check if we got all and there is no error
                                                auto end_sending_check = mq_send(mq,inner_buffer.data(),0,0);
                                                if (end_sending_check == -1) { //-1 == error
                                                    cout<<"Sending ends on case read ==0: Send error"<<strerror(errno)<<endl;
                                                }
                                        break;


                                }else{  //here we catch error
                                    perror("Loading loop: Reading failed");
                                }



                            }   //end for          


                    
                    }else{
                        cout<<"fd: Reading from file - failed"<<endl;;
                    }

                    //close fd and msg queue
                    close(file_descriptior);
                    mq_close(mq);


            }else{
                cout<<"readFromQueue: Failed to open msg queue"<<strerror(errno)<<endl; //strerror from cstring lib
            }



        }

        void run_me()
        {
            cout<<"-------------ch7_start----------------"<<endl;
            //eg_1_data_race_on_variable();
            thread th_read {egzample_of_posix_msg_queue::readFromQueue};
            thread th_write {egzample_of_posix_msg_queue::writeInToQueue};
            th_read.join();
            th_write.join();

            

            cout<<"-------------ch7_end----------------"<<endl;
        }

    }
//require gcc +11
/*
namespace semaphores_in_use_simple
    {
        //include <semaphore>
        uint32_t shared_resource = 0;
        binary_semaphore sem_for_produce(0);
        binary_semaphore sem_for_consume(0);
        
        constexpr uint32_t limit = 60000; // iteration max 

        void producer()
        {
            for(auto i =0; i<limit; i++)
            {
                sem_for_produce.acquire();  // it block resource for producer for increase it , task will be blocked until semaphore release
                ++shared_resource;
                osyncstream(cout) <<"Producer value: "<<shared_resource<<endl;
                sem_for_consume.release(); // it release resource 
                osyncstream(cout) <<"Producer finished"<<endl;
            }
        }

        void consumer()
        {
            for(auto i=0; i<limit; i++)
            {
                osyncstream(cout)<<"Waiting for data.."<<endl;
                sem_for_consume.acquire();  // it block resource for producer for increase it , task will be blocked until semaphore release
                --shared_resource;
                osyncstream(cout) <<"Value after consumer: "<<shared_resource<<endl;
                sem_for_produce.release(); // it release resource 
                osyncstream(cout) <<"Consumer finished"<<endl;
            }
        }

        void run_me()
        {
            sem_for_produce.release();
            thread t1(producer);
            thread t2(consumer);

            t1.join();
            t2.join();
            std::cout<<"End run me"<<endl;
        }


    }
*/    

namespace simple_mutex
{
    uint32_t shared_resource = 0;
    mutex shared_guard;
    mutex mutex_for_cout;

    constexpr uint32_t limit = 100000;

    void increment_it(unsigned id)
    {
        for(auto i = 0; i<limit; i++)
        {
            lock_guard<mutex> lock(shared_guard);
            ++shared_resource;
            cout<<"Thread id: "<<std::to_string(id)<<"\n";
        }

        cout<<"\n Thread: "<<std::to_string(id)<<" Incrementing finished"<<endl;
    }

    void run_me()
    {
        thread t1(increment_it,1);
        thread t2(increment_it,2);

        t1.join();
        t2.join();
    }
}
    
namespace atomic_spin_lock
{
    class My_Spinlock
    {
        std::atomic_flag flag;

        public:
        My_Spinlock():flag(ATOMIC_FLAG_INIT){};  //set flag on  false in class creation

        void lock_resource()
        {

            while(flag.test_and_set());     //it will block one core until release, spinlock do not wait pasivly
        }

        void unlock()
        {
            flag.clear();
        }

    };

    My_Spinlock my_spin;
    u_int32_t shared_resource =(0);
    u_int32_t max_value = 1000000;
    atomic<u_int32_t> shared_resource_atomic =(0);

   
    void my_job_to_do_with_spinlock(int thread_id)
    {
        cout<<"my_job_to_do_with_mutex"<<endl;
        cout<<"Thread num: "<<std::to_string(thread_id)<<" started and lock resource"<<endl;
        my_spin.lock_resource();
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        for(auto i=0; i<max_value; i++)
        {
            shared_resource++;
        }
        my_spin.unlock();      
        cout<<"Thread num: "<<std::to_string(thread_id)<<" release resource\n"<<endl;  

    }

    std::mutex mut;
    void my_job_to_do_with_mutex(int thread_id)
    {
        cout<<"my_job_to_do_with_mutex"<<endl;
        cout<<"Thread num: "<<std::to_string(thread_id)<<" started and lock resource"<<endl;
        mut.lock();
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        for(auto i=0; i<max_value; i++)
        {
            shared_resource++;
        }
        mut.unlock();      
        cout<<"Thread num: "<<std::to_string(thread_id)<<" release resource\n"<<endl;  


    }

    void my_job_to_do_with_atomic_on_resource(int thread_id)
    {
        cout<<"my_job_to_do_with_atomic_on_resource"<<endl;
        cout<<"Thread num: "<<std::to_string(thread_id)<<" started and lock resource"<<endl;
        //mut.lock();
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        for(auto i=0; i<max_value; i++)
        {
            shared_resource_atomic++;
        }
        //mut.unlock();      
        cout<<"Thread num: "<<std::to_string(thread_id)<<" release resource\n"<<endl;  
    }

    void run_me_with_just_atomic_on_resource()
    {
        thread th1(my_job_to_do_with_atomic_on_resource,1);
        thread th2(my_job_to_do_with_atomic_on_resource,2);
        thread th3(my_job_to_do_with_atomic_on_resource,3);
        thread th4(my_job_to_do_with_atomic_on_resource,4);
        

        th1.join();
        th2.join();
        th3.join();
        th4.join();
    }

    void run_me_with_splinlock_on_atomic_flag_block()
    {
        thread th1(my_job_to_do_with_spinlock,1);
        thread th2(my_job_to_do_with_spinlock,2);
        thread th3(my_job_to_do_with_spinlock,3);
        thread th4(my_job_to_do_with_spinlock,4);
        

        th1.join();
        th2.join();
        th3.join();
        th4.join();
    }

    void run_me_with_mutex_block()
    {
        thread th1(my_job_to_do_with_mutex,1);
        thread th2(my_job_to_do_with_mutex,2);
        thread th3(my_job_to_do_with_mutex,3);
        thread th4(my_job_to_do_with_mutex,4);

        th1.join();
        th2.join();
        th3.join();
        th4.join();
    }
}

namespace shm_egz_one
{
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