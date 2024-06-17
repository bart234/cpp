#include "semaphores_c.h"


int main()
{

    /*  SEMAPHORES  <semaphore.h> invented when dinosaurs rule the earth
    - keep unsigned value 
    - changes are atomic
    - can be use as mutex 
    - lock and unlock in diffrent threads (mutex cant do that)
        USAGE
    - sem_post(mutex_unlock) - increment value by one 
    - sem_wati(mutex_lock) - decrement value
                        - if value is 0 then it will wait
                        - if value is >0 then decrement it and run
    - sem_init(&my_semaphore, int_default_semaphor_value, int_number_of_process_which will use this semaphore)
    
    */
    //semaphores::semaphores_on_phthread::run_me_semaphores_two_threads();
    //semaphores::semaphores_on_phthread::run_me_semaphore_mutiple_threads();
    //semaphores::semaphores_on_phthread::run_me_semaphore_multiple_threads_sem_eq_2();
    //semaphores::semaphores_on_phthread::run_me_semaphores_login_queue();
    
    semaphores::semaphores_on_shm_and_diffrent_threads::run_me_shm_fork_one_producer_one_consumer();
    return 0;
}