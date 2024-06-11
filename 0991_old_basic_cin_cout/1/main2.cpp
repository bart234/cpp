#include <iostream>

using namespace std;

int main(){

    int total{};
    int num1{},num2{},num3{};
    const int count{3};
    
    cout<<"Enter 3 integers seeprate by spaces:";
    cin>>num1>>num2>>num3;
    total = num1 + num2 +num3;
    double avg{0};
    avg = static_cast<double>(total)/ count;
    
    cout<<"The 3 numbers were: "<< num1 << "," <<num2 << "," << num3 << endl;
    cout<<"sum od that number is: "<<total<<endl;
    cout<<"The average of this number is: "<< avg <<endl;
    
    }
