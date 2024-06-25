#include <iostream>


class A
{
    int n;
    std::string s;

    public:
    A(int n_, std::string s_):
        n{n_},s{s_}
        {std::cout<<"A ctor"<<std::endl;}
    
    A(const A& to_copy_me):
        n{to_copy_me.n},s{to_copy_me.s}
        {std::cout<<"A copy ctor"<<std::endl;}
    
    A(A&& to_move) noexcept:
        n(std::move((to_move.n))),
        s(std::move((to_move.s)))
        {std::cout<<"A move tor"<<std::endl;}
    
    ~A(){std::cout<<"A dctor"<<std::endl;}

    void printMe(){std::cout<<"----> n: "<<std::to_string(n)<<"    s: "<<s<<std::endl;}
};

int main()
{
    //just ctor
    A a(1,"zzz");
    a.printMe();

    //copy ctor: b object is created from a obj
    A b(a);
    b.printMe();

    //move ctor:
    A c= std::move(b);
    b.printMe();
    c.printMe();
    return 0;

}