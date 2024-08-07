#include <iostream>


/*
-making initialization in constructor is much more efficent then initialize in constructor
-we can skip part when we create temp object which is deleted later
-

-bulid-in types are efficient, but for other structures you should use initialization in constructor

*/

struct foo
{
    foo()
        {std::cout<<"def constr"<<std::endl;}
    foo(std::string const &text)
        {std::cout<<"constr: "<<text<<std::endl;}
    foo(foo const &other)
        {std::cout<<"copy constr"<<std::endl;}
    foo(foo&&other)
        {std::cout<<"move constr"<<std::endl;}
    foo &operator=(foo const & other)
        {std::cout<<"assignment op"<<std::endl;return *this;}
    foo &operator=(foo&& other)
        {std::cout<<"move op"<<std::endl;return *this;}
    ~foo()
        {std::cout<<"dstructor"<<std::endl;}
};

struct bar
{
    foo f;
   
    bar(foo const &value){f=value;}  ;           //unefficient way 
    //bar(foo const &value):f(value){};
};

int main()
{
    foo f;
    bar b(f);
}
