#ifndef _OWNER_H_
#define _OWNER_H_
#include <iostream>
#include <string>
#include "Dog.h"

class Owner{
    //attr
private:
    std::string name;
    int age;

public:    
    Dog piesek;
    void set_name(std::string name_in){name = name_in;};
    std::string get_name(){return name;} 
    void set_age(int age_in);
    int get_age();
    void set_dog(Dog my_dog);
//    void get_dog_name();
    
};

#endif // _OWNER_H_
