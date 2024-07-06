#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

//using std::cout;
//using std::endl;
//using std::cin;
using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

namespace threadingGeneralInfo
{
    ull OddSum=0;
    ull EvenSum=0;

    void functionEvenSum(ull start, ull end)
    {
        for(ull i = start; i<end; ++i)
        {
            if((i&1)==0){EvenSum+=i;};
        }
    }

    void functionEOddSum(ull start, ull end)
    {
        for(ull i = start; i<end; ++i)
        {
            if((i&1)==1){OddSum+=i;};
        }
    }

    void threadin_general_info()
    {
        ull start =0;
        ull end = 1900000000;
        auto startTime = high_resolution_clock::now();

        std::thread t1(functionEvenSum,start,end);
        std::thread t2(functionEOddSum,start,end);
        
        std::cout<<"Before join"<<std::endl;
        t1.join();                  
        t2.join();
        std::cout<<"After join"<<std::endl;

        auto stopTime = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stopTime-startTime);


        std::cout<<OddSum<<endl;
        std::cout<<EvenSum<<endl;
        std::cout<<duration.count()/1000.0<<endl;
    }

    void run(int x)
    {
        while(x-->0)
            cout<<x<<" my thread"<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    void threading_detach_eg()
    {
        std::thread t1(run,8);
        cout<<"Main()"<<endl;
        //t1.join();                  //with join main thread(main()) will launch thread, after that will print "Main()" and when join, 
                                    //will print counting and start to wait because of sleep, and after sleep will print after

        t1.detach();                //if we detach t1 from main, main will not w8 for t1 - depend what thread will be first (we dont know which t will be 1th)
                                    // main will print "Main" and "After" together  - and before t1 or after
                                    //WARNING it is possible that one thread is faster , ans is fast enough to start and finish work  before another will even start
                                    //and program will be closed before second thread ill start- it main thread will be faster then t1 - it will close os before
                                    //t1 will even start
                                    //
        cout<<"Main after()"<<endl;
    }

};

namespace threading_type_of_threads
{
    void funPointer(char c,int x)
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


    void my_main()
    {
        //MyThirdClass::run('f',99); --static

        std::thread t1(funPointer,'a',11);
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

namespace threading_MUTEX
{
    int my_val=0;
    std::mutex my_mutex;




    
    namespace simple_thread_with_mutex
    {
        using namespace std::literals::chrono_literals;

        void addMe(int add)
        {
            my_mutex.lock();
            cout<<"Thread id: "<<std::this_thread::get_id()<<endl;
            cout<<"Val before: "<<my_val<<std::endl;
            my_val+=add; 
            cout<<"Val after: "<<my_val<<std::endl;
            my_mutex.unlock();
        }

        void run_me()
        {
            std::thread t1(addMe,1);
            std::thread t2(addMe,-5);
            t1.join();
            t2.join();
            std::this_thread::sleep_for(1s);
            std::cout<<"Result is: "<<my_val<<std::endl;
        }

    }

    void simple_thread()
    {   
        std::array<std::thread, 5> th_array;

        const auto worker_lambda
        {
            []
            {
                const auto th_id = std::this_thread::get_id();
                cout<<"thread id: "<<th_id<<endl;
            }
        };

        for(auto &t:th_array)
        {
            t=std::thread(worker_lambda);
        }

        for(auto &t: th_array)
        {
            t.join();
        }

        cout<<"Main thred is: "<<std::this_thread::get_id()<<endl;
    };

};

/*
- you dont know what thread will start first
 once thread is started we have to wait to finish by calling join() - so if thread didnt finish calculate itself 
between moment of std::thread ... and join() - we ahve to wait  until it will finish its calculations 
- we can check if thread is jonable - if(t1.joinable()){t1.join()} - also if it is jonable you can detach it
-if you forget join or detach - program will crash

-detach - can detach  new thread from it parent (here t1 from maine)

*/

int main()
{
    //threadingGeneralInfo::threadin_general_info(); //general how to use threat anc clock
    //threadingGeneralInfo::threading_detach_eg();

    //threading_type_of_threads::my_main();         //kind of function which can be able to put into thread and HOW TO

    //threading_MUTEX::my_main();  // MUTEX - mutal exclusion - when more thread want access to  only one resource, to write

    //threading_MUTEX::simple_thread();
    threading_MUTEX::simple_thread_with_mutex::run_me();
}
