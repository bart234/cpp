#include <iostream>

using namespace std;
//pre
unsigned int long long fact (unsigned int long long n);
unsigned int long fib (unsigned int long n);


int main(){ 
    cout<<"Moj wynik to: "<<fact(22)<<endl;
    //cout<<"Fib 1: "<< fib(20)<<endl;
	return 0;
    }

unsigned int long fib (unsigned int long n){
    if (n <=1)
        return n;
    return fib(n-1)+fib(n-2);
    
    
    
    
}



unsigned int long long fact (unsigned int long long n){
    cout<<n<<endl;
    if (n==0)
        return 1;    
    return n*fact(n-1);
    
}