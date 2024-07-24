#include "sources.h"

namespace simple_thread
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

    void run_me_threadin_general_info()
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

    void run_me_threading_detach_eg()
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