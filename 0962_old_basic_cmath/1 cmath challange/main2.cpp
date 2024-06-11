#include <iostream>
#include <iomanip>
using namespace std;

int function_activation_count {0};
double a_penny_doubled_everyday(int n, double money);

void amount_accumulated() {  
    double total_amount{a_penny_doubled_everyday(5)};
    cout <<  "If I start with a penny and doubled it every day for 25 days, I will have $" << setprecision(10) << total_amount;
}

double a_penny_doubled_everyday(int n, double money = 0.01) {
    function_activation_count++;
    
    if (function_activation_count != n)
       return a_penny_doubled_everyday (n-1,money *2);
   return money *2

}

