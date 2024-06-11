#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int add_numbers(int a, int b){
    return a + b;
}

int main(){
    
    
    int a{1}, b{5};
    srand(time(nullptr));
    
    for (int i{0};i<=4;++i){
        cout<<"num "<<i<<": "<<rand()%b<<endl;
    }
//	bool zmien_mnie{true};    
//    while(zmien_mnie){
//        cout<<"Wpisz dwie liczby tak by otrzymac o ktorej mysle"<<endl;
//        int a{}; 
//        int b{};
//        cin>>a>>b;
//        cout<< add_numbers (a,b)<<endl;
//        if (20 ==add_numbers (a,b)){
//            zmien_mnie = false;
//            cout<<"Niezle, zgadles"<<endl;
//        }
//        
//    }
    return 0;
    }

