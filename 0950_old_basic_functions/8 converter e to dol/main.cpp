#include <iostream>
using namespace std;

int main()
{
    const double us_to_eur_ratio {1.19};
    cout<<"welcome in my conversion program"<<endl;
    cout<<"Please enter the value in euro: ";
    
    
    double euro{0.0};
    double dolar{0.0};
    
    cin>>euro;
    dolar = euro * us_to_eur_ratio;
    cout<<"You have "<< dolar<<" dolars"<<endl;
    
    return 0;
}