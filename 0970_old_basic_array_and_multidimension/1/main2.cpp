#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
    
//    int a[]{10,20,304,43};    
//    for (auto x:a)
//        cout<<x<<endl;

    vector<double> temp{32.2,89.2,74.2,99.2};
    double avg_t{};
    double suma{};
    
    for (auto x: temp){
        suma +=x;
    }
    
    avg_t = ((temp.size()==0)?0:suma/temp.size());
    cout<<fixed<<setprecision(1);
    cout<<"Avg temp is: "<< avg_t<<endl;
    
    return 0;
    }
