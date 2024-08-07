#include "sources.h"

//too much inside - 

//synch primitive 
//it set th to speep and that th/s will not constantly check it critical section is availible
//it block th o many th until another th finish
//efficient
//likce producer consumer-  we need 2 th , some shave reqource, and  lock shared batween threads

using namespace std;

namespace hard_ew_from_book
{
    void run_me()
    {
        osyncstream{cout}<<"Main th id: "<<this_thread::get_id()<<endl;


        jthread worker
        {       []
                (stop_token s_token)
                {
                    mutex mutex_1;
                    unique_lock lock(mutex_1);
                    condition_variable_any().wait(
                                                    lock,
                                                    s_token,
                                                    [&s_token]{return s_token.stop_requested();}
                                                );
                    osyncstream{cout}<<"Thread with id: "<<this_thread::get_id()<< " is currently working"<<endl;
                    
                }
        };


        stop_callback callback_1
                        (       worker.get_stop_token(),
                                []
                                {osyncstream{cout}<<"Stop callback executed by th: "<<this_thread::get_id()<<endl;}
                        );

        auto stopper_func = [&worker]{
                                    if(worker.request_stop())
                                        osyncstream{cout}<<"Stop request executed by thread: "<<this_thread::get_id()<<endl;
                                    };

        jthread stopper(stopper_func);
        stopper.join();


    }
}
