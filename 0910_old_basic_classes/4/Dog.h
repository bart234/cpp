#ifndef _DOG_H_
#define _DOG_H_

#include <iostream>
#include <string>

class Dog{
    //attr
    private:
    std::string name{};
    std::string owner{};
    int age{};
    int his_obay_in_scale{0};
    
    //functions
    public:
    bool set_a_name(std::string dog_name);
    bool set_a_owner(std::string owner_name);   
    void set_level_his_obey(int level){his_obay_in_scale = level;};
    void bark();
    bool give_a_leg();
    std::string dog_name(){return name;};
    
    
};

#endif // _DOG_H_
