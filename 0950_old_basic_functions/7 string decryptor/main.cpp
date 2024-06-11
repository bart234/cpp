#include <iostream>
#include <string>

using namespace std;

int main (){
    string corr {"abcdefghijklmnoprstuwzABCDEFGHIJKLMNOPERSUWZ"};
    string decryp {"ZORDWFGHMJKUINBPECSLEArbcunzwhioklmejpastdgf"};
    
    cout<<"Give me some string to crypt it"<<endl;
    string string_in{};
    getline(cin,string_in);
    cout<<"I have: " <<string_in<<endl;
    
    string string_out{};
    for (auto lett: string_in){
        if (corr.find(lett) != string::npos){
            string_out += decryp[corr.find(lett)];
            //bedzie szyfrowany
        }else{
            //cout<<"Nie  szyfruje: "<<lett<<endl; 
            string_out +=  lett;
        }
    }
    cout<<"Zaszyfrowany tekst: "<< string_out<<endl;
    
    //----------------------------------------------------
    string string_recypt{};
    for (auto lett: string_out){
        if (decryp.find(lett) != string::npos){
            string_recypt += corr[decryp.find(lett)];
            //bedzie szyfrowany
        }else{
            //cout<<"Nie  szyfruje: "<<lett<<endl; 
            string_recypt +=  lett;
        }
    }
    cout<<"string recytp: "<< string_recypt <<endl;
    return 0;
}