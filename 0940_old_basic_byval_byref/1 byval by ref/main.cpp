#include <iostream>
#include <string>
#include <vector>
using namespace std;

void swap_2_num(int &a, int &b);
void swap_normlany(int a, int b);

void print_guest_lists(vector<string> &guests, size_t guest_number);
void zmieniamy_funkcja_n_element_vektora(const string &element);
void czyscimy_vektor(vector<string> &guests);

void swap_2_num(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}

void swap_normlany(int a, int b){
    int temp = a;
    a=b;
    b=temp;
}
    
void print_guest_lists(vector<string> &guests, size_t guest_number){
    for (int i = 0;i < guest_number; ++i){
        cout<<"guest number "<<i+1<<" named: "<<guests[i]<<endl;
    }
}

void zmieniamy_funkcja_n_element_vektora(const string &element){
    element = "zmieniony el";
    //dodano contst wiec funkcje wyrzuca blad bo nie moze zmienic tej wartoci
}

void czyscimy_vektor(vector<string> &guests){
//    guests.clear(); - nie dziala nie wiadomo dlaczego 
    for (int i = 0 ;i<4;++i){
        guests[i]= "";
    }
//    print_guest_lists(guests,4);

}
    
int main () {

        vector<string> guests{"abba","beta","gamma","delta"};
        size_t guest_number{4};
        
        print_guest_lists(guests,guest_number);
        
        zmieniamy_funkcja_n_element_vektora(guests[2]);
        cout<<"zmieniamy element"<<endl;
        print_guest_lists(guests,guest_number);
        cout<< "czyscimy wektor"<<endl;
        czyscimy_vektor(guests);        
        print_guest_lists(guests,guest_number);
//    int a {22};
//    int b{8};
//    cout<< "a:"<<a<<"b:"<<b<<endl;
//    swap_2_num(a,b);
//    cout<< "a:"<<a<<"b:"<<b<<endl;
//    swap_normlany(a,b);
//    cout<< "a:"<<a<<"b:"<<b<<endl;
//    cout<< "a:"<<a<<"b:"<<b<<endl;
//    cout<< "a:"<<a<<"b:"<<b<<endl;
//    cout<< "a:"<<a<<"b:"<<b<<endl;
    return 0;
}
