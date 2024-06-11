#include <iostream>
#include <vector>

using namespace std;

void double_it(int *myptr);
void swap_pointers(int *a, int *b);
void display_vector_in_pointer (vector<string>* viki);
void display_array_in_pointer(int*array,int sentinel);
void display_array_in_pointer(int*array,int sentinel){
    while(*array != sentinel){      // *array to wartosc 1-go elementu, jesli ejst rozna od ostatniego to lecimy dalej
        cout<<*array++<<endl;       // tutaj wartosc elementu *array - durkujemy wpier, a potem inkrementujamy 
    }                               //czyli  przesowamy na kolejny int, w array, ponownie, sprawdzenie, druk, inkrementacja
}
void display_vector_in_pointer (vector<string>*viki){  //dereference on start so we work on normal vector
    for (auto el: *viki){
        cout<<el<<endl;
    }
    (*viki).at(0) = "Bart"; // 1th dereference pointer, so we have vector, and after that we have availible all vector functions
}
void swap_pointers(int *a, int *b){
    cout<<"(value)*a: "<<*a<< ", (ptr adress)&a: "<<&a<< "(adress where ptr point to), a: "<<a<<endl;     
}

void double_it(int *myptr){
    *myptr = *myptr*2;
    cout<<"(value)*myptr: "<<*myptr<< ", (ptr adress)&myptr: "<<&myptr<< "(adress where ptr point to), myptr: "<<myptr<<endl;    
}



int main (){
    
    int arrr[]{34,342,3,-1};
    display_array_in_pointer(arrr,-1); //nie trzeba(nie mozna, nie da sie) uzywac & przy arr, bo 1el array to adres tej array
    
//    vector<string> viki {"Larry","curly","Stoog"};
//    display_vector_in_pointer(&viki);
//    cout<<endl;
//    display_vector_in_pointer(&viki);
//    cout<<endl;
    
    int a {22};
//    cout<<pointer_back(&a)<<endl;    
    cout<<a<<endl;
    double_it(&a);
     cout<<a<<endl;
    cout<<"adress of a is :"<<&a<<" and value of a is"<<a<<endl;
    int *a_ptr {&a};
    cout<<"pointer to has adress: "<<&a_ptr<<" and it contain adress to: "<<a_ptr<<endl;
    cout<<"adn that adress containt value :"<<*a_ptr<<endl;
    int b{9};
    a_ptr = &b;
    cout<<"i change adress in pointer so new adress is:"<<a_ptr<<" but pointer has this same adress: "<<&a_ptr<<endl;
    cout<<"and new value from new  place whare it point to: "<<*a_ptr<<endl;
   
   cout<<endl;
   cout<<"we can switch value on place where pointer point to, od adress in pointer!!!!"<<endl;
   swap_pointers(&a,&b);
   //in function pointer is going to create new adress for himself, so pointer &a i different then &a in some function, 
   //but both are poinng to this same place
   

 //char - array of characters
//    char name[] {"Frank"};
//    char *chr_ptr1{nullptr};
//    char *chr_ptr2{nullptr};
//    
//    chr_ptr1 = &name[1]; //r
//    chr_ptr2 = &name[3]; //n
    return 0 ;
}

