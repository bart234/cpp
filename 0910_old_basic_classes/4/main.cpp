#include <iostream>
#include <string>
#include "Dog.h"
using namespace std;    


int main() {
    
    Dog art{};
    art.set_level_his_obey(55);
    if(art.set_a_name("Artur")){
        std::cout<<art.dog_name();
        std::cout<< " accept his new name"<<std::endl;
    }else{        
        std::cout<<"Dog didnt accept his name, he is not obay you"<<std::endl;
    }
    
    art.bark();
    
    if(art.give_a_leg()){
        std::cout<<art.dog_name();
        std::cout<<" gave you a leg"<<std::endl;
    }else{
        std::cout<<"Dog didnt give you leg, he is not obay you"<<std::endl;
    }
    
    return 0;
}