#include <iostream>
#include <vector>
using namespace std;


int main(){

    vector <int> test1{3,23,1,432,4};
    cout<< test1[1]<<endl;
    cout<< test1.at(2)<<endl;    
    cout<< "vektor.size: " <<test1.size()<<endl;
    test1.push_back(99);    
    cout<<"ostani element to: "<< test1.at(test1.size()-1)<<endl;
    test1.pop_back();
    cout<<"ostani element to: "<< test1.at(test1.size()-1)<<endl;
    test1.push_back(12);
    cout<<"ostani element to: "<< test1.at(test1.size()-1)<<endl;
    vector <vector <int>> test2;
    test2[1][3] = 22;
    
    }
    
