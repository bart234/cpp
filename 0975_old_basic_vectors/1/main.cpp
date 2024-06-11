#include <iostream>
#include <vector>

using namespace std;
int main()
{
    /* container in standard c++ lib, 
     * can grow and shrink, 
     * syntax like arrays continusly in memory, 
     * bounds checking (if use at)
     * must have using namespace std;
     * first element = 0 , last one = len(vector) -1
     * -> vector <type> <name> (number_of_elements - automaticly set to 0)  */
    vector <char> vowels {'a','e','i','o','u'};
    
    /* vector <double> hi_temperatures (365, 80.0); -> it create 365 doubles with value = 80.0 */
    //    vector <double> hi_temperatures (365, 80.0);
	
    std::cout<<vowels[2]<<std::endl;
    std::cout<<"try to give me something from 4 el: " <<vowels.at(4)<<std::endl;
    
    vector <int> someVect {100,90,80};
    someVect.push_back(70); //add at end    
    someVect.push_back(60);
    cout<<someVect.at(0)<<endl;
    cout<<someVect.at(1)<<endl;
    cout<<someVect.at(2)<<endl;
    cout<<someVect.at(3)<<endl;
    cout<<someVect.at(4)<<endl;
    
    //INICJOWANIE
    vector <int> cos; // zainiciowany
    vector <int> cos1 (5); //okreslony liczba , ale bez wartosci - same zera
    vector <int> cos2 {1,2,3,4,5}; // komplet informacji
    vector <int> cossztuk5z100 (3,100); //3 elementy z wartoscia 100
    
    //SPRAWDZANIE WIEZOW
    cout<<cos2[2] <<endl;// drukowanie 3-go elemntu , lub czegos z pamieci jesli poza zakresem
    cout<<cos2.at(2) <<endl; // drukowanie 3- elementy ale sprawdza wiezy 
    
    cout<<"Wielkosc vektora: " << cos2.size()<<endl;
    
    //DODAWANIE DO WEKTORA
    int wepchnijCosNaKoniec {};
    cin>>wepchnijCosNaKoniec;
    cos2.push_back(wepchnijCosNaKoniec);
    cout<<"Wielkosc vektora: " << cos2.size()<<endl;
    
    //Wektor 2d to WEKTOR WEKTOROW
    vector <vector<int>> tablica2D 
    {
        {1,2,3},
        {3,3,3},
        {4,4,4},
        {34,23,23}
    };
    
    cout<<tablica2D[0][0]<<endl;
    cout<<tablica2D[0][1]<<endl;
    cout<<tablica2D[0][2]<<endl;
    cout<<tablica2D[0][3]<<endl; // tu nic nie ma
    
    cout<<tablica2D.at(0).at(0)<<endl;
    cout<<tablica2D.at(0).at(1)<<endl;
    cout<<tablica2D.at(0).at(2)<<endl;
    cout<<tablica2D.at(0).at(3)<<endl; //tu tez nic nie ma ale zwraca info
    
	return 0;
}
