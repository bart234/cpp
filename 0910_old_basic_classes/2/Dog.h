#ifndef _DOG_H_
#define _DOG_H_

#include <iostream>
#include <string>

class Dog{
    //attr
    public:
    std::string name{};
    std::string owner{};
    int age{};
    int his_obay_in_scale{0};
    //constructors copy
    Dog(const Dog &source);
   

public:
    // constructors
    Dog ():name{"None"}, owner{"None"},age{0}{
//      wylaczono inicjacje z konstruktora klasy w taki sposob by wartosci inicjowaly sie
//      przy samym konstruktorze a nie pozniej    
//        name = "None";
//        owner = "None";
//        age = 0;
        }
    Dog (std::string name_in, std::string owner_in, int age_in)
        :name{name_in},owner{owner_in},age{age_in}
        { 
// wylaczono z powodu jw
//        name = name_in;
//        owner=owner_in;
//        age=age_in;
        }
        
    Dog(const Dog &source)
    :name{source.get_name},owner{"None"},age{0}
    {
    cout<<"stworzono kopie dog"<<endl;
    }
    
    bool set_a_name(std::string dog_name);
    bool set_a_owner(std::string owner_name);   
    void set_level_his_obey(int level){his_obay_in_scale = level;};
    void bark();
    bool give_a_leg();
    std::string dog_name(){return name;};
    
    
};

    

        

#endif // _DOG_H_
