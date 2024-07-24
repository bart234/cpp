
#include "sources.h"

namespace basic_mutex
{
    int my_val=0;
    std::mutex my_mutex;
    
    namespace simple_thread_with_mutex
    {
        using namespace std::literals::chrono_literals;

        void addMe(int add)
        {
            my_mutex.lock();
            cout<<"Thread id: "<<std::this_thread::get_id()<<endl;
            cout<<"Val before: "<<my_val<<std::endl;
            my_val+=add; 
            cout<<"Val after: "<<my_val<<std::endl;
            my_mutex.unlock();
        }

        void run_me()
        {
            std::thread t1(addMe,1);
            std::thread t2(addMe,-5);
            t1.join();
            t2.join();
            std::this_thread::sleep_for(1s);
            std::cout<<"Result is: "<<my_val<<std::endl;
        }

    }

    void run_me_simple_thread()
    {   
        std::array<std::thread, 5> th_array;

        const auto worker_lambda
        {
            []
            {
                const auto th_id = std::this_thread::get_id();
                cout<<"thread id: "<<th_id<<endl;
            }
        };

        for(auto &t:th_array)
        {
            t=std::thread(worker_lambda);
        }

        for(auto &t: th_array)
        {
            t.join();
        }

        cout<<"Main thred is: "<<std::this_thread::get_id()<<endl;
    };

};