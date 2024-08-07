#include "sources.h"

/*watch?v=XZDx41woDoI

//contition_variable - provide additional kind of lock which depend on variable like book
we need 3 things:
- bool variable
- some resource to share between th
- two threads, one will be sleep , until variable will say "you can go" , 
                second thread is a courier to inform about that message
- ofc mutex which is require for conditional_variable

//condition variable waiting for  condition which is hsared between threads 
*/

std::mutex my_mutex;
std::condition_variable my_condition_variable;

namespace simple_one_from_yt
{
    void run_me()
    {
        int my_resource = 0;
        bool my_bool_as_notification = false;

        //reporter - must wait until worker finshed
        //if reporter will go first - aquire mutex, but bool is checking - here is false - so  have to .wait(lock)
        std::thread reporter([&]{
            std::unique_lock<std::mutex> lock(my_mutex);

            //this flag in that egzample is used only once, when 2threads going together and reporter have to wait
            //it check flag - is true -mean is going in and it satting condition_variable into wait on lock-muex
            //her its wait until worker will do its job
            //and  .notify_one() will be launch - that will notify reporter and  lock will be proceed

            //to use that bool many times, you need while loop and producer consumer mechamism
            if(!my_bool_as_notification){
                my_condition_variable.wait(lock);
            }

            std::osyncstream{std::cout}<<"Reporter: my resource is: "<<my_resource<<std::endl;

        });

        //working th

        std::thread worker([&]{
            std::unique_lock<std::mutex> lock(my_mutex);
                //we lock mutex- so we can work
                //critical section
                my_resource = 1+2+34+5;
                //work is done            
                //my_bool_as_notification=false;                ----------------------disabled, because in that egzample it is not required       
                std::osyncstream{std::cout}<<"Worker:  work ends, time to 5s sleep"<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));

            std::osyncstream{std::cout}<<"Worker: sleep ends, notify_one"<<std::endl;
            std::osyncstream{std::cout}<<"Wake up alarm: notify_one - 'hey, you, who sleeping at work' - 'lock is free , you can proceed'"<<std::endl;

            my_condition_variable.notify_one();
        });

        reporter.join();
        worker.join();

    };
}