#include <iostream>
#include <string>

using namespace std;

    //function prototype
    double calculate_cost(double cost, int number_of_elements, double tax = 0.22);
    void gretttings(string name, string prefix ="Mr." , string suffix="");
    double fruits_price(int mangos_count=1, int pineaple_count=3, int strawberry_count=23);
    
    double fruits_price(int mangos_count=1, int pineaple_count=3, int strawberry_count=23){
        return mangos_count + pineaple_count + strawberry_count;
    }
    
    double calculate_cost(double cost, int number_of_elements, double tax)    {
        return cost * number_of_elements* (tax+1);        
    }

    void gretttings(string name, string prefix, string suffix){
        cout<< "Hello " + prefix + " " + name + " " + suffix<<endl;
    }

int main () {
    //cout<< calculate_cost(2.25, 4)<<endl;
//    gretttings("Bartek","Md." );
//    gretttings("Bartek","Prof.", "PhD" );   

    
    return 0;
}