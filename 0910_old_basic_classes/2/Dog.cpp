#include <iostream>
#include <string>
#include "Dog.h"

bool Dog::set_a_name(std::string dog_name){
        if (his_obay_in_scale <50){            
            return false;            
        }else{            
            name = dog_name; 
            return true;
        }
    }
    
bool Dog::give_a_leg(){
    if (his_obay_in_scale <50){
        return false;
    }else{
        return true;
    }
}

void Dog::bark(){
        if (his_obay_in_scale <50){
            std::cout<<"Dog barked: Grrrrrrr"<<std::endl;
        }else{
            std::cout<<name<<" barked: Woooooof"<<std::endl;
        }
}

