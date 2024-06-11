#include <iostream>
#include <vector>

using namespace std;

int *function_return_ptr(int *a, int*b);
int *function_return_ptr(int *a, int*b){ // *a mowi nam co przyjdzie,czyli pointer
    if (*a > *b){
        cout<<"to wartosc a: "<<a<<endl;
        return a; // *a - dereferencja pointera w to wartosc, a - ptr do tej wartosci
    }else{
        return b;
    }
}

int main () {
    int a{15};int b{10};
    cout<<*function_return_ptr(&a,&b)<<endl; //funkcja pobiera adresy bo wymaga pointerow,i zwraca adres
                                            //ale przed funkcja jest * wiec robie dereferencje i zwraca wartosc
    return 0;
}