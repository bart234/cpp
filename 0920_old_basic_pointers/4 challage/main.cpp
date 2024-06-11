#include <iostream>

using namespace std;

int *r_arr(int *arr, int size_arr1); //, int arr2[], int size_arr2);
int *r_arr(int *arr, int size_arr1, int *arr2, int size_arr2){
    
    int temp_size {size_arr1*size_arr2};
    
    int *temp_arr_ptr{nullptr};             // dynamic array on heap
    temp_arr_ptr = new int [temp_size];
    
    int counter{0};
    for(int a = 0;a<size_arr1;++a){
        for(int b=0; b<size_arr2;++b){
            cout<<counter<<endl;
            *(temp_arr_ptr+counter) = *(arr +a) * *(arr2+b);
            counter ++;
            
        }        
    }
    return temp_arr_ptr;

}

void print_me(int *arr, int size);
void print_me(int *arr, int size){
    
    for (int i = 0;i<size;++i){      
       cout<<*(arr+i)<< " " << (arr+i)<<endl;
    }
}

int main(){
    
    int arr_1[5]{1,2,3,4,5};
    int arr_2[3]{10,20,30};
    int *result_arr {nullptr};
    result_arr = r_arr(arr_1,5,arr_2,3);
    print_me(result_arr, 5*3);
    delete [] result_arr;
    
    
    return 0;
}