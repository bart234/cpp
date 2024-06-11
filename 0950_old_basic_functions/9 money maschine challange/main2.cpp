#include <iostream>
using namespace std;

int main(){
    
    cout<<"Put a number of cents what you want change:";
    int num_of_cents{0};
    cin>>num_of_cents;
    int dolars{0},quaters{0},dimes{0},nickles{0},pennies{0},rest{0};
        
    dolars = num_of_cents/100;
    rest = num_of_cents%100;    
    quaters = rest/25;
    rest = rest%25;    
    dimes = rest/10;
    rest = rest%10;
    nickles = rest/5;
    rest = rest%5;
    pennies = rest;
    
    cout<<"You can provide this change ad follows:"<<endl;
    cout<<"dollars :"<<dolars<< "  rest from divide: "<< rest<<endl;
    cout<<"quaters :"<<quaters<< "  rest from divide: "<< rest<<endl;;
    cout<<"dimes :"<<dimes<< "  rest from divide: "<< rest<<endl;;
    cout<<"nickles :"<<nickles<< "  rest from divide: "<< rest<<endl;;
    cout<<"pennies :"<<pennies<< "  rest from divide: "<< rest<<endl;;
    }
