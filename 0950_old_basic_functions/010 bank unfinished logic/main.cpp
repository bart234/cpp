#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
class Dokumenty{
    
    vector<string> a100{"100", "tresc","ogolne","o","e","-"};
    vector<string> a200{"200", "tresc","ogolne","o","e","-"};
    vector<string> a123{"123", "tresc","ogolne","o","e","-"};
    vector<string> a203{"203", "tresc","ogolne","o","e","-"};
    
    //kk
    vector<string> a300{"300", "tresc","produkt","o","e","-"};
    vector<string> a305{"305", "tresc","produkt","o","e","-"};
    vector<string> a306{"306", "tresc","produkt","o","e","-"};
    vector<string> a307{"307", "tresc","produkt","o","e","-"};
    vector<string> a309{"309", "tresc","produkt","o","e","-"};
    vector<string> a310{"310", "tresc","produkt","o","e","-"};
    vector<string> a320{"320", "tresc","produkt","o","e","-"};
    vector<string> a331{"331", "tresc","produkt","o","e","-"};
    vector<string> a332{"332", "tresc","produkt","o","e","-"};
    vector<string> a333{"333", "tresc","produkt","o","e","-"};
    vector<string> a334{"334", "tresc","produkt","o","e","-"};
    vector<string> a335{"335", "tresc","produkt","o","e","-"};
    //kh
    vector<string> a320{"320", "tresc","produkt","o","e","-"};
    vector<string> a331{"331", "tresc","produkt","o","e","-"};
    vector<string> a332{"332", "tresc","produkt","o","e","-"};
    vector<string> a333{"333", "tresc","produkt","o","e","-"};
    vector<string> a334{"334", "tresc","produkt","o","e","-"};
    vector<string> a335{"335", "tresc","produkt","o","e","-"};
        
    //atrr
    public:
    void wydruk_ogolne(string nazwa_grupy = "ogolne"){
        vector<vector<string>> ogolne{a100,a200,a123,a203};
        int i{1};
        cout<<"Grupa: "<<nazwa_grupy<<endl;
        for(auto dok: ogolne){
            cout<<i<<".("<<dok.at(0)<<") "<< dok.at(3)<< " "<<dok.at(4)<< " "<<dok.at(1)<<endl;
            i++;}            
        cout<<endl;
        };
    
    void wydruk_produkt(string nazwa_grupy = "produkt",int rodzaj_produktu){
        int i{1};
        cout<<"Grupa: "<<nazwa_grupy<<endl;
        for(auto dok: produkt){
            cout<<i<<".("<<dok.at(0)<<") "<< dok.at(3)<< " "<<dok.at(4)<< " "<<dok.at(1)<<endl;
            i++;}            
        cout<<endl;
        };
};

int main(){
    
    //prototype
    int menu0_okresl_produkt();
    int menu1_rozdzielnosc_maj();
    int menu2_cel1_krd();
    int menu3_cel1_czy_zab_to_inw();
    int menu3a_czy_drugi_cel_krd();
    vector<int> menu4_dochody();
    int menu5_dochody_dz_gosp_rodzaje(vector<int> rodzaje_doch_int);
    
    Dokumenty dok;
    dok.wydruk_ogolne();
    
//	std::cout<<"My new spd"<<std::endl;   
//    
//    //lvl 0 - produkt
//    int prod{};  
//    prod = menu0_okresl_produkt();
////    
//    //lvl 1 - rozdzielnosc majatkowa
//    int rozdz{};     
//    rozdz = menu1_rozdzielnosc_maj();
//    
//    //lvl 2 - cel kedytu 
//    int cel1{0};
//    if (prod ==2){cel1 = menu2_cel1_krd();}
//    
//    //lvl 3
//    int czy_nieruch_jest_zabezp{}; 
//    if (prod ==2){czy_nieruch_jest_zabezp =menu3_cel1_czy_zab_to_inw();}
//    
//    // lvl 3a - czy jest drugi cel krd
//    int czy_drugi_cel_krd{};
//    if (prod ==2){czy_drugi_cel_krd=menu3a_czy_drugi_cel_krd();} 
//
//    // lvl 3b  - 
//    int cel2{0};
//    int czy_nieruch_jest_zabezp2{}; 
//    if (czy_drugi_cel_krd && prod ==2){ 
//        cel2 = menu2_cel1_krd();
//        czy_nieruch_jest_zabezp2 = menu3_cel1_czy_zab_to_inw();
//    }
//        
//    //lvl 4
//    vector <int> rodzaje_doch_int{};
//    rodzaje_doch_int = menu4_dochody();
//    
//    //lvl 5
//    int czy_rodz_rozliczenia {};
//    czy_rodz_rozliczenia = menu5_dochody_dz_gosp_rodzaje(rodzaje_doch_int);
//        
//    //zakonczenie
//    cout<<"Zakonczono generowanie"<<endl;
//    cout<<"Wybrano produkt :"<< prod<<endl;
//    cout<<"Rozdzielnosc majatkowa:"<< rozdz<<endl;
//    cout<<endl;
//    cout<<"Pierwszy cel kredytu to: "<< cel1<<endl;
//    cout<<"Pierwszy cel - czy inw jest zab: "<< czy_nieruch_jest_zabezp<<endl;
//    if (czy_drugi_cel_krd){
//        cout<<endl;
//        cout<<"Drugi cel kredytu to: "<<cel2<<endl;
//        cout<<"Drugi cel - czy inw jest zab: "<<czy_nieruch_jest_zabezp2<<endl;
//    }
//    cout<<"Wybranoa nastepujace dochody:";for (int i{0}; i<rodzaje_doch_int.size();++i){cout<<rodzaje_doch_int[i]<<", "; }  
//    cout<<endl;
//    cout<<"Efekt menu 5 to:"<< czy_rodz_rozliczenia<<endl;   
    
    
      
        
        
	return 0;
    }
   



int menu0_okresl_produkt(){  
        int prod{0}; 
        do{
             
            cout<<"Wybierz produkt:"<<endl;
            cout<<"1. Pozyczka hipoteczna"<<endl;
            cout<<"2  Kredyt mieszkaniowy"<<endl;
            cout<<"3. Kredyt konsolidacyjny"<<endl;        
            cin>>prod;
        }while(prod != 1 && prod != 2 && prod != 3) ;
        return prod;
        };

int menu1_rozdzielnosc_maj(){ 
        char rozdz{'a'};
        do{
            cout<<"Czy rozdzielnosc majatkowa? (Y/N)";
            cin>>rozdz;
        }while(rozdz != 'y' && rozdz != 'Y' && rozdz != 'n'&& rozdz != 'N');
        if (rozdz=='y' || rozdz=='Y'){
            return 1;
        }else{
            return 0;}
        };

int menu2_cel1_krd(){  
    
    int cel1{0};
        do{
            cout<<endl;
            cout<<"========================== cele kredytu ============================="<<endl;
            cout<<"           Jesli jeden cel kredytu wpisz numer tego celu."<<endl;
            cout<<"     Jesli sa dwa cele kredytu, wpisz numery obu celi po spacji"<<endl;
            cout<<"====================================================================="<<endl;
            cout<<"1.Zakup nieruchomosci na rynku wtornym (dzialka, dom jednorodzinny)"<<endl; 
            cout<<"2.Zakup nieruchomosci na rynku wtornym (lokal mieszkalny)"<<endl; 
            cout<<"3.Zakup nieruchomosci na rynku pierwotnym"<<endl; 
            cout<<"4.BUDOWA / ADAPTACJA / ROZBUDOWA DOMU JEDNORODZINNEGO systemem gospodarczym/ MODERNIZACJA (wymagające pozwolenia na budowe)"<<endl; 
            cout<<"5.REMONT/ WYKOŃCZENIE / MODERNIZACJA (bez pozwolenia na budowe)"<<endl; 
            cout<<"6.WYKUP (1) domu / lokalu mieszkalnego od gminy lub spoldzielni w drodze przetargu"<<endl; 
            cout<<"7.Zakup nieruchomosci w drodze l i c y t a c j i komorniczej"<<endl; 
            cout<<" 8.Zwrot czesci wydatkow poniesionych na zakup z rynku wtornego"<<endl; 
            cout<<"9.Zwrot czesci wydatkow poniesionych na zakup z rynku pierwotnego"<<endl; 
            cout<<"10.Zwrot czesci wydatkow poniesionych na budowe"<<endl; 
            cout<<"11.Refinansowanie kredytu mieszkaniowego"<<endl;          
            cin>>cel1;

        }while(cel1 <1 != cel1 > 11);
     return cel1;
};

int menu3_cel1_czy_zab_to_inw(){
     //lvl 3 - czy neiruchomosc bedzie zabezpieczeniem
    char czy_nieruch_jest_zabezp{'O'}; 
    do{
        cout<<"Czy nieruchomosc bedzie zabezpieczeniem? (Y/N)";
        cin>>czy_nieruch_jest_zabezp;
    }while(czy_nieruch_jest_zabezp != 'y' && czy_nieruch_jest_zabezp != 'Y' 
        && czy_nieruch_jest_zabezp != 'n'&& czy_nieruch_jest_zabezp != 'N') ;
        
    if (czy_nieruch_jest_zabezp=='y' || czy_nieruch_jest_zabezp=='Y'){
            return 1;
        }else{
        return 0;}
            
};

int menu3a_czy_drugi_cel_krd(){
    char czy_drugi_cel_krd{};
        do{
            cout<<"Czy istnieje drugi cel kredytu? (Y/N)";
            cin>>czy_drugi_cel_krd;
        }while(czy_drugi_cel_krd != 'y' && czy_drugi_cel_krd != 'Y' && czy_drugi_cel_krd != 'n'&& czy_drugi_cel_krd != 'N') ;
        
        if (czy_drugi_cel_krd == 'y' || czy_drugi_cel_krd == 'Y'){
            return 1;
        }else{
            return 0;
        };
};

vector<int> menu4_dochody(){    
   //lvl 4 -dodzaj dochodu
    int doch{22};
    vector <int> rodzaje_doch_int{};
        do{
            cout<<endl;
            cout<<"========================== dochody =================================="<<endl;
            cout<<"             Wpisz numer dochodu ktory Ciebie dotyczy"<<endl;
            cout<<"                 By zakonczyc wybor wybierz 0 "<<endl;
            cout<<"====================================================================="<<endl;      
            cout<<"1. UMOWA O PRACE -......"<<endl; 
            cout<<"2. UMOWA O PRACE - na terenie UE (poza RP)"<<endl; 
            cout<<"3. DZIALALNOSC GOSPODARCZA -JEDNOOSOBOWA DZIALALNOSC GOSPODARCZA*"<<endl; 
            cout<<"4. DZIALALNOSC GOSPODARCZA -SPOLKI JAWNE/CYWILNE*"<<endl; 
            cout<<"5. EMERYTURA / RENTA"<<endl; 
            cout<<"6. WYNAJEM LOKALI / DZIERZAWA GRUNTOW"<<endl; 
            cout<<"7. UMOWY ZLECENIA / O DZIELO"<<endl; 
            cout<<"8. MARYNARZE"<<endl; 
            cout<<"9. ROLNICY - Dochody z HA"<<endl; 
            cout<<"10. ROLNICY - Produkcja rolna"<<endl; 
            cout<<"11. ROLNICY - działy specjalne produkcji rolnej"<<endl; 
            cout<<"12. Swiadczenie wychowawcze 500+"<<endl;  
            cout<<endl;  
            cout<<"0. Przejdz dalej"<<endl;  
            cout<<"====================================================================="<<endl;   
            cin>>doch;

            if (doch > 0 && doch < 13 ) {
                rodzaje_doch_int.push_back(doch);}
            
        }while(doch != 0);


        cout<<"====================================================================="<<endl;   
        cout<<"Wybrano nastepujace dochody: ";          
        for (int i{0}; i<rodzaje_doch_int.size();++i){
            cout<<rodzaje_doch_int[i]<<", ";
        }  
        cout<<endl;  
        cout<<"====================================================================="<<endl;   
        cout<<endl; 
    return rodzaje_doch_int;
}

int menu5_dochody_dz_gosp_rodzaje(vector<int> rodzaje_doch_int){
    ////lvl 4a -dzialalanosc gosp - rodzaj rozliczenia
        //in czy_rodz_rozliczenia+
        bool czy_rodz_rozliczenia {false};
        int sOpodatkowania{0};
        
         for (int i{0}; i<rodzaje_doch_int.size();++i){            
            if (rodzaje_doch_int[i] ==3 || rodzaje_doch_int[i] ==4){
                czy_rodz_rozliczenia = true;
            };
        }  
        
        if (czy_rodz_rozliczenia) {
            
            do{
                cout<<"====================================================================="<<endl;   
                cout<<"Sposob opodatkowania"<<endl;  
                cout<<"1. ZASADY OGOLNE (KPiR)"<<endl;  
                cout<<"2. ZASADY OGOLNE (Ksiegi rachunkowe – pelna ksiegowosc)"<<endl;  
                cout<<"3. KARTA PODATKOWA"<<endl;  
                cout<<"4. RYCZALT OD PRZYCHODOW EWIDENCJONOWANYCH"<<endl;  
                cout<<"====================================================================="<<endl;   
                cin>>sOpodatkowania;
                
            }while(sOpodatkowania <1 && sOpodatkowania >5);
        }
        cout<<"====================================================================="<<endl;   
        cout<<"Wybrano nastepujacy sposob opodatkowania: "<<sOpodatkowania<<endl;
        cout<<"====================================================================="<<endl;   
        return sOpodatkowania;
}
