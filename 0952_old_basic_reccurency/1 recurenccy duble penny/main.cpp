#include <iostream>

using namespace std;


int num_of_days {5};
double value_after_day{};
int base_value_increase{2};

double func(double ammount, int days);

double func(double ammount, int days){    
    if (days ==0){
        return ammount;
    }        
    return func(ammount *base_value_increase, days -1);
}

int main() {    
    cout<<func(0.01,18)<<endl;   
    
    
    
    return 0;
}