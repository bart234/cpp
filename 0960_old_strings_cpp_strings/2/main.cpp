#include <iostream>
#include <string>
using namespace std;

int main (){
    /*
     * require std namespace i include stream
     * dynamic size
     * usefull operators < > >= != itp
     * easy convert to c-style string    
     * */
     
     string s1; //no garbage, always initialize
     string s11{"brtk"};
     string s2{s11};
     string s3{"bartek",3}; // "bar"
     string s5{"bartek",3,4};// "rtek"
     string s6(3,'ab'); //"ababab"
     
     s1 = "Rocks";
     //concat
     
     string whole;
     whole = s3 + " " + s11 + " cos";
//     
//     cout<<whole[1]<<endl;
//     cout<<whole.at(12)<<endl;
    for (auto el:whole){
        cout<<el<<endl;
    }
    //coparing  - value on ascii table value
    //sprawdzic cpp strings lib
    //string.substr(start_index,length)
    //string.find(search_string) - return: pos or string::npos
    //string.lenght() 
    
    //cnormlany cin czyta tylko do pierwszego bialego znaku, by czytac cala linie potrzebna jest ponizsza funkcja
    //getline(cin, s1) - (<input stream>, <variable where store line >)
//    string s1a;
//    getline(cin,s1a);
//    cout<<s1a;
    
    // getlinr(cin,s1,'xxx') ????????????
    //cout<<s1<< 'cos tam xxx' ??????????????
//    cout<<endl;
//    string app{"apple"};
//    for (int i = 0;i<app.length();++i){
//        cout<<app[i]<<endl;
//    }
//    cout<<"---------------"<<endl;
//    string abba {"This is a substring test"};
//    cout<<abba.substr(5,5)<<endl;

    ////---------wyszukiwanie -----------
    string a1{"secred word is boo"};
    string word;
    cout<<"give me secred word:"<<endl;
    cin>>word;
    size_t result = a1.find(word);
    if (result != string::npos){
        cout<<"We found it !! it was: "<<word<<endl;
        cout<<"On position: "<< result<<endl;
    }else{
        cout<<"Sorry "<< word<<" wasnt a magic word"<<endl;
    }

    return 0;
}