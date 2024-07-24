#include "sem_vs_mutex.h"
#include "enable_disable_in_diff_threads_semaphores.h"
#include "enable_disable_in_diff_threads_sem_while_l.h"

int main()
{
    //mutex - have concept of ownership, and it expect to be closed in same thread, if you dont -> undefined bhw
    //semaphores - you can set wait and post in diffrent threads - more primitive then mutex

    //both are out of race condition and are synchronized 
    //in both: other threads are blocked by semaphore/mutex, and everything is processed one by one
    sem_vs_mutex::run_me_common_semaphore();
    sem_vs_mutex::run_me_common_mutex();

    //it is not free of race condition
    // semaphor is changes in another thread, not in same after use resource
    enable_disable_in_diff_threads_semaphores::run_me_common_semaphore();

    //here semaphor is changed in diffrent thread, but here recource is relesed after 1 second
    //and it is not race free, it launch 4 threads at once
    ena_dis_in_diff_threads_semaphores_while_l::run_me_common_semaphore();



}
