#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    vector<string> viki{"Bartek","Ola","Katarzyna"};
    
    for(auto el: viki){
        cout<<el<<endl;
        el = "abba"; // nie zmienia niczego bo do petli zostala zrobbiona kopia        
    }
    
    for (auto &el:viki){
        el = "abba";    // dodanie & sprawilo ze pobrany zostal adres czyli referencja, wiez zmieniono all
        cout<<el<<endl;
    }
    
//        for (auto const &el:viki){
//        el = "abba";    // dodanie & jeszcze const sprawia ze owszem to referencja ale nie zmienimy niczego bo jest const
//        cout<<el<<endl;
//    }
        
        
        
    int val{10};
    int &val_ref1 = val;
    cout<<val_ref1<<endl;
    int &val_ref2 = val;
    cout<<val_ref2<<endl;
    val_ref1 = 1;
    cout<<val_ref1<<endl;
    cout<<val_ref2<<endl;
    
    //int &val_ref3 = 122; - to wyrzuca blad bo  nie moze byc referencji do wartosci nie stalej, tzn bez zmiennej
    return 0;
}