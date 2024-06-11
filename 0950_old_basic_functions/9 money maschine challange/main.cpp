#include <iostream>

using namespace std;

int main()
{
//    int age{12};
//    bool parental_consent{true}, ssn {true}, accidents{true};
//    
//    if (age >= 18 || (age >=15 && parental_consent == true && ssn== true && accidents == true)){
//        cout<<"Yep you can drive"<<endl;}
//    else{
//        cout<<"You cant drive jet"<<endl;
//    }

    cout<<"Please put number of pennies to change:"<<endl;
    int pennie_in{0};
    cin>>pennie_in;
    cout<<"You will get:"<<endl;
    int temp_int{}, temp_rest{};
    temp_int = pennie_in/100;
    cout<<"dolars: "<< temp_int<<endl;
    pennie_in -= 100*temp_int;
    temp_int = pennie_in/25;
    cout<<"quaters: "<<temp_int<<endl;
    pennie_in -= 25*temp_int;
    temp_int = pennie_in/10;
    cout<<"dimes: "<<temp_int<<endl;
    pennie_in -=10*temp_int;
    temp_int = pennie_in/5;
    cout<<"nicke: "<<temp_int<<endl;
    pennie_in-= temp_int*5;
    cout<<"cents: "<<pennie_in<<endl;
    
    
    
    
    
    return 0;
}