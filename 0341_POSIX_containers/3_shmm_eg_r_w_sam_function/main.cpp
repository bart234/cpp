
#include "ch_7_.h"
  



int main()
{


    //chapter_7_concurenncy_simple_and_linux_IPC::egzample_of_posix_msg_queue::run_me();
    //chapter_7_concurenncy_simple_and_linux_IPC::semaphores_in_use_simple::run_me();       //disabled: require gcc +11 and c+20 (tasks.json)
    //chapter_7_concurenncy_simple_and_linux_IPC::simple_mutex::run_me();
    
    //chapter_7_concurenncy_simple_and_linux_IPC::atomic_spin_lock::run_me_with_splinlock_on_atomic_flag_block(); //thread which waiting for is blocking one cpu (file monitor) , but in case of mutex - it does not
    //chapter_7_concurenncy_simple_and_linux_IPC::atomic_spin_lock::run_me_with_mutex_block();    
    //chapter_7_concurenncy_simple_and_linux_IPC::atomic_spin_lock::run_me_with_just_atomic_on_resource();

    chapter_7_concurenncy_simple_and_linux_IPC::shm_egz_one::run_me_shm_fork_one_producer_one_consumer();
    
    cout<<"\nDone\n"<<endl;
    return 0;
}

//spinlock: is blocking whole core for each thread , until resource is free
//mutex: is better
//atomic resource: is better
//each technique inherit performance cost :
//best achive: minimize switching, minimize performance and their scope
//best achive: use existing mechanisms which are optimized before you start mixing all together