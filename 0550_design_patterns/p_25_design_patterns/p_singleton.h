#include "sources.h"
#include "thread"

namespace p_singleton
{

    class Singleton
    {
    private:
        //basic thing - pointer for one and only instance 
        static Singleton * ptr_to_class;    
        std::string my_value;

        //here is main constructor - in private section
        Singleton(std::string val):my_value{val}{};

    public:
        //deleted stuff
        Singleton(const Singleton&obj_to_copy)=delete;

        ~Singleton();

        //basic function - getInstance
        static Singleton* getInstance(std::string instVal)
        {   
            cout<<"Get instance"<<endl;
            //if  ptr is filled ther return ptr, but if is empty then create new instance
            /*
            if(ptr_to_class==NULL)
            {
                ptr_to_class = new Singleton();
            }
            */
            ptr_to_class = new Singleton(instVal);
            //Singleton* a = new Singleton(instVal);
            return ptr_to_class;
            //return a;
        }

        void setValue(std::string val){this->my_value=val;};
        void printMe(){std::cout<<"Value inside: "<<this->my_value<<std::endl;};

    };
    
    Singleton* Singleton ::ptr_to_class = NULL;

    void run_me()
    {
        

        Singleton * my_sing = Singleton::getInstance("new_instance");
        //my_sing->setValue("abba");
        my_sing->printMe();
        Singleton * new_sigl = Singleton::getInstance("second");
        new_sigl->printMe();
        my_sing->printMe();

    }
}

namespace doesnt_work
{

    /*
    main idee is to have only one object that kind, and you cannot inherit from it
    use: to have access to something, or to keep properties
    to make it works we need one static class without public constuctor
    */
   /* ----- doesnt work -----
   class Singleton
   {
    protected:
    std::string value_1;
    static Singleton* my_instance_;
    Singleton(const std::string in_value_1):value_1{in_value_1}{};

    public:
    Singleton(Singleton &other_singleton) = delete;     //delete copy constructor
    void operator=(const Singleton&)=delete;            //delte assgin constructor
    static Singleton* get_instance(std::string val)
        {
            if(my_instance_==nullptr)
                my_instance_=new Singleton(val);
            return my_instance_;
        };
    std::string printMe(){return this->value_1;}       
   };

    void ThreadFoo()
    {
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
        Singleton* s=Singleton::get_instance("Foo");
        cout<<s->printMe()<<endl;
    }

    void ThreadBoo()
    {
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
        Singleton* s=Singleton::get_instance("Boo");
        cout<<s->printMe()<<endl;
    }
    
    
    void run_me()
    {
        std::cout <<"If you see the same value, then singleton was reused (yay!\n" <<
                "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
                "RESULT:\n";   
        std::thread t1(ThreadFoo);
        //std::thread t2(ThreadBoo);
        t1.join();
        //t2.join();
    }
    */
}