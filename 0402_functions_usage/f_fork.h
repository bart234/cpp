#include <ostream>
#include <unistd.h>

namespace fork_processes
{
    /*
    parent and child are two diffrent threads executed in diffrent addres space (threads share addres space)
    fork function can run concurrently in same program  or run as executable

    */

   void just_one_fork()
   {/*
    Process fork-ing to simulate two application: one produce data, second consume it
    -main fork creating child and going into  pid >0 (because it was just created)
    -child_pid, do not create another,  child_pid and variable pid is pid==0
    */
        std::cout<<"before fork: "<<getpid()<<std::endl;


        int pid = fork();
        std::cout<<"after fork: "<<getpid()<<" new_fork pid: "<< pid<<std::endl;


        if(pid==0)
            std::cout<<"pid == 0 :"<<getpid()<<std::endl;
        else if (pid > 0)
            std::cout<<"pid > 0: "<<getpid()<<std::endl;
        else
            std::cout<<"pid == -1: "<<getpid()<<std::endl;
            
   }

    void run_few_forks()
    {
        pid_t pid_1 = fork();
        pid_t pid_2 = fork();
        std::cout<<"My fork number: 1 => "<<pid_1<< "  "<<getpid()<<std::endl;
        std::cout<<"My fork number: 2 => "<<pid_2<< "  "<<getpid()<<std::endl;
        std::cout<<"\n"<<std::endl;
        //std::cout<<"My fork number: 2 => "<<pid_2<<std::endl;
    }
}