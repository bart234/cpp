#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> vector1;
    vector <int> vector2;
    vector1.push_back(10);
    vector1.push_back(20);
    cout<<"Element 0 v1: "<<vector1.at(0) <<endl;
    cout<<"element last v1: "<<vector1.at(vector1.size()-1) <<endl;
    
    vector2.push_back(100);
    vector2.push_back(200);
    cout<<"Element 0v2: "<< vector2.at(0)<<endl;
    cout<<"Element lastv2: "<< vector2.at(vector2.size()-1)<<endl;
    
    cout<<"================================="<<endl;
    cout<<"========== vektor 2D ============="<<endl;
    vector <vector <int>> v_2d;
    v_2d.push_back(vector1);
    v_2d.push_back(vector2);
    cout<<"Element v0 el0: "<<v_2d.at(0).at(0) <<endl;
    cout<<"element v0 last: "<<v_2d.at(0).at(v_2d[0].size()-1) <<endl;
    cout<<"Element v1 el0: "<< v_2d.at(1).at(0)<< endl;
    cout<<"Element v1 last: "<< v_2d.at(1).at(v_2d[1].size()-1)<<endl;
    cout<<"================================="<<endl;
    cout<<"========== change el [0][0] ============="<<endl;
    vector1.at(0) =1000;
    
    cout<<"1 el v1: " <<vector1.at(0)<<endl;
    cout<<"================================="<<endl;
    cout<<"========== vektor 2D ============="<<endl;
    cout<<"Element v0 el0: "<<v_2d[0][0] <<endl;
    cout<<"element v0 last: "<<v_2d[0][v_2d[0].size()-1] <<endl;
    cout<<"Element v1 el0: "<< v_2d[1][0]<< endl;
    cout<<"Element v1 last: "<< v_2d[1][v_2d[1].size()-1]<<endl;
    
    cout<<"================================="<<endl;
    cout<<"1 el v1: " <<vector1.at(0)<<endl;
    }
