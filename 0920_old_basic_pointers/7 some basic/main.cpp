#include <iostream>
#include <vector>
#include <string>

using namespace std;

int *create_arr(size_t size, int init_val = 0){
    int * new_storage{nullptr};
    new_storage = new int{size};
    for (size_t i{0};i<size;++i)
        *(new_storage + i) = init_val;
    return new_storage;
        }

void display(const int *const arr, size_t size){
    for (size_t i{0};i<size;++i){
        cout<<arr[i]<<" ";
    cout<<endl;
    }
}
int main(){

    int *my_arr{nullptr};
    size_t size;
    int init_val{};
    
    cout<<"\nHow many itegers would like to allocate? :";
    cin>>size;
    cout<<"What valuewould like initialized to? ";
    cin>>init_val;
    
    my_arr = create_arr(size, init_val);
    
    
//    
//        int scores []{100,95,85,65, -1};
//        int *score_ptr(scores);
//        
////        while(*score_ptr != -1){
////            cout<<*score_ptr<<" adresy: "<<&*score_ptr<<endl;
////            score_ptr++;
////        }
//       
//        while(*score_ptr != -1){
//            cout<<*score_ptr++<<" adresy: "<<&*score_ptr++<<endl;
//        } 
        
    
    
//    int scores []{100,95,85};
//    
//    cout<<"adres scores 1: "<< scores<<endl;
//    
//    int *score_ptr{scores};
//    
//    cout<<"adres scores 1: "<< score_ptr<<endl;
//    
//    cout<<"array adresy:"<<endl;
//    cout<<"vartosci scores 0: "<< scores[0]<< " adresy: "<<&scores[0]<<endl;
//    cout<<"vartosci scores 1: "<< scores[1]<< " adresy: "<<&scores[1]<<endl;
//    cout<<"vartosci scores 2: "<< scores[2]<< " adresy: "<<&scores[2]<<endl;
//  
//    cout<<"pointers adresy:"<<endl;
//    cout<<"vartosci scores 0: "<< *score_ptr<< " adresy: "<<&*(score_ptr)<<endl;
//    cout<<"vartosci scores 1: "<< *(score_ptr +1)<< " adresy: "<<&*(score_ptr +1)<<endl;
//    cout<<"vartosci scores 2: "<< *(score_ptr+2)<< " adresy: "<<&*(score_ptr +2)<<endl;
//    
    
    
//    int *int_ptr{nullptr};
//    int_ptr = new int;
//    cout<<int_ptr<<endl;
//    delete int_ptr;
//    
//    
//    size_t size(0);
//    cout<<"How many temps? :";
//    cin>>size;
//    
//    double *temp_ptr(nullptr); //tworzy odwolanie do double
//    //towrzymy nowa zmienna double (bez nazwy) zawierajaca tablice 
//    //o wielkosci size
//    temp_ptr = new double[size]; 
//    //adres temp_ptr zwroci adres 1 elementu tej tablicy 
//    cout<<temp_ptr<<endl; 
//    
//    delete [] temp_ptr;
    
//        int score{100};
//        int *score_ptr{&score};
//        
//        cout<<"Adress of score: " << &score<<endl;
//        cout<<"Adress of score ptr: " << &score_ptr<<endl;
//        cout<<"Score ptr:"<< *score_ptr<<endl;
//        *score_ptr = 123;
//        cout<<"Score ptr: "<<*score_ptr<<endl;
//        cout<<"Score: "<<score<<endl;

//    int num{10};
//    cout<<"Value of num is: "<< num<<endl;
//    cout<<"sizeof of num is: "<< sizeof(num)<<endl;
//    cout<<"adress of num is: "<< &num<<endl;
//    cout<<endl;
//    int *p;
//    cout<<"Value of garbage in p is: "<< p<<endl;
//    cout<<"sizeof of p is: "<< sizeof(p)<<endl;
//    cout<<"adress of p is: "<< &p<<endl;
//    p=nullptr;
    
//    cout<<"value of p is: "<< p <<endl;
    
    return 0;
    }

