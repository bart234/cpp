#include <iostream>
//40 to
//using  namespace std;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
    int fav_number;
    cout <<"Enter your number"<<endl;
    cout <<"Wyslij mnie do konsoli"<<endl;
    cin>> fav_number;
    cout<<"Podales numer w konsoli: " << fav_number<<endl;
 return 0;
}
/* 
 * cin >>wartosc1 >>wartosc2 - podajemy oddzielone spacjami
 *<< kierunek wysylania danych std::cout<< "do konsoli"
 * --------------------------
 * name space pozwala grupwoac kod
 * tak by definicje sie nie dublowaly
 * using  namespace std; -fajne ale niepraktyczne przy duzych programach
 * lepiej uzywac specyfikowanych using std::endl;
 * 
 */