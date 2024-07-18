#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>

using namespace std;

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
