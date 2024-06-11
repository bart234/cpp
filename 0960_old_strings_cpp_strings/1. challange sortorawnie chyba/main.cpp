#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main(){
    string person1{"Issac Dewton"};
    string person2{"Cesla"};
    string person3{"Jan Sebastian Bach"};
    string p4{"Krzysztof Penderecki"};
    string p5{"Ola Wielkopolska"};
    

    vector <string> arr{};
//    cout<<"Tell us how many ppl you want sort?"<<endl;
//    int count{}; 
//    int i{1};
//    cin>>count;
//        
//    cout<<"Podaj imiona i nazwiska"<<endl;  
//    
//    while(i<=count+1){
//        string temp;
//        getline(cin,temp);
//        arr.push_back(temp);
//        ++i;
//    }
    
    
    arr.push_back(p4);
    arr.push_back(p5);
    arr.push_back(person1);
    arr.push_back(person2);
    arr.push_back(person3);
    //take surname
    vector <string> vector_just_surname{};
    vector <string> user_name_in_parts{};
    bool is_space {false};
    
    for(auto el: arr){
        // if has a space
        for (auto letter: el){
            
            if (isspace(letter)>0){
                is_space = true;
//                cout<<el<<" ma spacje"<<endl;
            }
        }
            
        if (is_space == true) {
            //separate by spaces and take last one
            int place_of_space{};
            for (int i = 0;i<el.length();++i){
                if (isspace(el[i])>0){
                    place_of_space = i;
//                    cout<<i<<endl;
                    }
                is_space = false;            
                }
//            cout<<"Moje nazwisko to:"<< el.substr(place_of_space+1,el.length()- place_of_space+1)<<endl;
            vector_just_surname.push_back(el.substr(place_of_space+1,el.length()- place_of_space+1));
            
        }else{
            // no spaces, just add to list
//             cout<<el<<"nie ma spacji"<<endl;
            vector_just_surname.push_back(el);
        }
        
        //cout<<el<<endl;
    }
    
    bool zamien{};    
    string first_l {};
    string second_l{};

    // przed sortowaniem
    for (auto el: vector_just_surname){
        cout<<el<<endl;
    }
    cout<<"------------------------"<<endl;
    

    
    for (int i = 0;i<vector_just_surname.size();++i){
        for (int a = i+1;a<vector_just_surname.size();++a){
            first_l =  vector_just_surname[i].substr(0,1);
            //char as[2];
            //strcpy(as,first_l.c_str());
            
            second_l = vector_just_surname[a].substr(0,1);
            //char as_next[2];
            //strcpy(as,vector_just_surname[i+1].substr(0,1).c_str());    

           zamien = first_l > second_l;
           if (zamien){
               cout<<"zamienie: "<<vector_just_surname[i]<<" z "<< vector_just_surname[a]<<endl; 
               vector_just_surname[i].swap(vector_just_surname[a]);
           }
           
        }
    }
    
    //po sortowaniu
    for (auto el: vector_just_surname){
        cout<<el<<endl;
    }

    
//----------------------------------------------------------
//    string unformatted_string_name {"StephenHawking"};
//    int secondCapital{};
//    for (int i =1;i<unformatted_string_name.length();++i){
//        if (isupper(unformatted_string_name[i])){
//            secondCapital = i;
//        } 
//    }
//
//    string firstname{unformatted_string_name.substr(0,secondCapital)};
//    cout<<"First name is: "<<firstname<<endl;
//    string lastname{unformatted_string_name.substr(secondCapital,unformatted_string_name.length())};
//    cout<<"Last name is: "<<lastname<<endl;
//    string fullname{firstname+" "+lastname};
//    cout<<"whole name is: "<<fullname<<endl;
    
    return 0;
}