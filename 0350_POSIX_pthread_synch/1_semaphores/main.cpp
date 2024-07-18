#include "semaphores_login_queue_void_pth.h"
#include "semaphores_on_pthread_void_arg_pth.h"
#include "semaphores_shm_w_r_one_th_fork.h"

int main()
{
    semaphores_login_queue_void_pth::run_me_semaphores_login_queue();

    semaphores_on_pthread_void_arg_pth::run_me_semaphores_two_threads();
    semaphores_on_pthread_void_arg_pth::run_me_semaphore_mutiple_threads();
    semaphores_on_pthread_void_arg_pth::run_me_semaphore_multiple_threads_sem_eq_2();

    semaphores_shm_w_r_one_th_fork::run_me_shm_fork_one_producer_one_consumer();
    return 0;
}