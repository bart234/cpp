#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> vector1{};
    vector <int> vector2{};
    vector1.push_back(10);
    vector1.push_back(20);
    cout<<"vector 1:" <<vector1.at(0)<<" --- "<< vector1.at(vector1.size()-1)<<endl;
    vector2.push_back(100);
    vector2.push_back(200);
    cout<<"vector 2:"<<vector2.at(0)<<" --- "<<vector2.at(vector2.size()-1)<<endl;
    
    vector<vector<int>> vector2d{};
    vector2d.push_back(vector1);
    vector2d.push_back(vector2);
    cout<<"1th el of v2d: "<<vector2d.at(0).at(0)<<endl;
    cout<<"1th el of v2d: "<<vector2d.at(0).at(1)<<endl;
    cout<<"1th el of v2d: "<<vector2d.at(1).at(0)<<endl;
    cout<<"1th el of v2d: "<<vector2d.at(1).at(1)<<endl;
    vector1[0] = 1000;
    cout<<"1t el changed"<<endl;
    cout<<"1th el of v2d: "<<vector2d.at(0).at(0)<<endl;
    cout<<"1th el of v2d: "<<vector2d.at(0).at(1)<<endl;
    cout<<"1th el of v2d: "<<vector2d.at(1).at(0)<<endl;
    cout<<"1th el of v2d: "<<vector2d.at(1).at(1)<<endl;
    cout<<"el vectora 1"<<endl;
    cout<<"v1: "<<vector1[0]<<" el 2 "<<vector1[1]<<endl;
//    cout<<"2nd el of v2d: "<<vector2d.at(vector2d.size()-1)<<endl;
    
    return 0;
}