#include <iostream>
#include <string>
/*
enum - are unscoped - thats mean they override themself in a app scope
        - problem: name clashes if two enums have same namespace with same name
        - you cannot specify underlying value - always is int
        - lack of scope  can result mixing meaning od names
enum class / enum struct - are scoped like: enum class Status{ABBA,BETA,GAMMA};
        - strongly typed
        - they not export themself to surroundings scope
        - you can specify underlying type
        - assigning to value - value from behind will not convert implicitly
*/
enum class Status{ABBA,BETA,GAMMA};

enum class MyEnum: unsigned int {OK=0,ERROR=1,SUCCESS=2,FATAL_E=0xFFFF0000U};

int main()
{
    MyEnum e1 = MyEnum::FATAL_E;
    // int e2 = MyEnum::OK  //no longer work - a value of type "MyEnum" cannot be used to initialize an entity of type "int"
    int e2 = static_cast<int>(MyEnum::OK);
    //int e3 = MyEnum::ERROR;

    Status s = Status::ABBA;

    switch(s)
    {
        using enum Status;      //since c++20
        case ABBA:std::cout<<"ABBA"<<std::endl;break;
        case BETA:std::cout<<"B"<<std::endl;break;
        case GAMMA:std::cout<<"G"<<std::endl;break;
    }

}