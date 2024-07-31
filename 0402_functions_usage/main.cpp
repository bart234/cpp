#include "f_bind.h"
#include "f_fork.h"
#include "f_array_data.h"


int main()
{
    //bind_test::simple_f_args_bind();
    //bind_test::bind_object_and_its_action();

    //fork_processes::run_few_forks();                 //#include <unistd.h>
    //fork_processes::just_one_fork();

    f_array_data::run_me();
    return 0;
}