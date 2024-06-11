#include <iostream>

using namespace std;    
int main(){

    int i1{10};
    int i2{20};
    i1 = i2;
    i2 = 55;
    i1=10;
    i2=20;
    cout<<"my val i1 is: "<< i1++ <<endl;
    cout<<"my val i2 is: "<< ++i2<<endl;
    cout<<"my val i1 is: "<< i1 <<endl;
    
    }
