#include <iostream>
using namespace std;

const double charge {32.5};
const double sale_tax {0.06};

int main(){ 
    
    cout<<"Estimate for carpet clining service"<<endl<<endl;
    cout<<"Number of rooms: ";
    int number_rooms {0};    
    cin>>number_rooms;    
    
    cout<<"Price per room is: "<<charge<<" euro"<<endl;    
    
    cout<<"Tax: "<<number_rooms*charge*sale_tax<<endl;
    cout<<"==========================="<<endl;
    cout<<"Total estimate is: "<<number_rooms*charge*(1+sale_tax)<<endl;
    
    int valid_days {5};
    cout<<"This estimation is valid "<< valid_days * number_rooms <<" days."<<endl;
    
    
    }
