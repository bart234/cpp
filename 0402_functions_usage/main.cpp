#include "f_bind.h"
#include "f_fork.h"
#include "f_array_data.h"
#include "f_swap.h"
#include "f_exchange.h"
#include "f_move.h"
#include "f_alignas.h"
#include "f_random.h"

int main()
{
    
    f_random::run_me_random_with_seed_from_time();
    //f_random::run_me_random_gen_basic_1_to_6();

    //f_alignas::basic_aligment::run_me_foo_32_bits();
    //f_alignas::basic_aligment::run_me();

    //f_move::run_me_swap_made_by_move_ptr();
    //f_move::run_me_swap_made_by_move();

    //f_exchange::run_me_like_swap();

    //f_swap::run_me_swap_ptrs();
    //f_swap::run_me_swap();
    //f_swap::run_me();

    //f_array_data::run_me();

    //fork_processes::run_few_forks();                 //#include <unistd.h>
    //fork_processes::just_one_fork();

    //bind_test::simple_f_args_bind();
    //bind_test::bind_object_and_its_action();

    return 0;
}