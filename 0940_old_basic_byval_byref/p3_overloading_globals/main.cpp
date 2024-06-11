#include <iostream>
#include "Truck.h"
using namespace std;




int main()
{   
    Car c("Omega");

    Car a{"BMD"};
    
    a.set_wheels_num(5);
    //a.print_info();
    cout<<a;
    Car b{"Audi",1999};


    //b.print_info();
    Truck t_1{"Star",TruckKind::NACZEPA,6,2005};
    cout<<t_1;
    //std::cout<<t_1.get_TruckKind()<<std::endl;
    t_1.print_truck();
    //t_1.print_info();
    //b.year =1999;
    //Car c = a+b;
    //cout<<c;
}

/*
int main()
{
    /*
    string a;
    cin>>a;
    Car b{a};
    b.year = 2313;
    //cout<< a<<endl;
    cout<<b<<endl;
    cout<<"Give ma other model"<<endl;
    cin>>b;
    cout<<"My new modelis: "<<b.model<<endl;
    Car d
    return 0;
}*/

