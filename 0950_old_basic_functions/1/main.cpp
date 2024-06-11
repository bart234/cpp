#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

const double pi {3.1416};
// Function prototype
int add_numbers(int a,int b);
void function_return_nothing();
int funkcja_z_argumentami(int a, std::string b);
double pole_kola(double r);
double objetosc_walca(double r, double h);
void oblicz_pole_kola();
void policze_objetosc_walca();





int main() {
//    cout<<sqrt(400.0);
// cppreferences.com
    cout<<add_numbers(12,23)<<endl;
    //cppreference.com
    
    cout<<"sqrt:"<<sqrt(3)<<endl;
    cout<<"sqrt + floor: "<<floor(sqrt(3))<<endl;
    cout<<"sqrt + round: "<<round(sqrt(3))<<endl;
    
    //RANDOM FUNCITON
    int random_num{};
    size_t number_of_my_numbers{10};
    int min_random_number{1};
    int max_random_number{6};
    
    cout<<"Random amx in my system is: "<<RAND_MAX<<endl;
        
    //trzeba zroznicowac srand czylis eed bo inaczej zawsze bedzie to samo 
    //#include <ctime>
    srand(time(nullptr));
    
    for (size_t i{1};i<=number_of_my_numbers;++i){
//        rand();
        cout<<rand()% max_random_number + min_random_number<<endl;
    }
    
    function_return_nothing();
    funkcja_z_argumentami(3,"abba");
    policze_objetosc_walca ();
    return 0;
}

int add_numbers(int a , int b){
    return a+b;
}

void function_return_nothing(){
    cout<<" funkcja gdzie nic nie zwracamy"<<endl;
}

int funkcja_z_argumentami(int a, std::string b){
    cout<<"zwroce liczbe a: "<<a<<" oraz string b:"<<b<<endl;
}

double pole_kola(double r){
    return pi*pow(r,2);
}

double objectosc_walca(double r, double h){
    return pole_kola(r)*h;
}

void policze_pole_kola (){
   cout<<"Poprosze promien kola do wyliczen:";
   double r{};
   cin>>r;
   cout<<"Pole powierzchni to: "<<pole_kola(r)<<endl;
}

void policze_objetosc_walca(){
    double r; double h;
    cout<<"Prosze podaj promien kola i wysokosc walca, w kolejnosci, po spacji: "<<endl;
    cin>>r>>h;
    cout<<"Objetosc wynosi: "<< objectosc_walca(r,h)<<endl;
}