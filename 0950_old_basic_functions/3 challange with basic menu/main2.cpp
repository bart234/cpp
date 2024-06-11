#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main(){
    
    char stat{};
    vector<int> vec{};
    do{
        
        cout<<endl;
        cout<<"=============================="<<endl;
        cout<<"     Menu glowne"<<endl;
        cout<<"=============================="<<endl;
        cout<<"Liczby w zakresie: ";
        for (auto x: vec){
            cout<<x<<", ";
            }
        cout<<endl;
        cout<<"==============================="<<endl;
        cout<<"P - Print number"<<endl;
        cout<<"A - Add a number"<<endl;
        cout<<"Z - Add a few numbers"<<endl;
        cout<<"M - Display mean of the numbers"<<endl;
        cout<<"S - Display the smallest number"<<endl;
        cout<<"L - Display the largest number"<<endl;
        cout<<"Q - Quit"<<endl;
        cout<<endl;
        cout<<"I chose: ";
        cin>>stat;
        
        switch (stat){
            case 's':
            case 'S':{
                int min_num{};
                min_num = vec[0];
                for( auto x: vec){
                    if (min_num >= x){
                        min_num= x;
                    }
                }
                cout<<"Min value from this arr is: "<<min_num<<endl; 
            }
            case 'q':
            case 'Q':{
                cout<<"Thanks br0"<<endl;
                break;}
            case 'a':
            case 'A':{
                cout<<"Put number: ";
                int numb{};
                cin>>numb;
                vec.push_back(numb);
                break;
            }
            case 'z':
            case 'Z':{
                cout<<"How many numbers would you add? ";
                int ct{};
                cin>>ct;
                for (int a{};a<=ct;++a){
                    cout<<"Podaj liczbe: "<<a<<endl;
                    int n1{};
                    cin>>n1;
                    vec.push_back(n1);
                }                
                break;
            }
            case 'm':
            case 'M':{
                double suma{};
                for (auto x: vec){ 
                    suma += x;
                    }
                cout<<"Avg of that numbers is: "<< suma/vec.size();
                break;
            }
            
            }
    cout<<endl;
        

    }while(stat != 'q' && stat != 'Q');
    
    
    return 0;
    }
