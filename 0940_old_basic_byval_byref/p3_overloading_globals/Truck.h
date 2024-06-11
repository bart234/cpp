
#include "Car.h"

enum class TruckKind{BUS,WYWROTKA,NACZEPA,CYSTERNA,NONE}; 

class Truck: public Car
{
    friend std::ostream&operator<<(std::ostream&os, const Truck &obj); //out - there is a problem with that - //why i dont have access to function from Truck class id arg is a Truck
    private:
        TruckKind in_kindOfTruck;
        std::string in_producer{"Wielton"};
        std::string get_TruckKind();

    private:        
        //TruckKind get_kind_of_truck(){return this->in_kindOfTruck;};
    public:        
        
        
        //void print_info()const;
        void print_truck();
        Truck(std::string model,TruckKind kindOfTruck, int weels,int year);
};

std::string Truck::get_TruckKind()
{
    switch (this->in_kindOfTruck)
    {
        case TruckKind::BUS:return "BUS";
        case TruckKind::WYWROTKA:return "WYWROTKA";
        case TruckKind::NACZEPA:return "NACZEPA";
        case TruckKind::CYSTERNA:return "CYSTERNA";
        case TruckKind::NONE:return "NONE";
        default: return "NONE";
    }
}

Truck::Truck(std::string model,TruckKind kindOfTruck, int weels,int year):
            Car{model,year,weels},in_kindOfTruck{kindOfTruck}{};     


//overload Car << operator ?
std::ostream&operator<<(std::ostream&os, const Truck &obj)
    {
        //why i dont have access to function from Truck class id arg is a Truck
        os <<"Os Truck part:"<<obj.in_producer<< " " << obj.in_model << " "<<obj.in_weels_number<<" "<<obj.in_year<<" "<<std::endl;
        return os;
    }    

//print
void Truck::print_truck(){std::cout<<"abba beta gamma"<<std::endl;}
//void Truck::print_info()const {std::cout<< "Print info Truck: " <<this->in_model<< " "<<this->in_year<< " "<<this->in_weels_number<<std::endl;}

