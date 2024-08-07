#include <iostream>
#include <string>
#include <vector>

class my_class
{
    int _a,_b;
    public:

    my_class():_a(0),_b(0){};
    my_class(int c):_a(c){};
    my_class(int a, int b):_a(a),_b(b){};

};

void func(int a,int b, int c)
{
    std::cout<<a<<" "<<b<<" "<<c<<std::endl;
}
void func(std::initializer_list<int> const my_list)
{
    for(auto &el:my_list)
    {
        std::cout<<el<<" \n";
    }
}

int main()
{
    my_class t1{};
    my_class t2{3};
    my_class t3{4,2};

    my_class r1 =2;
    my_class r2 ={1,2};


    func({1,2,3});      //to work with that, we need initializer-list as argument and override func

    return 0;
}