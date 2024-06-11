#include <iostream>
#include <string>
#include "Dog.h"
#include "Owner.h"
using namespace std;    


int main() {
    
    Dog art;
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
    
    Dog ciapek;
    Dog kora{"Kora","bart",4};
    cout<<kora.dog_name()<<endl;
    
    Owner brtk;
    brtk.set_name("bartek");
    cout<<"My name is "<<brtk.get_name()<<endl;
    brtk.set_age(34);
    cout<<"Im "<<brtk.get_age()<<" years old"<<endl;
    brtk.set_dog(kora);
    cout<<"I have dog named "<<brtk.piesek.dog_name()<<endl;
    
    return 0;
}