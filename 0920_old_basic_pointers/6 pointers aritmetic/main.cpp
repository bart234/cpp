#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    int num {10};
    
    cout<<"Num vlaue: "<<num<<endl;
    cout<<"Num size: "<<sizeof(num)<<endl;
    cout<<"Num address: "<< &num<<endl;
    
    int *num_ptr{nullptr};                                      //initialize pointer and clear "point to" to null
    cout<<"num ptr with garbage: "<<num_ptr<<endl;
    
    num_ptr = &num;                                             // add to pointer, address of num value
    cout<<"num ptr with adress to num: "<<num_ptr<<endl;        
    *num_ptr = 12; //                                           // set 12 to a value on adress in pointer  (in num)
    
    cout<<"Num vlaue: "<<num_ptr<<endl;     //return adress form pointer
    cout<<"Num vlaue: "<<*num_ptr<<endl;    //return value from pointer
    
    int abba {2};
    num_ptr = &abba;
    cout<<"changed num value: "<<*num_ptr<<endl;        //return changed value in pointer
    
    abba = 3;
    cout<<"changed num value: "<<*num_ptr<<endl;        // value changed by variable to wchih is a pointer abba
    
    
    string myname {"Bartek"};
    string *myname_ptr{nullptr};
    myname_ptr = &myname;
    cout<<"ptr with my anme is: "<<*myname_ptr<< " and has adress:"<<myname_ptr<<endl;
    cout<<"adres of myname is: "<<&myname<<endl;
    myname= "Iga";
    cout<<"We change myname vlaue so: "<<endl;
    cout<<"ptr with my anme is: "<<*myname_ptr<< " and has adress:"<<myname_ptr<<endl;
    cout<<"adres of myname is: "<<&myname<<endl;
    
    
    vector<string> stooges{"Barget","Iga","Iza"};
    vector<string> *stooges_ptr {nullptr};
    stooges_ptr = &stooges;
    
    cout<<"First name from vector: "<<(*stooges_ptr)[0]<<" " <<(*stooges_ptr)[2]<<endl;
    //cout<<"First name from vector: "<<(*stooges_ptr).at(2)<<endl;  //error
    cout<<"A: "<<&stooges[0]<< " "<< &stooges[1] <<endl;
    cout<<"A: "<<(*stooges_ptr)[0]<< " "<< (*stooges_ptr)[2] <<endl;  
            // pobiernaie wartosci pt musi  byc w nawiasie bo inaczej chce mnozyc
    
    for(string el:*stooges_ptr){
        cout<<el<<endl;
    }
    
    int *my_ptr_without_variable{new int};
    *my_ptr_without_variable = 22;
    cout<<"This is myptr without variable: " <<*my_ptr_without_variable<<endl;
    delete my_ptr_without_variable;         //and relese memory for that    
    
    cout<<"---------------------------------------------------------"<<endl;
    
    size_t arr_size{};
    cout<<"How many elements doyou want store?"<<endl;
    cin>>arr_size;
    double *arr_double_ptr{nullptr};           // inicjacja pointera do arr
        arr_double_ptr = new double[arr_size];
    
//    double *arr_double_ptr {new double[arr_size]};
    for (int i =0; i<arr_size;i++){
        cout<<"adress of el "<<i<<" is: "<<(arr_double_ptr+i)<<" value arr place is:" <<arr_double_ptr[i]<<" and adress is: "<<&arr_double_ptr[i]<<endl;
    }
//    cout<<"My array 1th element: " <<arr_double_ptr<<endl;
//    cout<<"el number: "<<3 <<" "<<(arr_double_ptr+3)<<endl; 
//    cout<<"el number: "<<4 <<" "<<(arr_double_ptr+4)<<endl;
    delete [] arr_double_ptr;               // !!!!!!!!!!!!!!!!!!!! zwalnianie przestrzeni poarr
    
    
    
    return 0;
}