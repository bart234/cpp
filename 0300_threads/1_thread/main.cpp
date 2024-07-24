#include "simple_thread.h"
#include "basic_mutex.h"
#include "diff_kind_of_func_passing_into_th.h"

int main()
{
    basic_mutex::run_me_simple_thread();
    
    simple_thread::run_me_threadin_general_info();
    simple_thread::run_me_threading_detach_eg();

    //diffrent kind of func passing into th
    threading_type_of_threads::run_me();

}
