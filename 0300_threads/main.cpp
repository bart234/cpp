#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

void detached_routine()
{
    cout<<"th_1: start - Starting detatched_routine thread. \n";
    std::this_thread::sleep_for(seconds(4));
    cout<<"th_1: end - Exiting detatched_routine\n";
}

void joined_routine()
{
    cout<<"th_2: start - Starting joined_routine thread. \n";
    std::this_thread::sleep_for(seconds(2));
    cout<<"th_2: end - Exiting joined_routine\n";
}

void thread_creator()
{
    std::cout<<"Starting thread_creator\n";
    std::thread th_1(detached_routine);
    std::cout<<"th_1 - before - -Is detatched_routine thread - joinable: "<< th_1.joinable() <<endl;
    //Separates the thread of execution from the thread object, 
    //allowing execution to continue independently. 
    //Any allocated resources will be freed once the thread exits.
    th_1.detach();
    std::cout<<"th_1 - after - is detatched_routiine thread joinable: "<<th_1.joinable()<<endl;
    
    std::thread th_2(joined_routine);
    std::cout<<"th_2 - before - is th2 is joinable: "<<th_2.joinable()<<std::endl;
    th_2.join();
    std::cout<<"th_2 - after - it th2 is joinable: "<<th_2.joinable()<<std::endl;
    
    this_thread::sleep_for(chrono::seconds(6));
    

    cout<<"Exiting thread creator"<<endl;
}

int main()
{
    thread_creator();
}