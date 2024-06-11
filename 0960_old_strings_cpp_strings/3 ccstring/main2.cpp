#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main(){
    
    char f_name[20]{};
    char l_name[20]{};
    char all_name[20]{};
    char temp[20]{};
    
	cout<<"ener your first name "<<endl;
    cin>>f_name;    
    
	cout<<"ener your last name "<<endl;
    cin>>l_name;
    
    cout<<"dlugosc imienia: "<< strlen(f_name)<<endl;
    cout<<"dlugosc nazwiska: "<< strlen(l_name)<<endl;
    
    return 0;
    }
