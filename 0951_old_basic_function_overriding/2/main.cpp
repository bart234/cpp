#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(int);
void print(double);
void print(string);
void print(string, string);
void print(vector<string>);

void print(vector<string>v){
    cout<<"Iteracja po vektorze: "<<endl;
    for (auto s:v){
        cout<<"print out: "<<s<<endl;
    }
}
void print( string s, string t){
    cout<<"Printing string x2 : "<<s<< " oraz vector t:"<<t<<endl;
}
void print(int num){
    cout<<" Printing int: "<< num<<endl;
}
void print(double num){
    cout<<" Printing double: "<< num<<endl;
}
void print(string num){
    cout<<" Printing string: "<< num<<endl;
}

int main(){
    print(100);
    print('A');
    print(123.2);
    print(23.3F); // flaot going to promote to double
    print("C-style string");
    string s{"C-style string"};
    print (s);
    vector<string>st{"larry","hans","iga"};
    print (st);
    return 0;
    }
