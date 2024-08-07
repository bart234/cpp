#include <iostream>

using namespace std;

//l-value - value container/saved to which we can make ref
//r-value - temp value , like  use("temp_val"), add(2+3)
//&& to use r-value 

void print_me(std::string & my_msg){
    std::cout<<"L-value: just ref to something"<<std::endl;
    std::cout<<my_msg<<std::endl;
}

void print_me(std::string && my_msg){
    std::cout<<"R-value: ref to temp value"<<std::endl;
    std::cout<<my_msg<<std::endl;
}


int main()
{
    std::string my_str{"Abba"};
    print_me(my_str);

    print_me("Beta");
    print_me("Gamma "+my_str);


}