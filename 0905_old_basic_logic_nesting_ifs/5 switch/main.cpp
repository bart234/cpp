#include <iostream>

using namespace std;
 
int main(){
    //towrzenie nowej grupy , nowego rodzaju obiektu ze slownikiem
    enum Direction{
        left,right,up,down
    };
    
    Direction  zmienna{left};
    
    //jelsi uzywamy obiektu z konkretnymi elementami to kompilator wyrzuci informacje ze cos nie jest obsluzone
    switch (zmienna){
    case left: {cout<<"lewo"<<endl;break;}
    case right: {cout<<"prawo"<<endl;break;}
    }
    
//------------------------------------------------switch    
//    int test{0};
//    cout<<"Give me some number between 1 and 100"<<endl;
//    cin>>test;
//    
//    switch (test){
//        
//        case 1: {cout<<"This is 1"<<endl;break;}  // jesli wejdzie case 1 to break pozwoli wyjsc ze switcha, by nie sprawdzla reszty warunkow
//        case 2: {
//            cout<<"This is 2"<<endl;
//            cout<<"You lucky guy - you won"<<endl;
//            cout<<"Please put second number to check your luck (between 1  to 5)"<<endl;
//            int test2{0};
//            cin>>test2;
//            switch (test2){
//                case 4: {
//                    cout<<"Gratz you won 1th price"<<endl;break;}
//                case 5:{
//                    cout<<"Grats , 2nd price is yours!"<<endl;break;}
//                default:{
//                    cout<<"Sorry you have to try next time"<<endl;break;}                
//            }
//            break;            
//        }
//        case 3: {cout<<"This is 3"<<endl;break;}
////        default:cout<<"Bigger then 3"<<endl;
//    }
    return 0;
}