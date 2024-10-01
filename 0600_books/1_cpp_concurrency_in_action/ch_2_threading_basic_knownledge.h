#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void do_some_work()
{
    for(int i=0;i<5;i++){
        cout<<"do some work:"<< std::this_thread::get_id()<<" my a... "<<i<<endl;
    }
}
void do_some_print(int i)
{
    cout<<"do some print:" <<std::this_thread::get_id()<<" print my i..."<<i<<endl;
}

void do_some_print_2(std::string print_me)
{
    cout<<"do_some_print_2:"<<std::this_thread::get_id()<<print_me<<endl;
}

class class_to_launch_itself
{
    public:
        void operator()()const
        {
            do_some_work();
        }
};

void do_something_error(){cout<<"Thromme error"<<endl;throw;}

struct func
{
    int &i;
    func(int&i_):i(i_){};
    void operator()()
    {
        cout<<"1"<<endl;
        for(unsigned i=0;i<2000;i++)
        {
            do_some_print_2("from funct");
        }
        cout<<"2"<<endl;
    }
};

class thread_guard
{
    std::thread &t;
    public:
    explicit thread_guard(std::thread &t_):t(t_){};
    ~thread_guard()
    {
        cout<<"th guard: destructor start"<<endl;
        if(t.joinable()){t.join();}
        cout<<"th guard: destructor end"<<endl;
    }
    thread_guard(thread_guard const&)=delete;
    thread_guard &operator=(thread_guard const &)=delete;

};

void my_func_variable_by_ref(int a, std::string &b){b="beta"+ std::to_string(a);}


std::thread func_with_th_return()
{
    cout<<"func_with_th_return"<<endl;
    void do_some_work_with_thread();
    return std::thread(do_some_work_with_thread);
}

void func_to_get_thread(std::thread th)
{
    cout<<"func_to_get_thread"<<endl;
}

struct big_project{void prepare_data(){};};

namespace threads_basic_knownledge
{
    //basic - bottom, more advanced - top

    void spawn_multiple_threads()
    {
        //place to save them
        std::vector<std::thread> thread_wh;

        //creation
        for(int i=0;i<20;i++)
        {thread_wh.push_back(std::thread(do_some_print));}

        //joining
        for(auto &th:thread_wh)
        {th.join();}
    }

    void thread_as_a_result_of_function()
    {
        //thread can be passed to function by temp object or by value(std::move)
        
        //temp thread object into function  
        func_to_get_thread(std::thread(func_with_th_return));

        //explicit move, and object 
        std::thread t3(do_some_work);
        func_to_get_thread(std::move(t3));
    }

    void move_ownership_between_threads()
    {
        std::thread t1(do_some_work);
        std::thread t2=std::move(t1);   //explicit because t1 is already a object
        t1=std::thread(do_some_work);    //implicit, because it it temp object, it have by default std::move
        std::thread t3;
        t3 = std::move(t1);     //object -so we have to move it
        t1 = std::move(t2);     //error - we cannoct assign another proces into t1
        //it running, you can only join or detach it
    }

    void unique_ptr_and_threads()
    {
        /*unique ptr and thread have similar semantics - can be move, but not copied
        object with one-instance like unique_ptr can be took by thread  by std::move
        it leave empty object with null ptr
        temp objects are moved automatically , but named obj are moved explicitly with std::move
        thread do not own  object in same way like unique_ptr, thread own resource        
        */
        void function_to_takebig_project(std::unique_ptr<big_project>);
        std::unique_ptr<big_project> bp_instance(new big_project); 
        std::thread t10(function_to_takebig_project,std::move(bp_instance)); //after that bp_instance is empty
        t10.join();
    }

    void passing_args_by_ref_into_thread()
    {
        /*thread itself copy arguments to internal storage, and since that time they are treated like rvalues, even are temp variables
        std::string& passed int thread, will be passed as char*const , and converted in thread again int std::string
        we can pass char const* - like result of sprintf(buffer,"%i",some_param); - but function will have problems
        to avoid problems we have to cast into string std::thread t(f,3,std::string(buffer));*/

        std::string my_string="abba";
        //error - std::thread t9(my_func_variable_by_ref,42,my_string);
        std::thread t9(my_func_variable_by_ref,42,std::ref(my_string));

    }

    void thread_guard_to_protect_and_join_other_th()
    {
        int my_local_variablr=4;
        func my_func(my_local_variablr); //here is loop x2000 print 
        std::thread t8(my_func);
        thread_guard tg_t8(t8);

        //do_something_error();// undefine behavior - t8 is still joined because join in destructor
        do_some_work(); //program will join t8 during ending scope , when tg will be delete
    }
    

    void catching_errors_and_join_anyway()
    {
        //it some error will occure in main thread, and it happen before  other thread join
        //that thread work will be lost, so even if main thread cras, we want to be sure 
        //that other thread will complete their jobs
        //without that catch - undefined behavior occure, and result from thread id randomnly occure

        int my_local_variablr=4;
        func my_func(my_local_variablr); //here is loop x2000 print 
        std::thread t8(my_func);
        try
        {
            do_something_error();
        }
        catch(...)
        {
            t8.join();
            throw;
        }
        t8.join();
    }

    void detach_thread_and_crash_it()
    {
        //main thread is not waiting for finish t8, because we detach t8
        //ubt t8 is using local variable from man thread - so after main th will end
        //t8 will be without variable and will crash

        int my_local_variablr=4;
        func my_func(my_local_variablr); //here is loop x2000 print 
        std::thread t8(my_func);
        t8.detach(); 
    }

    void lambda_as_temp_function()
    {
        std::string print_me="abba";
        std::thread t7([=]
                        {
                            do_some_work();
                            do_some_print_2(print_me);
                        });
        t7.join();
    }

    void clas_with_do_function_as_temp_obj()
    {
        // nope -  we cant do this like that - std::thread(clas_with_do_function_as_temp_obj());
        //declaration of whole class is diffrent, otherwise compiler define it as obj definition
        std::thread t5{class_to_launch_itself()};  //temp object - init by {} and put int thread t5
        //or - it works too
        std::thread t6((class_to_launch_itself()));
        t5.join();
        t6.join();
    }

    void class_with_do_function_inside()
    {
        //cls have overriten opeartow and it init launch function x20
        class_to_launch_itself my_cls;
        std::thread t3(my_cls);
        std::thread t4(my_cls);
        t3.join();
        t4.join();        
    }

    void basic_thread_launch()
    {
        std::thread t1(do_some_work,1);
        std::thread t2(do_some_work,2);
        t1.join();
        t2.join();
    }

}