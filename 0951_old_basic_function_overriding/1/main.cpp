#include <iostream>
#include <cmath>
using namespace std;

//prototype function
double square(int a, int b =0);
//double square(int a, int b);
double square(double a, double b);
double rectangle(int b, int h);
double rectangele(double b, double h);
double romb(int floor, int celing, int h);
double romb(double floor, double celing, double h);


double romb(int floor, int celing, int h){
    return celing*h + rectangle(((floor-celing)/2),h)+ rectangle(((floor-celing)/2),h);
}

double rectangle (int b, int h){
    cout<<"int square"<<endl;
    return b*(0.5)*h;
}

double rectangle (double b, double h){
    cout<<"double square"<<endl;
    return b*(0.5)*h;
}

double square(int a, int b){
    if (b == 0) {
        cout<<"int square default"<<endl;
        return a*a;}
    else{
        cout<<"int square "<<endl;
        return a*b;
    }
}


//double square (int a, int b){
//    cout<<"int square"<<endl;
//    return a*b;
//}

double square (double a, double b){
    cout<<"double square"<<endl;
    return a*b;
}

main () {
    
    cout<<"int square default"<<square(2)<<endl;
    cout<<"int square "<<square(2,3)<<endl;
    cout<<"double square "<<square(2.3,3.1)<<endl;
    cout<<"double square default return int "<<square(2.3)<<endl;
    cout<<"double romb "<<romb(6,4,3)<<endl;
    
    
    return 0;
}