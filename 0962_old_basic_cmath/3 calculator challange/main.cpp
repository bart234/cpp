#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
//prototypes ----------------------------------
char low_up_TO_LOW(char st);
void menu_head();
void menu_menu();
void menu_zapis(double w1);
double menu_add(double w1);
double menu_minus(double w1);
double zapis_wyniku(char el_to_check,double wynik, double w1);

int main(){
    
    char input_thing{};
    double w1{};
    bool yn{false};
    
    do{
        double a{},b{},c{},d{};
        
        menu_head();
        if (w1){
            menu_zapis(w1);}
        menu_menu();

        
        cin>> input_thing;
        input_thing = low_up_TO_LOW(input_thing);   
        
        switch (input_thing){
            case 'q': 
            {            
                w1 =menu_add(w1);
                break;
            }        
            case 'w':
            {
                w1 =menu_minus(w1);
                break;
            }
            case 'e':{
                cout<<"nacisnieto - e"<<endl;
                break;
            }
            case 'r':{
                cout<<"nacisnieto - r"<<endl;
                break;
            }
            case 'a':{
                cout<<"nacisnieto - a"<<endl;
                break;
            }
            case 's':{
                cout<<"nacisnieto - s"<<endl;
                break;
            }
            case 'c':{
                w1 = 0;
                cout<<"Wyczyszczono pamiec"<<endl;
                break;
            }
        }
    
       
    
    cout<<endl;
    }while(input_thing!='m' );
    
    cout<<"Dziekujemy za wspolprace"<<endl;
    return 0;
    
    }


// functions----------------------------
double menu_minus(double w1){
    if (w1){
        cout<<"============Odejmowanie============"<<endl;
        cout<<"    w pamieci znaleziono zmienna: "<<w1<<endl;
        cout<<"==================================="<<endl;
        cout<<"Czy chcesz wykonac na niej dzialanie?"<<endl;
        cout<<"(Y/N)";
        char yn{};
        cin>>yn;
        if (low_up_TO_LOW(yn)=='y'){
                cout<<"========================================================"<<endl;
                cout<<"         W jaki sposob chesz uzyc zmiennej ?"<<endl;
                cout<<"  Wybierz:1  by "<<w1<<" - n (nowa liczba)"<<endl;
                cout<<"  Wybierz:2  by n (nowa liczba) - "<<w1<<endl;
                cout<<"========================================================"<<endl;
                char temp{};
                do {                   
                    cin>>temp;
                    if (temp!='1' &&temp!='2'){
                        cout<<"Nie wybrano poprawnej opcji"<<endl;
                    }
                }while (temp != '1' && temp !='2');
                    
                cout<<"===========Odejmowanie==========="<<endl;
                double n{};
                double r{};
                if (temp =='1'){
                    cout<<"Podaj nowa liczbe ktora zostanie odjeta od "<<w1<<endl;                    
                    cin>>n;
                    cout<<"Wynik odejmowania podanych liczb to: "<<w1-n<<endl;
                    r =w1-n;
                    cout<<endl;
                } else{
                    cout<<"Podaj nowa liczbe od ktorej chcesz odejac "<<w1<<endl;
                    cin>>n;
                    cout<<"Wynik odejmowania podanych liczb to: "<<n-w1<<endl;
                    r =n-w1;
                    cout<<endl;
                } 
                
                cout<<"Czy zapisac wynik (Y/N) ?"<<endl;
                char yn{};
                cin>>yn;
                return zapis_wyniku(yn,r,w1);
           
        }else if (low_up_TO_LOW(yn)=='n'){
            cout<<"========Odejmowanie=========="<<endl;
            cout<<"Podaj liczby ktore chcesz odjac (rozdzielone spacja):"<<endl;
            double a{},b{};
            cin>> a >>b;
            cout<<"Wynik odejmowania podanych liczb to: "<<a-b<<endl;
            cout<<endl;
            cout<<"Czy zapisac wynik (Y/N) ?"<<endl;
            char yn{};
            cin>>yn;
            return zapis_wyniku(yn,a-b, w1);   
        }else{
            cout<<"#########################################"<<endl;
            cout<<"Wybrano bledny skrot, sprobuj jeszcze raz"<<endl;
            cout<<"#########################################"<<endl;
            return w1; 
        }

    }else{
        cout<<"========Odejmowanie=========="<<endl;
        cout<<"Podaj liczby ktore chcesz odjac (rozdzielone spacja):"<<endl;
        double a{},b{};
        cin>> a >>b;
        cout<<"Wynik odejmowania podanych liczb to: "<<a-b<<endl;
        cout<<endl;
        cout<<"Czy zapisac wynik (Y/N) ?"<<endl;
        char yn{};
        cin>>yn;
        return zapis_wyniku(yn,a-b,w1);        
    }
}

double menu_add(double w1){
    if (w1){
        cout<<"==============Dodawanie============"<<endl;
        cout<<"w pamieci znaleziono zmienna: "<<w1<<endl;
        cout<<"==================================="<<endl;
        cout<<"Czy chcesz dodac do niej liczbe?"<<endl;
        cout<<"(Y/N)";
        char yn{};
        cin>>yn;
        if (low_up_TO_LOW(yn)=='y'){
            cout<<"===========Dodawanie==========="<<endl;
            cout<<"Podaj liczbe ktora chcesz dodac:"<<endl;
            double a{};
            cin>>a;
            cout<<"Wynik dodawania podanych liczb to: "<<w1+a<<endl;
            cout<<endl;
            cout<<"Czy zapisac wynik (Y/N) ?"<<endl;
            char yn{};
            cin>>yn;
            return zapis_wyniku(yn,w1+a,w1);
            
        }else if (low_up_TO_LOW(yn)=='n'){
            cout<<"========Dodawanie=========="<<endl;
            cout<<"Podaj ktore chcesz dodac (rozdzielone spacja):"<<endl;
            double a{},b{};
            cin>> a >>b;
            cout<<"Wynik dodawania podanych liczb to: "<<a+b<<endl;
            cout<<endl;
            cout<<"Czy zapisac wynik (Y/N) ?"<<endl;
            char yn{};
            cin>>yn;
            return zapis_wyniku(yn,a+b, w1);   
        }else{
            cout<<"#########################################"<<endl;
            cout<<"Wybrano bledny skrot, sprobuj jeszcze raz"<<endl;
            cout<<"#########################################"<<endl;
            return w1; 
        }

    }else{
        cout<<"========Dodawanie=========="<<endl;
        cout<<"Podaj ktore chcesz dodac (rozdzielone spacja):"<<endl;
        double a{},b{};
        cin>> a >>b;
        cout<<"Wynik dodawania podanych liczb to: "<<a+b<<endl;
        cout<<endl;
        cout<<"Czy zapisac wynik (Y/N) ?"<<endl;
        char yn{};
        cin>>yn;
        return zapis_wyniku(yn,a+b,w1);        
    }
}

double zapis_wyniku(char el_to_check,double wynik, double w1){
        if (low_up_TO_LOW(el_to_check) =='y'){        
            cout<<"Wynik zapisano w pamieci"<<endl;
            return wynik;
        }else if (low_up_TO_LOW(el_to_check) =='n'){
            cout<<"Wyniku nie zapisano"<<endl;
            return w1;
        }else{
            cout<<"#########################################"<<endl;
            cout<<"Wybrano bledny skrot, sprobuj jeszcze raz"<<endl;
            cout<<"#########################################"<<endl;
            return w1;
        };
}

void menu_zapis(double w1){
    cout<<"================================="<<endl;
    cout<<"Elementy zapisane w pamieci: "<<w1<<endl;
    cout<<"================================="<<endl;
    cout<<"  c - czyszczenie pamieci"<<endl;
    cout<<"================================="<<endl;
}

char low_up_TO_LOW(char st){
        if (isupper(st)){
            return tolower(st);
        }
    return st;
}

void menu_head(){
    cout<<"================================="<<endl;
    cout<<"             Kalkulator"<<endl;
    cout<<"================================="<<endl;
    cout<<"              Menu"<<endl;
    cout<<"   Podaj oznaczenie dzialania:"<<endl;
}

void menu_menu(){
    cout<<"q - Dodawanie"<<endl;
    cout<<"w - Odejmowanie"<<endl;
    cout<<"e - Mnozenie"<<endl;
    cout<<"r - Dzielenie"<<endl;
    cout<<"a - Pierwiatek"<<endl;
    cout<<"s - Potega"<<endl;
    cout<<endl;
    cout<<"m - Quit"<<endl;
    
    cout<<endl;
}