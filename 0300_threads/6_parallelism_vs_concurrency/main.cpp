#include "sources.h"
#include "parraleism_base_algorythm.h"
#include "parallel_struct_passed_into_function_try1.h"
#include "parallel_struct_passed_into_function_try2.h"
#include "parallel_struct_passed_into_function_try3.h"
#include "parallel_struct_passed_copy_corrected_from_yt_try4.h"
#include "parallel_struct_passed_based_on_yt_done.h"



int main()
{
    //mian idee was to sum array without concurrency -one thread should sum one part, second-another part
    //parraleism_base_algorythm::run_me(); //paralleism - there is no resource race - just sum two diff parts of array

    //i didnt fully undestand yt approch so i rewrite it - but is doesnt works
    //because it was used pthread - it take only one arg -arg* - so it was necesseary to
    //rewrite it with some structure

    //below: struct was pass  and i didnt know how to recast it to correct struct
    //       also there was NOT return value from worker
    parallel_struct_passed_into_function_try1::run_me();        
    
    //below:struct was replaced, problably because it made copy
    parallel_struct_passed_into_function_try2::run_me_race_condition_on_struct_passed_into_thread(); 

    //below: i had corrects values in threads but it didnt return correct value to upper funciton
    //       it was a problem with return function
    parallel_struct_passed_into_function_try3::run_me_race_condition_on_struct_passed_into_thread();

    //below: it is clean clopy from yt, because it works there, but he passes only int
    parallel_struct_passed_copy_corrected_from_yt_try4::main();

    //below: i modify yt app to pass my struct into pthread, recast it, and also return it
    parallel_struct_passed_based_on_yt_done::main();

    
    // sum from object correctly returned during switch
    /* value added:
         how to pass more args int pthread
         how to manage that struct trough void ptr 
            knownledge about on what struct you need to recast it
        how to return ptr from void back
    */

}