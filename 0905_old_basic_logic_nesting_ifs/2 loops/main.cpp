#include <iostream>
#include <vector>
using namespace std;

int main(){
    /* range base loop */
    double scores[]{1.2,2.33,2.3};
//    for (double cyferka:scores){
//        cout<<cyferka<<endl;
//    }

//    for (auto cyferka:scores){
//        cout<<cyferka<<endl;
//    }
    string cos {"sfdsdf dsfdsfds dsfdsf"};
    cout<<cos<<endl;
    for (char literka:cos){
        if (literka == ' '){
            cout<<endl;
        }else{
        cout<<literka<<" ";
        }
    }
    /*for loop 
     * for (i = 1;i<5; ++1)
     * ywkonuje sie do momentu gdy warunek jest spelniony,
     * jak wejdzie na 5 to i<5 -> false wiec wychodzi z petli
    
    for(int i = 1;i<=10; ++i){
        cout<<((i%2==0)?"parzysta":"nieparzysta")<<endl;
        cout<<i<<endl;
    }
---------------------------------------------------------------------------
        for (int i =1, j=10; i<=10;++i,++j){
            cout<<i<<" "<<j<<endl;
        }
---------------------------------------------------------------------------        
        //''for (;;){
            cout<<"endles loop"<<endl;
        }

        for (int i = 10; i>=1;--i){
            cout<<i<<endl;
        }

        for (int i = 1;i<=100;++i){
            cout<<i<<"  ";
            cout<<((i%10==0)?"\n":"");
        }

        for (int i = 0;i<=100;i+=10){
            cout<<i<<"  ";
            for (int a=i+1;a<i+10;++a){
                cout<<a<<" ";
            }
            cout<<endl;
        }   
--------------------------------------with vectors-----------------------

    vector <int>heniek{10,20,30,40,50};
    for (int i =0;i<heniek.size();++i){
        cout<<heniek[i]<<endl;
    }
     
     int suma{0};
     for(int i=1;i<=2346;++i){
         suma += ((i%2==0)?i:0);
     }
     cout<<suma<<endl;
      * */
    return 0;
}