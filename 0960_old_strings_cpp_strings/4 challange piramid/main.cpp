#include <iostream>
#include <string>

using namespace std;

int main(){
    string str_in{};
    cout<<"======================================"<<endl;
    cout<<"              piramida"<<endl;
    cout<<"======================================"<<endl;
    cout<<"  Podaj tekst do zbudowania piramidy: "<<endl;
    getline(cin,str_in);
//    int r{str_in.length()};
//    cout<<r;
    string temp{str_in};
    string spaces{"                              "};
    string temp_rev{};
    for (int k{str_in.length()-1};k>=0;--k){
        temp_rev +=str_in[k];     
    }
    temp +=temp_rev;    
    
    int i{1};
    int a{};
    for (int r{0};r<str_in.length();++r){   
        a+=2;}
    
    a=a/2;
    for (int r{0};r<str_in.length();++r){        
        cout<<spaces.substr(0,a) <<temp.substr(0,i)<<endl;
        i+=2;       
        a-=1;}
    
	return 0;
    }
