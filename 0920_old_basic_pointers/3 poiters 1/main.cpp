#include <iostream>
#include <string>

using namespace std;

void display (int *arr, int size);
void display (int *arr, int size){
    for (int i = 0;i<size;i++){
        cout<<*(arr+i)<<endl;
    }
}

int *return_temp_arr(int size, int def_value);
int *return_temp_arr(int size, int def_value =0){
    int *arr{nullptr};
    arr = new int[size];
    for (int i =0;i<size;++i){
        arr[i] = def_value;
    }
    return arr;  
}

int main (){
    int *new_temp_arr{nullptr};
    new_temp_arr = return_temp_arr(5,22);
    
    display(new_temp_arr,5);
    
    //-----------------------------------------------------
    int score[]{95,96,96,98,99,-1};
    int *score_ptr{score};
    
    //petla sie wylancza w momencie trafienia na -1 czyli ostatnia liczbe w tablicy
    while (*score_ptr != -1){       //sprawdza warosc el docelowego
        cout<<*score_ptr<<endl;     //drukuje wartosc elementu docelowego
        score_ptr++;                // to pointer wiec dodaje +1 do niego, przechodzac do kolejnego el w tablicy
        
        //cout<<*score_ptr++<<endl; //to bardziej zaawansowany kawalek odpowiadam temu powyzej ale w jednej linijce
                                    // dzialanie to dereferencing pointer i jego uzycie - czyli wydruk, a nastepnie  append pointera
                                    // wynika to z sekwencji znakow  czyli wpierw * a potem ++ (ktore jest wykonywan epo uzyciu)
    }
    
    
    //porownywanie
    string s1 {"Frank"};
    string s2 {"Frank"};
    string s3 {"Frank"};
    
    string *p1 {&s1};
    string *p2 {&s2};
    string *p3 {&s1};
    
    cout<<boolalpha;
    
    cout<<(p1 ==p2)<<" porownanie p1 i p2 - porownuje adresy w pointerze (tutaj rozne)"<<endl;
    cout<<(p1 ==p3)<<" porownanie p1 i p3 - porownuje adresy w pointerze (tutaj takie same)"<<endl;
    cout<<endl;
    cout<<(*p1 ==*p2)<<" porownanie p1 i p2 jako ptr - porownuje artosci pod adresami"<<endl;
    cout<<(*p1 ==*p3)<<" porownanie p1 i p3 jako ptr - porownuje artosci pod adresami"<<endl;
    
    return 0;
}
