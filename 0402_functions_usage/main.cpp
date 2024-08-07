#include "f_bind.h"
#include "f_fork.h"
#include "f_array_data.h"
#include "f_swap.h"
#include "f_exchange.h"
#include "f_move.h"
#include "f_alignas.h"


int main()
{
    //bind_test::simple_f_args_bind();
    //bind_test::bind_object_and_its_action();

    //fork_processes::run_few_forks();                 //#include <unistd.h>
    //fork_processes::just_one_fork();

    //f_array_data::run_me();
    
    //f_swap::run_me();
    //f_swap::run_me_swap();
    //f_swap::run_me_swap_ptrs();

    //f_exchange::run_me_like_swap();

    //f_move::run_me_swap_made_by_move();
    //f_move::run_me_swap_made_by_move_ptr();

    //f_alignas::basic_aligment::run_me();
    f_alignas::basic_aligment::run_me_foo_32_bits();

    return 0;
}