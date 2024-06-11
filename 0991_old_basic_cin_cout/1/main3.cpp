#include <iostream>>
using namespace std;

int main(){
	cout<<"Podaj 2 liczby,druga po spacji: ";
    
    double num1{10},num2{20};
    bool result{false};
    
    cout<<boolalpha;
    cout<<"Czy sa num1>10 or num2>20: "<< (num1 >10 || num2 >20 )<<endl;

    }
