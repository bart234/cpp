#include <string>
#include <iostream>

enum class status{brand_new,used,wreck};

class Car
{
friend std::ostream&operator<<(std::ostream&os, const Car &obj); //out
protected:
    std::string in_model;
    int in_year;
    int in_weels_number{4};

public:
    Car(const std::string &model, int year,int weels);

    void set_year(int year){this->in_year=year;};
    int get_year()const {return this->in_year;};
    const std::string &get_model()const{return this->in_model;}

    void set_wheels_num(int wheels_num){this->in_weels_number=wheels_num;};
    int get_wheels_num()const {return this->in_weels_number;};

    //print
    //void print_info()const {std::cout<<"Print info Car: " <<this->in_model<< " "<<this->in_year<< " "<<this->in_weels_number<<std::endl;}
    
};

Car::Car(const std::string &model,int year =-1,int weels=4):in_model{model},in_weels_number{weels},in_year{year}{}

std::ostream&operator<<(std::ostream& os,const Car &obj)//out
{         
    //os using public funciton from car class
    //os<<"Os Car part: "<<obj.get_model()<< " "<<obj.get_wheels_num()<<" "<<obj.get_year()<<std::endl;
    //os im changing values form private -> protected , and will use it in os
    os<<"OS Car: model: "<<obj.in_model<<"year: "<< obj.in_year<<" wheels: "<<obj.in_weels_number<<std::endl;
    return os;
}







//friend std::istream&operator>>(std::istream&in,Car &obj);//in
//friend Car operator+(const Car &lhs, const Car &rhs);

/* //overloaded operators
Car operator+(const Car &lhs, const Car &rhs)
{
    Car temp(lhs.model+ " " + rhs.model);
    temp.year = lhs.year;
    return temp;    
}*/

/*
std::istream&operator>>(std::istream&in,Car&obj)//int
{
    std::string buff;
    in>>buff;
    obj.model=buff;
}
*/



/*
class Car
{
private:
    std::string in_brand;
    std::string in_model;
    std::string in_color;
    int in_prod_year;
    int in_km;
    status car_status;
    //Engine e{}

public:
    Car(std::string brand,std::string model,
        status car_status,std::string color="None",
        int prod_year=0,int km=0);
    void setEngine();
    void displayGeneral();
    void displayDetails();   

};*/