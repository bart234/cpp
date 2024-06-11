#include <iostream>

using namespace std;
int main (){
//    int test{1};
//    cout<< (test== 0? "mamy zero" : "mamy else")<<endl;
        cout<<"Please put 2 number separated by space"<<endl;
        int v1{0}, v2{0};
        cin>>v1>>v2;
        
        if( v1 != v2){
            cout<<" value:" <<((v1>v2)?v1:v2)<< " is bigger then " <<((v1<v2)?v1:v2) <<endl;
            //(condition)?true:false
        }else{
            cout<<"they are equal!!"<<endl;
        }
    return 0;
}
