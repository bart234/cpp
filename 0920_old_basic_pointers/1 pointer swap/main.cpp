#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b);
void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int main() {
    //1th set break point on left
    //perspecite -> debuglayout
    // next -> f10
    int i{5}; 
    while (i>0){
        cout<<i<<endl;
        i--;
    }
    
    return 0;
}