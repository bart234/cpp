#include <iostream>
#include <cctype>   //string base function
#include <cstring> //string function
using namespace std;
int main(){
    
    // cctype - funkcje do testowania znakow
    /* isalpha - is etter
     * isalnum - letter or number
     * islower/isupper 
     * isspace
     * f<- tolower(<>)
     * f<- toupper(<>)
     * */
     
     //cctyle string (as array), end by (zero/null at the end) np: "Bartek0"
    /* char imie[10]{"Bartek"};
     imie[6] = 'g';
     cout<<imie;
     cout<<endl;
    */
     //   imie = "Brtk" // nie mozna tego robic z tym rodzajem str, ma zapis w pamieci i nei mozna tego tak podmienic
     
     //trzeba zaimoirtowac cstring
     /*strcpy(imie,"Brtk");
     cout<<imie<<endl;
    */
 
    //  for (auto lett: imie){cout<<imie<<endl;}
    
//    char stg[10]{} ;
//    cout<<stg<<endl;

    char brtk[10]{"Bartek"};
//    cout<<strlen(brtk)<<endl;  //ta funkcja zwraca <size_t>
//    cout<<strcat(brtk, "_end");
//    cin.getline(30) //limit znakow na cin
//    cout<<strcmp("porownan","porownan")<<endl; //porownanie string-ow -> 0 = takie same, 1 = inne
    return 0;
}