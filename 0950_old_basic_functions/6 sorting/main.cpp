#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

//function prototype 
bool function_is_space(char element1);
string just_surname();
void just_print_vector(vector<string>viki);
vector<string> sortowanie_viki (vector<string>viki);

bool has_space(string element1){
    for (char letter: element1){
        if (isspace(letter)>0){
            cout<<element1<<" ma spacje"<<endl;
            return true;            
        }
    }
    return false;
}

vector<string> sortowanie_viki (vector<string>viki){
    
    bool zamien{};    
    string first_l {};
    string second_l{};
    
    for (int i = 0;i<viki.size();++i){
        for (int a = i+1;a<viki.size();++a){
            first_l =  viki[i].substr(0,1);            
            second_l = viki[a].substr(0,1);

           zamien = first_l > second_l;
           if (zamien){
               cout<<"zamienie: "<<viki[i]<<" z "<< viki[a]<<endl; 
               viki[i].swap(viki[a]);
           }
           
        }
    }
    return viki;
    
}

void just_print_vector(vector<string> viki){
    for (auto v: viki){
        cout<<v<<endl;
    }
    cout<<"------------------------"<<endl;
}

string just_surname(bool is_space, string whole_word){
    if (is_space == true) {
            //separate by spaces and take last one
            int place_of_space{};
            for (int i = 0;i<whole_word.length();++i){
                if (isspace(whole_word[i])>0){
                    place_of_space = i;
//                    cout<<i<<endl;
                    }
                is_space = false;            
                }
//            cout<<"Moje nazwisko to:"<< el.substr(place_of_space+1,el.length()- place_of_space+1)<<endl;
            return whole_word.substr(place_of_space+1,whole_word.length()- place_of_space+1);
            
        }else{
            // no spaces, just add to list
//             cout<<el<<"nie ma spacji"<<endl;
            return whole_word;
        }
        
    }
    
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
    bool is_space {};
    
    
    for(auto el: arr){
        
        // if has a space
        
        is_space = false;
        // ----------- f1 short -------------
        is_space = has_space(el);
        
        
        // ------------ f1 long orginal 
        //        for (char letter: el){
        //            if (isspace(letter)>0){
        //                is_space = true;
        //                cout<<el<<" ma spacje"<<endl;
        //            }
        //        }
        // ------------ f1 end orginal
            
        //------------ f2 short ---
        vector_just_surname.push_back(just_surname(is_space,el));
        
        //----------- f2 long orginal
        //        if (is_space == true) {
        //            //separate by spaces and take last one
        //            int place_of_space{};
        //            for (int i = 0;i<el.length();++i){
        //                if (isspace(el[i])>0){
        //                    place_of_space = i;
        ////                    cout<<i<<endl;
        //                    }
        //                is_space = false;            
        //                }
        ////            cout<<"Moje nazwisko to:"<< el.substr(place_of_space+1,el.length()- place_of_space+1)<<endl;
        //            vector_just_surname.push_back(el.substr(place_of_space+1,el.length()- place_of_space+1));
        //            
        //        }else{
        //            // no spaces, just add to list
        ////             cout<<el<<"nie ma spacji"<<endl;
        //            vector_just_surname.push_back(el);
        //        }
        //------------end  f2---------------
        
        //cout<<el<<endl;
    }
    


    // przed sortowaniem
    
    // ----------f3 short
    just_print_vector(vector_just_surname);
    
    //----------- f3 ogrinal
    //    for (auto el: vector_just_surname){
    //        cout<<el<<endl;
    //    }
    //    cout<<"------------------------"<<endl;
    // ---------- f3 orginal end


    //sortowanie
    
    // --------- f4 short
    vector_just_surname = sortowanie_viki(vector_just_surname);
    
    // ---------- f4 long orginal
    
    //    bool zamien{};    
    //    string first_l {};
    //    string second_l{};
        
    //    for (int i = 0;i<vector_just_surname.size();++i){
    //
    //        for (int a = i+1;a<vector_just_surname.size();++a){
    //            first_l =  vector_just_surname[i].substr(0,1);
    //            //char as[2];
    //            //strcpy(as,first_l.c_str());
    //            
    //            second_l = vector_just_surname[a].substr(0,1);
    //            //char as_next[2];
    //            //strcpy(as,vector_just_surname[i+1].substr(0,1).c_str());    
    //
    //           zamien = first_l > second_l;
    //           if (zamien){
    //               cout<<"zamienie: "<<vector_just_surname[i]<<" z "<< vector_just_surname[a]<<endl; 
    //               vector_just_surname[i].swap(vector_just_surname[a]);
    //           }
    //           
    //        }
    //    }    
    // ----------- end f4 logn orginal
    
    
    //po sortowaniu
    
    // ----------f3 short
    just_print_vector(vector_just_surname);
    
    
    // ----------
    //    for (auto el: vector_just_surname){
    //        cout<<el<<endl;
    //    }
    //------
    
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