#include <iostream>
#include <string>
#include <vector>

using namespace std;





void print_guest_list(string guests[], size_t number_of_guests);
void clear_guests_list(string guests[], size_t number_of_guests);

void clear_guests_list(string guests[], size_t number_of_guests){
    for (int i = 0; i<number_of_guests;++i){
        guests[i] = "";
    }
}


void print_guest_list(string guests[], size_t number_of_guests){
    for (int i = 0; i<number_of_guests;++i){
        cout<<"This is guest number: "<<i+1<<" called: "<< guests[i]<<endl;
    }
}


int main() {
    
    string guests[]{"abba","beta","gamma", "delta"};
    int guests_number{4};
    print_guest_list(guests, guests_number);
    clear_guests_list(guests, guests_number);
    cout<<"wyczyszczono gosci"<<endl;
    print_guest_list(guests, guests_number);
    
    return 0;
}