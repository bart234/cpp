#include "sources.h"

namespace threading_type_of_threads
{
    void function_(char c,int x)
    {
        while( x --> 0)
            std::cout<<c<< " " <<to_string(x)<<std::endl;
    }
    //below it is lambda saved in variable/adress
    auto lambda_ptr = [](char c,int x)
        {
            while( x --> 0)
                std::cout<<c<< " " <<to_string(x)<<std::endl;
        };

    //functor
    class MyClass
    {
        public:
        void operator()(char c, int x)
        {
            while( x --> 0)
                std::cout<<c<< " " <<to_string(x)<<std::endl;
        }
    };

    //non-static member funciton
    class MySecondClass
    {
        public:
            void run(char c,int x)
            {
                while( x --> 0)
                    std::cout<<c<< " " <<to_string(x)<<std::endl;
            }
    };

    class MyThirdClass
    {
        public:
            static void run(char c,int x)
            {
                while( x --> 0)
                    std::cout<<c<< " " <<to_string(x)<<std::endl;
            }
    };


    void run_me()
    {
        std::thread t1(function_,'a',11);
        std::thread t2(lambda_ptr,'l',10);
        std::thread t3((MyClass()),'f',10);
        MySecondClass my_instance;
        std::thread t4(&MySecondClass::run,&my_instance,'n',8); //to use it, you need object(here my_instance) to call this funciton (::run)
        std::thread t5(&MyThirdClass::run,'s',9);

        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
    }
};