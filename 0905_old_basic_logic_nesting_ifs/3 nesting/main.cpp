#include <iostream>
#include <vector>

using namespace std;

int main() {

    int num_counter{0};
    vector<int> data{};
    
    cout<<"Tell me how many want store:";
    cin>>num_counter;
    for(int i=1;i<=num_counter;++i){
        int temp{};
        cout<<"give me a number"<<endl;
        cin>>temp;
        data.push_back(temp);
    }
    
    for(auto printit:data){
        cout<<printit<<" ";
    }
    cout<<endl;
//    for(int i = 1;i<=10;++i){
//        for (int a =5;a<=15;++a){
//            cout<<i*a<<"      ";
//        }
//        cout<<endl;
//    }
    
    
//    vector<vector<int>> olek { {1,2,3,4},{4,4,4,4},{6,6,6,6}};
//    
//    for (auto vOut:olek){
//        for(auto vIn:vOut){
//            cout<<vIn<<"  ";
//        }
//        cout<<endl;
//    }
    
//    for(int i =1;i<=10;++i){
//        for (int a=1;a<=10; ++a){
//            cout<<i*a<< " ";
//        }
//        cout<<endl;
//    }
    
    
    return 0;
}