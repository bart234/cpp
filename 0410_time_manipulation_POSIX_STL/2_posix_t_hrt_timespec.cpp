#include <iostream>
#include <ctime>

//hrt we use to mesure execution block of code
//timespec  is a struct to keep time in sec an nano-sec
//clock_gettime  - just seting current time (kind: CLOCK_MONOTONIC) , to struct (ref)


static const auto LOOP_LIMIT{40000};

void function_to_delay()
{
    for(auto i =0;i<LOOP_LIMIT;i++){
        for(auto a =0;a<LOOP_LIMIT;a++){
            
        }        
    }
}

int main ()
{
    timespec start,end;

    //start to mesure
    clock_gettime(CLOCK_MONOTONIC,&start);

        //action
        function_to_delay();
    
    clock_gettime(CLOCK_MONOTONIC,&end);

    const auto duration{(end.tv_sec -start.tv_sec)};

    std::cout<<"Elasped time: "<<duration<<std::endl;

}